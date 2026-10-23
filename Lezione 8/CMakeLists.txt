cmake_minimum_required(VERSION 3.10)
project(Pendolo)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_compile_options(-Wall)

add_executable(pendolo main.cpp Misure.cpp Statistiche.cpp)