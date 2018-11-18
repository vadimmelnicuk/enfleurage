cmake_minimum_required(VERSION 3.12)
project(hazel)

set(CMAKE_CXX_STANDARD 17)

add_library(hazel STATIC src/Application.cpp src/Application.h src/Hazel.h src/EntryPoint.h)