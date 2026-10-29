#include <iostream>
#include "Vettore2D.hpp"

int main() {
    Vettore2D v1(3.0, 4.0);
    Vettore2D v2 = v1 * 5.0;
    std::cout << v2.getX() << " "
              << v2.getY() << "\n";
    return 0;
}