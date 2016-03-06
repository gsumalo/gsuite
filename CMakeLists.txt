cmake_minimum_required(VERSION 3.3.2)
project(gsuite)

add_executable("gsuite-${CMAKE_SYSTEM_NAME}-${CMAKE_CXX_COMPILER_ID}-${CMAKE_CXX_COMPILER_VERSION}" gsuite.cpp)
