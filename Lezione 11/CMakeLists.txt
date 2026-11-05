cmake_minimum_required(VERSION 3.15)
project(Lezione11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
# AddressSanitizer (Lezione 08)
add_compile_options(-fsanitize=address -g)
add_link_options(-fsanitize=address)
# qui una riga add_executable per esempio
add_executable(stringhe stringhe.cpp)
add_executable(apri_file apri_file.cpp)
add_executable(leggi_righe leggi_righe.cpp)

add_executable(spezza_riga spezza_riga.cpp)
add_executable(converti converti.cpp)
add_executable(scrivi_file scrivi_file.cpp)
add_executable(precisione precisione.cpp)
add_executable(csv csv.cpp)                  # esercizio
#add_executable(ambiguita ambiguita.cpp)      # ripasso: non compila