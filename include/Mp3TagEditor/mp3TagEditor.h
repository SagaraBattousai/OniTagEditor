#ifndef __MP3_TAG_EDITOR_H__
#define __MP3_TAG_EDITOR_H__

#ifdef MP3_TAG_EDITOR_EXPORTS
#define MP3_TAG_API __declspec(dllexport)
#else
#define MP3_TAG_API __declspec(dllimport)
#endif

#include <string>

//extern "C" 
MP3_TAG_API std::string test();




#endif