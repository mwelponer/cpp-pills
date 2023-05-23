cmake_minimum_required(VERSION 3.0.0)

project(classes VERSION 0.1.0)

add_executable(classes classes.cpp)
target_sources(classes PRIVATE Something.cpp)
target_include_directories(classes PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

