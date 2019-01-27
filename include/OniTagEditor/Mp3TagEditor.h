#pragma once

#ifdef EXPORT_DLL
#define MP3_TAG_EDITOR_API __declspec(dllexport)
#else
#define MP3_TAG_EDITOR_API __declspec(dllimport)
#endif

//extern MP3_TAG_EDITOR_API 
//extern const size_t HEADER_SIZE;

typedef struct hashmap_t hashmap_t;

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
  char *info;
}textBodyFrame;

typedef struct{
  frameHeader *header;
  void *frameBody;
  long frameLocation;
}frame;

typedef struct{
  tagHeader *header;
  hashmap_t *frames;//frame *frames;
  long padding_location;
  unsigned padding_length;
}mp3Tag;

typedef struct{
  const char *filename;
  long amountRead;
  long fileLength;
  mp3Tag *tag;
}mp3Info;

mp3Info* new_mp3Info(const char *filename);

tagHeader* getTagHeader(const char *file);

/* PI frame* getFrame(FILE *file); *1/ */

/* PI frameHeader* getFrameHeader(FILE *file); *1/ */

/* PI textBodyFrame* getTextBodyFrame(FILE *file, unsigned size); *1/ */

int getHeader(FILE *file, void *header);

int getFrame(const unsigned char *id, frame *f);

unsigned char getAFlag(tagHeader *header);

unsigned char getBFlag(tagHeader *header);

unsigned char getCFlag(tagHeader *header);

unsigned getTagSize(tagHeader *header);

unsigned getFrameSize(frameHeader *header);
