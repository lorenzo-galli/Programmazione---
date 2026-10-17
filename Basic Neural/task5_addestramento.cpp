#include <iostream>
#include <cmath>

// Soluzione del Laboratorio 02, Task 5: addestrare la catena.

int main() {
    double x = 1.0, eta = 1.0;
    for (int caso = 0; caso < 2; ++caso) {
        double y = 1.0;
        if (caso == 1) {
            y = 0.8;
        }
        double w1 = 1.0, w2 = 1.0;
        std::cout << "\n[Task 5] y = " << y << ", eta = " << eta << std::endl;
        for (int t = 0; t <= 200; ++t) {
            double a1 = 1.0 / (1.0 + std::exp(-w1 * x));
            double a2 = 1.0 / (1.0 + std::exp(-w2 * a1));
            double E  = (a2 - y) * (a2 - y);
            double delta2 = 2.0 * (a2 - y) * a2 * (1.0 - a2);
            double delta1 = w2 * delta2 * a1 * (1.0 - a1);
            if (t % 20 == 0) {
                std::cout << "t = " << t << "\tE = " << E
                          << "\tw1 = " << w1 << "\tw2 = " << w2 << std::endl;
            }
            w1 = w1 - eta * delta1 * x;     // dE/dw1 = delta1 * x
            w2 = w2 - eta * delta2 * a1;    // dE/dw2 = delta2 * a1
        }
    }
    return 0;
}
