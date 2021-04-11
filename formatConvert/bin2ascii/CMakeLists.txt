cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(bin2ascii)

find_package(PCL 1.8 REQUIRED)

include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

add_executable (bin2ascii bin2ascii.cpp)
target_link_libraries (bin2ascii ${PCL_LIBRARIES})