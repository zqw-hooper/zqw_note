cmake_minimum_required(VERSION 2.8.3)
project(common_can_encode_decode)

add_compile_options(-std=c++11 -Wall -Wextra -Werror)

find_package(catkin REQUIRED COMPONENTS roscpp)

catkin_package(
        INCLUDE_DIRS include
        LIBRARIES common_can_encode_decode
        CATKIN_DEPENDS roscpp)

include_directories(
        include
        ${catkin_INCLUDE_DIRS})

add_library(common_can_encode_decode
        STATIC
        src/can_encode_decode.cpp)