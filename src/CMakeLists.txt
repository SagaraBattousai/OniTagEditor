
add_library(Mp3TagEditor SHARED Mp3TagEditor.cpp Mp3TagEditor.h)
target_compile_definitions(Mp3TagEditor PRIVATE EXPORT_DLL)
target_include_directories(Mp3TagEditor PUBLIC ../include/OniTagEditor/)