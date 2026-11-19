#include <iostream>
#include "layers.hpp"

template <typename T>
T massimo(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    std::cout << massimo(3, 7) << "\n";             // T = int
    std::cout << massimo(2.5, 1.5) << "\n";         // T = double
    std::cout << massimo<double>(3, 2.5) << "\n";   // T scelto da noi
    // std::cout << massimo(SigmoidLayer(), SigmoidLayer()); // Giustamente non lo sa fare
    return 0;
}