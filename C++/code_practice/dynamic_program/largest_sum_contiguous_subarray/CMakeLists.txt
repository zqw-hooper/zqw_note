cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(largest_sum_contiguous_subarray)

add_compile_options(
  -std=c++11
  -Werror)

set(SRC_LIST main.cpp)
add_executable(output ${SRC_LIST})
