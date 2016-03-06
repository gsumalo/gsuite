cmake_minimum_required(VERSION 3.3.2)
project(gsuite)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(KERNELS_SRC
	"kernels/io/naive_std.cpp"
)

add_executable("gsuite-${CMAKE_SYSTEM_NAME}-${CMAKE_CXX_COMPILER_ID}-${CMAKE_CXX_COMPILER_VERSION}" gsuite.cpp ${KERNELS_SRC})
