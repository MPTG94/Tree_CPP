cmake_minimum_required(VERSION 3.15)
project(Tree)

set(CMAKE_CXX_STANDARD 11)

add_executable(Tree main.cpp Tree.h)
add_executable(TreeTester TreeTester.cpp Tree.h)