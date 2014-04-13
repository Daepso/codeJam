project(cookieCliker)
cmake_minimum_required(VERSION 2.8)

add_definitions( "-g -O0")
include_directories(src/)

set(SOURCES
  CookieClicker.cpp
  Parser.cpp)

add_executable(${PROJECT_NAME} main.cpp ${SOURCES})
