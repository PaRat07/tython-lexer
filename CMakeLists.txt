cmake_minimum_required(VERSION 3.29)
project(interprit)

set(CMAKE_CXX_STANDARD 26)

add_executable(interprit main.cpp
        Bor.cpp
        Bor.h
        lexemes
        lexemes/operator.h
        lexemes/comment.h
        lexer.cpp
        lexer.h
        lexemes/float_num.h
        lexemes/int_num.h
        lexemes/other.h
)
