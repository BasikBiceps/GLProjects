cmake_minimum_required(VERSION 3.15)
project(TextVerification)

include_directories("headers/")

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE HEADERS "headers/*.h" "headers/*.hpp")
file(GLOB_RECURSE SOURCES "sources/*.cpp")

add_executable(TextVerification main.cpp ${HEADERS} ${SOURCES} sources/StringHelper.cpp headers/StringHelper.h sources/FileSystemHelper.cpp headers/FileSystemHelper.h)

target_link_libraries(TextVerification stdc++fs)
