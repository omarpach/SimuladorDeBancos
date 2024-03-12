cmake_minimum_required(VERSION 3.10)
project(Colas)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON) # For clangd
set(CMAKE_CXX_STANDARD 17)

add_executable(Colas main.cpp) # All the .cpp files
