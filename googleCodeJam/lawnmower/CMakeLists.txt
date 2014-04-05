project(lawnmower)
cmake_minimum_required(VERSION 2.8)

include_directories(src/)

set(SOURCES
  src/Lawn.cpp
  src/Parser.cpp)

add_executable(${PROJECT_NAME} src/main.cpp ${SOURCES})
