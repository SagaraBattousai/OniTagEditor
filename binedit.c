#include <stdio.h>
#include "binedit.h"

int main()
{
  FILE *ptr;

  ptr = fopen("Legend of Zelda Majora's Mask OST [Disk 1] - Koji Kondo and Toru Minegeshi - Catch Small Item.mp3", "rb");

  tagHeader *id = getTagHeader(ptr);

  printf("tag: %s\n", id->buf);
  printf("majVer: %x\n", id->ver);
  printf("minVer: %x\n", id->min);
    
  printf("A flag: %u\n", getAFlag(id));
  printf("B flag: %u\n", getBFlag(id));
  printf("C flag: %u\n", getCFlag(id));
  
  printf("correct Size: %u\n", getTagSize(id));

  unsigned frameBytes = getTagSize(id);

  while(frameBytes > 0)
  {
    frame *f = getFrame(ptr);


    unsigned frameSize = getFrameSize(f->header);

    unsigned char empty[4];
    memset(empty, 0, 4);

    if(!memcmp(f->header->frameID, empty, 1))
    {
      frameBytes -= (frameSize + 10);
      continue;
    }

    printf("frameID %s\n", f->header->frameID);
    printf("frameID Hex %x\n", frameSize);
    printf("frameID %u\n", getFrameSize(f->header));


    textBodyFrame *body = (textBodyFrame *) f->frameBody;

    printf("enc %c\n", body->textEncoding);
  
    printf("name %s\n", body->info);

    frameBytes -= (frameSize + 10);
    printf("frameBytesRemaining %u\n", frameBytes);

  }

  fclose(ptr);
  return 0;
}

//tag* getTag(FILE *file);

tagHeader *getTagHeader(FILE *file)
{  
  tagHeader *id = (tagHeader *) malloc(sizeof(tagHeader));

  fread(id, 10, 1, file);

  return id;
}




unsigned char getAFlag(tagHeader *header)
{  
  return header->flags & 0x80;
}
unsigned char getBFlag(tagHeader *header)
{
  return header->flags & 0x40;
}

unsigned char getCFlag(tagHeader *header)
{
  return header->flags & 0x20;
}

unsigned getTagSize(tagHeader *header)
{
  return header->remainingTagSize[0] << 21 | 
         header->remainingTagSize[1] << 14 | 
         header->remainingTagSize[2] << 7 | 
         header->remainingTagSize[3];
}

frame* getFrame(FILE *file)
{

  frameHeader *header = getFrameHeader(file);


  textBodyFrame* body = getTextBodyFrame(file, getFrameSize(header));

  frame *f = (frame *) malloc(sizeof(frame));

  f->header = header;
  f->frameBody = (void *) (body);

  return f;


}

frameHeader* getFrameHeader(FILE *file)
{
  frameHeader *header = (frameHeader *) malloc(sizeof(frameHeader));

  fread(header, 10, 1, file);

  return header;

}

unsigned getFrameSize(frameHeader *header)
{

  return (header->remainingFrameSize[0] << 24) |
         (header->remainingFrameSize[1] << 16) |
         (header->remainingFrameSize[2] << 8) |
          header->remainingFrameSize[3];
}

textBodyFrame* getTextBodyFrame(FILE *file, unsigned size)
{
  unsigned char enc;
  unsigned char *name = (unsigned char *) malloc(sizeof(unsigned char) * size);

  
  fread(&enc, 1, 1, file);
  
  fgets(name, size, file);

  textBodyFrame *body = (textBodyFrame *) malloc(sizeof(textBodyFrame)); ;
  body->textEncoding = enc;
  body->info = name;

  return body;

}
