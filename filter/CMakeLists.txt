cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(direct_filter)

find_package(PCL 1.8 REQUIRED)

include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

add_executable (direct_filter direct_filter.cpp)
target_link_libraries (direct_filter ${PCL_LIBRARIES})
