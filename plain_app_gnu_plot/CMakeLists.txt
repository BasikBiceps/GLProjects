cmake_minimum_required(VERSION 3.15)
project(plain_app_gnu_plot)

set(CMAKE_CXX_STANDARD 17)

include_directories("3-rd-party/include")

add_executable(plain_app_gnu_plot main.cpp)

target_link_libraries(plain_app_gnu_plot boost_iostreams boost_system boost_filesystem)