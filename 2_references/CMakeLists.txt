cmake_minimum_required(VERSION 3.0.0)

project(references VERSION 0.1.0)

add_executable(references references.cpp)
target_sources(references PRIVATE entity.cpp)
target_include_directories(references PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

