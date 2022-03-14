cmake_minimum_required(VERSION 3.21)
project(Labo_1)

set(CMAKE_CXX_STANDARD 11)

add_executable(Labo_1 main.cpp Matrix.cpp Matrix.h operations/Operation.h
        operations/AdditionOperation.h operations/SubstrationOperation.h
        operations/MultiplicationOperation.h)
