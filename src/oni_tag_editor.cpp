
#include "oni_tag_editor.h"

#define noPadding(header) memcmp(header, EMPTY, 4)
#define id_to_key(id) id[0] << 24 | id[1] << 16 | id[2] << 8 | id[3]

const size_t HEADER_SIZE = 10;

static const unsigned char EMPTY[4] = {0, 0, 0, 0};

static textBodyFrame* getTextBodyFrame(FILE *file, unsigned size);

static int getHeader(FILE *file, void *header)
{
  fread(header, HEADER_SIZE, 1, file);

  return (noPadding(header));
}
  
static int getFrame(FILE *file, frame *f)
{
  f->frameLocation = ftell(file);
  
  //may not need to put on heap
  frameHeader *header = (frameHeader *) malloc(sizeof(frameHeader));
  
  int padding = !getHeader(file, header);

  if(padding)
  {
    free(header);
    return 0;
  }

  //need to edit
  textBodyFrame* body = getTextBodyFrame(file, getFrameSize(header));

  f->header = header;
  
  f->frameBody = (void *) (body);

  printf("info is %s\n", header->frameID);
 
  return 1;
}
//TEMP

static textBodyFrame* getTextBodyFrame(FILE *file, unsigned size)
{
  unsigned char enc;
  char *name = (char *) malloc(sizeof(char) * size);

  fread(&enc, 1, 1, file);

  fgets(name, size, file);

  textBodyFrame *body = (textBodyFrame *) malloc(sizeof(textBodyFrame));
  body->textEncoding = enc;
  body->info = name;


  return body;

}

mp3Info* new_mp3Info(const char *filename)
{
  mp3Info *info = (mp3Info *) malloc(sizeof(mp3Info));

  FILE *file = fopen(filename, "rb");

  tagHeader *header = (tagHeader*) malloc(sizeof(tagHeader));
  
  //check for id3v1
  getHeader(file, header);


  unsigned tagRemaining = getTagSize(header);

  hashmap_t *frames = new_hashmap();

  long padding_location = 0;

  unsigned padding_length = 0;

  while(tagRemaining)
  {
    frame *f = (frame *) malloc(sizeof(frame));
    
    if(!getFrame(file, f))
    {
      padding_location = ftell(file);

      padding_length = tagRemaining; //I think

      break;

    }

    
    size_t key = id_to_key(f->header->frameID);

    add_to_hashmap(frames, (void *)key, (void *)f);

    tagRemaining -= (10 + getFrameSize(f->header));

  }

  mp3Tag *tag = (mp3Tag *) malloc(sizeof(tag));

  tag->header = header;

  tag->frames = frames;

  tag->padding_location = padding_location;

  tag->padding_length = padding_length;


  info->filename = filename;
    
  info->amountRead = ftell(file); //???

  info->fileLength = ftell(file); //???

  info->tag = tag;


  return info;
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


unsigned getFrameSize(frameHeader *header)
{

  return (header->remainingFrameSize[0] << 24) |
         (header->remainingFrameSize[1] << 16) |
         (header->remainingFrameSize[2] << 8) |
          header->remainingFrameSize[3];
}


tagHeader* getTagHeader(const char *filename)
{
  FILE *file = fopen(filename, "rb");

  tagHeader *header = (tagHeader *) malloc(sizeof(tagHeader));

  fread(header, HEADER_SIZE, 1, file);

  fclose(file);

  return header;
}

/*
 *
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
*/
