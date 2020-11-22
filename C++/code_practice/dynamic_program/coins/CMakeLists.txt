cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(coins)

add_compile_options(
  -std=c++11
  -Werror)

set(SRC_LIST coins.cpp)
add_executable(output ${SRC_LIST})
