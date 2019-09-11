cmake_minimum_required(VERSION 3.12)
set(CMAKE_CXX_STANDARD 14)
project(boosttest)

link_directories(/usr/local/Cellar/boost/1.67.0_1/lib)
include_directories(/usr/local/Cellar/boost/1.67.0_1/include)

add_subdirectory(timer)
add_subdirectory(asio)
add_subdirectory(variant)