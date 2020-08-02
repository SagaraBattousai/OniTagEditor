#pragma once

#ifdef EXPORT_DLL
#define MP3_TAG_EDITOR_API __declspec(dllexport)
#else
#define MP3_TAG_EDITOR_API __declspec(dllimport)
#endif

//extern MP3_TAG_EDITOR_API 
//extern const size_t HEADER_SIZE;


MP3_TAG_EDITOR_API mp3Info* new_mp3Info(const char *filename);

MP3_TAG_EDITOR_API tagHeader* getTagHeader(const char *file);

/* PI frame* getFrame(FILE *file); *1/ */

/* PI frameHeader* getFrameHeader(FILE *file); *1/ */

/* PI textBodyFrame* getTextBodyFrame(FILE *file, unsigned size); *1/ */

MP3_TAG_EDITOR_API int getHeader(FILE *file, void *header);

MP3_TAG_EDITOR_API int getFrame(const unsigned char *id, frame *f);

MP3_TAG_EDITOR_API unsigned char getAFlag(tagHeader *header);

MP3_TAG_EDITOR_API unsigned char getBFlag(tagHeader *header);

MP3_TAG_EDITOR_API unsigned char getCFlag(tagHeader *header);

MP3_TAG_EDITOR_API unsigned getTagSize(tagHeader *header);

MP3_TAG_EDITOR_API unsigned getFrameSize(frameHeader *header);
