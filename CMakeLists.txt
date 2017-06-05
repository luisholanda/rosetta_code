cmake_minimum_required(VERSION 3.8)
project(Rosetta_Code)

set(CMAKE_CXX_STANDARD 14)

file(GLOB_RECURSE srcs ${CMAKE_SOURCE_DIR}/src/*.cpp)

set(SOURCE_FILES main.cpp ${srcs})
add_executable(Rosetta_Code ${SOURCE_FILES})