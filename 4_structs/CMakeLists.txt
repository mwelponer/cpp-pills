cmake_minimum_required(VERSION 3.0.0)

project(structs VERSION 0.1.0)

add_executable(structs structs.cpp)
#target_sources(structs PRIVATE entity.cpp)
target_include_directories(structs PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

