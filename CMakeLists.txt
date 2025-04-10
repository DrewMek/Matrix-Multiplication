cmake_minimum_required(VERSION 3.10)
project(Research_Practice)

set(CMAKE_CXX_STANDARD 17)

include_directories(/usr/include)
include_directories(/usr/include/x86_64-linux-gnu)

add_executable(Research_Practice main.cpp)

find_package(BLAS REQUIRED)

target_link_libraries(Research_Practice PRIVATE ${BLAS_LIBRARIES} /usr/lib/x86_64-linux-gnu/libopenblas.so)
