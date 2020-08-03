
set(SRC_FILES mp3TagEditor.cpp)

file(GLOB HEADER_FILES "${CMAKE_SOURCE_DIR}/include/Mp3TagEditor/*.h")
#set("../resources/Legend of Zelda Majora's Mask OST [Disk 1] - Koji Kondo and Toru Minegeshi - Catch Small Item.mp3")

add_library(Mp3TagEditor SHARED ${SRC_FILES} ${HEADER_FILES})

target_compile_definitions(Mp3TagEditor PRIVATE MP3_TAG_EDITOR_EXPORTS)

target_include_directories(Mp3TagEditor PUBLIC "${CMAKE_SOURCE_DIR}/include/")
