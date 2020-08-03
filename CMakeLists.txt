cmake_minimum_required(VERSION 3.1...3.18)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
  cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

project(OniTagEditor  VERSION 2.0
                      DESCRIPTION "A tag editor for Mp3, Flac and M4A"
                      LANGUAGES CXX C)

set_property(GLOBAL PROPERTY CXX_STANDARD 14)

if (MSVC)
    # warning level 4 and all warnings as errors
    add_compile_options(/W4 /WX)
else()
    # lots of warnings and all warnings as errors
    add_compile_options(-Wall -Wextra -pedantic -Werror)
endif()

add_subdirectory(src)
add_subdirectory(app)

file(COPY "${CMAKE_SOURCE_DIR}/resources/" DESTINATION "${CMAKE_BINARY_DIR}/resources")

