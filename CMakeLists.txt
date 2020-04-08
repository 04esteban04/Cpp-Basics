cmake_minimum_required(VERSION 3.15)
project(Cpp-Basics)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -pthread")

add_executable(Cpp-Basics Files/LinkedList.cpp)