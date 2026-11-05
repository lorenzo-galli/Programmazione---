#include <iostream>

int main() {
    double w = 1.0 / 3.0;
    std::cout << w << "\n";
    std::cout.precision(17);
    std::cout << w << "\n";
    // equivale a (con #include <iomanip>):
    // std::cout << std::setprecision(17);
    return 0;
}