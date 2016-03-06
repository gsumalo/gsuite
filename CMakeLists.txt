cmake_minimum_required(VERSION 3.3.2)
project(gsuite)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Boost 1.54.0 REQUIRED COMPONENTS filesystem system)

include_directories(${Boost_INCLUDE_DIRS})

set(KERNELS_SRC
	"kernels/io/naive_std.cpp"
)

set(GSUITE_BIN "gsuite-${CMAKE_SYSTEM_NAME}-${CMAKE_CXX_COMPILER_ID}-${CMAKE_CXX_COMPILER_VERSION}")
add_executable("${GSUITE_BIN}" gsuite.cpp ${KERNELS_SRC})
target_link_libraries("${GSUITE_BIN}" ${Boost_LIBRARIES})
