cmake_minimum_required(VERSION 3.15)
project(BasicNeuralPlusPlus)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

find_package(Eigen3 QUIET)
find_package(OpenCV REQUIRED)
message(STATUS "OpenCV ${OpenCV_VERSION} trovata")

add_executable(basic_neural main.cpp)
add_executable(task7 es_7.cpp)

# Trovare Eigen non basta: bisogna dire al bersaglio dove sono i suoi header.
if(Eigen3_FOUND)
    target_link_libraries(basic_neural Eigen3::Eigen)
else()
    message(STATUS "Eigen non trovata: uso libs/eigen")
    target_include_directories(basic_neural PRIVATE libs/eigen)
endif()
target_link_libraries(basic_neural ${OpenCV_LIBS})

# Laboratorio 02: un eseguibile per ciascun task (non usano Eigen ne' OpenCV).
add_executable(task2 task2_tipi.cpp)
add_executable(task3 task3_discesa.cpp)
add_executable(task4 task4_backprop.cpp)
add_executable(task5 task5_addestramento.cpp)
