cmake_minimum_required(VERSION 3.12)
set(CMAKE_CXX_STANDARD 14)
project(poco)

link_directories(/usr/local/Cellar/poco/1.9.0_1/lib)
include_directories(/usr/local/Cellar/poco/1.9.0_1/include)

add_subdirectory(hellopoco)
add_subdirectory(all)