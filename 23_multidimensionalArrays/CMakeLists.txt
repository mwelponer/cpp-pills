cmake_minimum_required(VERSION 3.0.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

project(thecherno VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(thecherno multidimensionalArrays.cpp)
#target_sources(neetcode PRIVATE Utils.cpp)
#target_include_directories(neetcode PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

