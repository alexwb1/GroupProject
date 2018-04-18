cmake_minimum_required(VERSION 3.10)
project(GroupProject)

set(CMAKE_CXX_STANDARD 11)

add_executable(GameTest test/game-test.cpp)
add_executable(GroupProject src/main.cpp)