cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(three_sum)

add_compile_options(
  -std=c++11
  -Werror)

set(SRC_LIST three_sum.cpp)
add_executable(output ${SRC_LIST})