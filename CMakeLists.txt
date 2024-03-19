cmake_minimum_required(VERSION 3.26)
project(chess C)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES
        main.c
        BoardGame/BoardGame.c
        ChessGame/ChessAI.c
        ChessGame/ChessGame.c
        ChessGame/ChessGameBoard.c
        ChessGame/ChessGameViewOutput.c
        DataStructs/ArrayList.c
        IO/BasicErrorsHandling.c
        IO/FileIO.c
        IO/Parser.c
)

add_executable(chess ${SOURCE_FILES})

SET(GCC_COVERAGE_COMPILE_FLAGS "-c -fmessage-length=0 -std=c99 -Wall -Wextra -Werror -pedantic-errors")

add_definitions(${GCC_COVERAGE_COMPILE_FLAGS})