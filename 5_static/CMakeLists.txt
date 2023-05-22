cmake_minimum_required(VERSION 3.0.0)

project(static VERSION 0.1.0)

add_executable(static main.cpp)
target_sources(static PRIVATE static.cpp)
#target_include_directories(static PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

