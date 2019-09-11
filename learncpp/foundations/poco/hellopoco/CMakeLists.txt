cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 14)
project(poco_hello)
file(GLOB SRC *.h *.hpp *.cpp *.cc *.c )
add_executable(${PROJECT_NAME} ${SRC})

target_link_libraries(${PROJECT_NAME} libPocoFoundation.60.dylib)