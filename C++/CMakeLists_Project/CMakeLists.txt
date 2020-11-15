cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(reverse_linked_list)
add_compile_options(
  -std=c++11
  -Werror)

set(SRC_LIST reverse_linked_list.cpp)
add_executable(output ${SRC_LIST})