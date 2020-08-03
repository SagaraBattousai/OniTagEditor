
add_executable(app main.cpp)

target_link_libraries(app PUBLIC Mp3TagEditor)

target_include_directories(app PUBLIC "${CMAKE_SOURCE_DIR}/include/")

file(GENERATE OUTPUT copy_mp3_editor_dll
     CONTENT "file(COPY ${CMAKE_CURRENT_BINARY_DIR}/../src/Mp3TagEditor.dll DESTINATION ${CMAKE_CURRENT_BINARY_DIR})"
     )

add_custom_command(TARGET app
                   POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -P copy_mp3_editor_dll
                   BYPRODUCTS Mp3TagEditor.dll
                   COMMENT "Copying over Mp3TagEditor.dll to executable directory"
                   VERBATIM
                   )
