cmake_minimum_required(VERSION 3.10)
project(Research_Practice)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fopenmp")

find_package(BLAS REQUIRED)

add_executable(Research_Practice main.cpp)

target_compile_options(Research_Practice PRIVATE -O3 -mavx -mfma -funroll-loops -march=native -fopenmp)

target_link_libraries(Research_Practice PRIVATE ${BLAS_LIBRARIES})