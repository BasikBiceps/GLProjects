cmake_minimum_required(VERSION 3.15)
project(calculator_cxx)

include_directories("includes/")

set(CMAKE_CXX_STANDARD 17)
file(GLOB_RECURSE HEADERS "includes/*.h" "includes/*.hpp")
file(GLOB_RECURSE SOURCES "sources/*.cpp")

add_executable(calculator_cxx ${SOURCES} ${HEADERS})