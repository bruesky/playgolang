cmake_minimum_required(VERSION 3.15)
project(pp_openmp)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_C_COMPILER /usr/local/Cellar/gcc/9.2.0_3/bin/gcc-9)
set(CMAKE_CXX_COMPILER /usr/local/Cellar/gcc/9.2.0_3/bin/g++-9)
#set(CMAKE_C_COMPILER /usr/bin/clang)
#set(CMAKE_CXX_COMPILER /usr/bin/clang++)
set(CMAKE_CXX_FLAGS "-fopenmp")

add_subdirectory(hello)
add_subdirectory(log-of-arr)
add_subdirectory(merging_sorted_lists)


