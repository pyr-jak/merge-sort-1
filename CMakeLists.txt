cmake_minimum_required(VERSION 4.1)
project(merge_sort)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(merge_sort
        MergeSort.cpp main.cpp
        )
