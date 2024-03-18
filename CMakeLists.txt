cmake_minimum_required(VERSION 3.10)
project(SimuladorBanco)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON) # For clangd
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../)
set(SOURCES main.cpp Banco.cpp Banco.hpp)

add_executable(SimuladorBanco ${SOURCES}) # All the .cpp files
target_include_directories(SimuladorBanco PRIVATE lib/Cola.hpp lib/ListaSimple.hpp lib/nocurses.h)
