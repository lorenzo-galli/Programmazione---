cmake_minimum_required(VERSION 3.15)
project(Lezione10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
# AddressSanitizer (Lezione 08)
add_compile_options(-fsanitize=address -g)
add_link_options(-fsanitize=address)
# qui una riga add_executable per esempio


add_executable(copia_superficiale copia_superficiale.cpp)
add_executable(puntatore_this puntatore_this.cpp)
add_executable(discesa discesa.cpp Vettore2D.cpp)
