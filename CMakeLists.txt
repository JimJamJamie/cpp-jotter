cmake_minimum_required(VERSION 3.14)

if (${clean} EQUAL 1)
    message(STATUS "Cleaning build directories")
    file(REMOVE_RECURSE ${CMAKE_SOURCE_DIR}/build)
    message(STATUS "Cleaning build directories - done")

    message(STATUS "Cleaning output directories")
    file(REMOVE_RECURSE ${CMAKE_SOURCE_DIR}/bin)
    message(STATUS "Cleaning output directories - done")
endif()

project(helloworld LANGUAGES CXX)

file(MAKE_DIRECTORY ${CMAKE_SOURCE_DIR}/build)
file(MAKE_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

set(TARGET_ARCH ${CMAKE_SYSTEM_NAME}-${CMAKE_SYSTEM_PROCESSOR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/${TARGET_ARCH})

# The following generates a compile_commands.json file inside /build.
# Clangd needs this to properly locate header files.
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(${CMAKE_SOURCE_DIR}/src)
