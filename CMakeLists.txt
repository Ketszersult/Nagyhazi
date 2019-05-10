cmake_minimum_required(VERSION 3.7.2)
project(nagyhazi)

set(CMAKE_CXX_STANDARD 14)

add_executable(nagyhazi main.cpp Screen.cpp Screen.h Shape.cpp Shape.h Rect.cpp Rect.h Circle.cpp Circle.h)