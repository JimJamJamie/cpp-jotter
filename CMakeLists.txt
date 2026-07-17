cmake_minimum_required(VERSION 3.10)

project(helloworld
  VERSION 0.1
  LANGUAGES CXX
)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_BUILD_TYPE "Release")

add_subdirectory(src)
file(MAKE_DIRECTORY build)
