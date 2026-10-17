#include <iostream>

// Soluzione del Laboratorio 02, Task 2: tipi base e divisione intera.

int main() {
    int epochs = 100;
    double learning_rate = 0.01;
    std::cout << "[Task 2] epoche: " << epochs
              << ", learning rate: " << learning_rate << std::endl;

    int a = 5, b = 2;
    std::cout << "5 / 2 = " << a / b << " (divisione intera)" << std::endl;
    std::cout << "con il cast = " << static_cast<double>(a) / b << std::endl;
    return 0;
}
