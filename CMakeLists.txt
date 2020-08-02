cmake_minimum_required(VERSION 3.1...3.13)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
  cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

project(OniTagEditor  VERSION 2.0
                      DESCRIPTION "A tag editor for Mp3, Flac and M4A"
                      LANGUAGES CXX)

set(CMAKE_GENERATOR_PLATFORM, "Visual Studio 15 2017 Win64")

add_subdirectory(app)
add_subdirectory(src)

#Is Bad??
#target_compile_features(Mp3TagEditor PUBLIC cxx_std_11)
