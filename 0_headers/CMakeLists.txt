cmake_minimum_required(VERSION 3.0.0)

project(headers VERSION 0.1.0)

add_executable(headers headers.cpp)
target_sources(headers PRIVATE log.cpp)
target_include_directories(headers PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

