#ifndef _BINEDIT_H
#define _BINEDIT_H

typedef struct{
  char id[3];
  char title[30];
  char artist[30];
  char album[30];
  char year[4];
}id3v1;

typedef struct{
  unsigned char buf[3];
  unsigned char ver;
  unsigned char min;
  unsigned char flags;
  unsigned char remainingTagSize[4];
}tagHeader;

typedef struct{
  unsigned char frameID[4];
  unsigned char remainingFrameSize[4];
  unsigned char flags[2];
}frameHeader;

typedef struct{
  unsigned char textEncoding;
  unsigned char *info;
}textBodyFrame;

typedef struct{
  frameHeader *header;
  void *frameBody;
}frame;

typedef struct{
  tagHeader header;
  frame *frames;
}tag;

tag* getTag(FILE *file);

tagHeader* getTagHeader(FILE *file);

frame* getFrame(FILE *file);

frameHeader* getFrameHeader(FILE *file);

textBodyFrame* getTextBodyFrame(FILE *file, unsigned size);

unsigned char getAFlag(tagHeader *header);

unsigned char getBFlag(tagHeader *header);

unsigned char getCFlag(tagHeader *header);

unsigned getTagSize(tagHeader *header);

unsigned getFrameSize(frameHeader *header);

#endif
