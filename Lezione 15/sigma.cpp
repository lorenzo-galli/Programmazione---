#include <cmath>
#include <iostream>

enum class InitType { HE, XAVIER };

// deviazione standard dei pesi gaussiani (Laboratorio 08)
double sigma(InitType type, int n_in, int n_out) {
    switch (type) {
        case InitType::HE:
            return std::sqrt(2.0 / n_in);
        case InitType::XAVIER:
            return std::sqrt(2.0 / (n_in + n_out));
    }
    return 0.0;
}

int main() {
    std::cout << sigma(InitType::HE, 784, 128) << "\n";
    std::cout << sigma(InitType::XAVIER, 784, 128) << "\n";
    return 0;
}