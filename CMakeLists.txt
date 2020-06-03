cmake_minimum_required(VERSION 3.15)
project(Tree)

set(CMAKE_CXX_STANDARD 11)

add_executable(Tree main.cpp Tree.h AvlTree.h RankTree.h)
add_executable(TreeTester TreeTester.cpp Tree.h RankTree.h ThreeParamKey.cpp ThreeParamKey.h)
add_executable(RankTester RankTester.cpp RankTree.h ThreeParamKey.cpp ThreeParamKey.h)