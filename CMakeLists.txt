cmake_minimum_required(VERSION 3.17)
project(Matrix)

set(CMAKE_CXX_STANDARD 20)

add_executable(Matrix main.cpp LinAlg/Matrix.cpp LinAlg/Matrix.h LinAlg/Row.cpp LinAlg/Row.h)
target_include_directories(Matrix PRIVATE LinAlg)
