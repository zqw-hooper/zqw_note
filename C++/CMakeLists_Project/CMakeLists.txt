cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(test)
add_compile_options(
  -std=c++11
  -Werror)

  find_package(Threads REQUIRED)
  include_directories(include)

set(SRC_LIST main.cpp)
add_executable(test ${SRC_LIST})

target_link_libraries (test pthread)
