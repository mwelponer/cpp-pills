cmake_minimum_required(VERSION 3.0.0)

project(threads VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

add_executable(threads threads.cpp)
#target_sources(neetcode PRIVATE Utils.cpp)
#target_include_directories(neetcode PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

