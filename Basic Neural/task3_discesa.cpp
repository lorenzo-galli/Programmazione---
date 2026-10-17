#include <iostream>

// Soluzione del Laboratorio 02, Task 3: discesa del gradiente su E(x) = x^2 (quesito 1, Lezione 03).

int main() {
    std::cout << "[Task 3] E(x) = x^2, x0 = 1" << std::endl;
    for (int k = 1; k <= 5; ++k) {
        double eta = 0.25 * k;              // int * double: k diventa double
        double x = 1.0;
        std::cout << "eta = " << eta << ":";
        for (int n = 1; n <= 5; ++n) {
            x = x - eta * 2.0 * x;          // E'(x) = 2x
            std::cout << "  " << x;
        }
        std::cout << std::endl;
    }
    return 0;
}
