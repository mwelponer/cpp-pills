cmake_minimum_required(VERSION 3.0.0)
project(thecherno VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

add_subdirectory(_test)

add_subdirectory(0_hello)
add_subdirectory(0_functions)
add_subdirectory(0_headers)
add_subdirectory(0_loops)

add_subdirectory(1_pointers)
add_subdirectory(1_arrays)
add_subdirectory(1_arrayFromFunction)
add_subdirectory(1_arrayToFunction)

add_subdirectory(2_references)

add_subdirectory(3_classes)

add_subdirectory(4_structs)

add_subdirectory(5_static)
add_subdirectory(5_staticInClasses)

add_subdirectory(6_enum)

add_subdirectory(7_interfaces)
add_subdirectory(7_virtualFunctions)

add_subdirectory(8_strings)

add_subdirectory(9_const)
add_subdirectory(10_ternaryOperator)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
