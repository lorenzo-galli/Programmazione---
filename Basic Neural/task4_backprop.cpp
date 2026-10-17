#include <iostream>
#include <cmath>

// Soluzione del Laboratorio 02, Task 4: l'esercizio in classe della Lezione 03.

int main() {
    double x = 1.0, y = 1.0;
    double w1 = 1.0, w2 = 1.0;

    // forward
    double z1 = w1 * x;
    double a1 = 1.0 / (1.0 + std::exp(-z1));
    double z2 = w2 * a1;
    double a2 = 1.0 / (1.0 + std::exp(-z2));
    double E  = (a2 - y) * (a2 - y);

    // backward
    double s1 = a1 * (1.0 - a1);            // sigma'(z1) = sigma(1 - sigma)
    double s2 = a2 * (1.0 - a2);            // sigma'(z2)
    double delta2 = 2.0 * (a2 - y) * s2;
    double delta1 = w2 * delta2 * s1;
    double dE_dw2 = delta2 * a1;
    double dE_dw1 = delta1 * x;

    std::cout << "[Task 4]\tstrato 1\tstrato 2" << std::endl;
    std::cout << "z\t\t" << z1 << "\t" << z2 << std::endl;
    std::cout << "a\t\t" << a1 << "\t" << a2 << std::endl;
    std::cout << "sigma'(z)\t" << s1 << "\t" << s2 << std::endl;
    std::cout << "delta\t\t" << delta1 << "\t" << delta2 << std::endl;
    std::cout << "dE/dw\t\t" << dE_dw1 << "\t" << dE_dw2 << std::endl;
    std::cout << "E = " << E << ",  delta1/delta2 = " << delta1 / delta2 << std::endl;

    // gradient check: lo stesso forward, con w1 spostato di +h e di -h.
    // Senza funzioni (Lezione 05) va ricopiato: nel Lab 03 diventera' sigmoid().
    double h = 0.01;
    double a1p = 1.0 / (1.0 + std::exp(-(w1 + h) * x));
    double a2p = 1.0 / (1.0 + std::exp(-w2 * a1p));
    double E_piu = (a2p - y) * (a2p - y);
    double a1m = 1.0 / (1.0 + std::exp(-(w1 - h) * x));
    double a2m = 1.0 / (1.0 + std::exp(-w2 * a1m));
    double E_meno = (a2m - y) * (a2m - y);
    std::cout << "gradient check: (E(w1+h) - E(w1-h)) / 2h = "
              << (E_piu - E_meno) / (2.0 * h)
              << "  (backprop: " << dE_dw1 << ")" << std::endl;
    return 0;
}
