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
