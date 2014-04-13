project(magikTrick)
cmake_minimum_required(VERSION 2.8)

include_directories(src/)

set(SOURCES
  Parser.cpp)

add_executable(${PROJECT_NAME} main.cpp ${SOURCES})
