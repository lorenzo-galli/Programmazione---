#include <iostream>
#include "DynamicArray.hpp"

int main() {
    DynamicArray a(5);
    for (int i = 0; i < 5; i++) {
        a.imposta(i, 0.5 * i);
    }
    for (int i = 0; i < 5; i++) {
        std::cout << a.leggi(i) << " ";
    }
    std::cout << "\n";
    a.imposta(7, 1.0);     // indice non valido
    std::cout << a.leggi(7) << "\n";
    return 0;
}