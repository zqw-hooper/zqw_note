cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(longest_palindromic_substring)

add_compile_options(
  -std=c++11
  -Werror)

set(SRC_LIST main.cpp)
add_executable(output ${SRC_LIST})
