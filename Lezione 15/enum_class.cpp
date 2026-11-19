#include <iostream>

enum class InitType   { HE, XAVIER };
enum class DistroType { UNIFORM, GAUSSIAN };

void init_weights(InitType type, DistroType distro) {
    if (type == InitType::HE) std::cout << "He, ";
    else                      std::cout << "Xavier, ";
    if (distro == DistroType::UNIFORM)
        std::cout << "uniforme\n";
    else
        std::cout << "gaussiana\n";
}

int main() {
    init_weights(InitType::HE, DistroType::GAUSSIAN);
    int n = static_cast<int>(InitType::XAVIER);
    std::cout << n << "\n";
    return 0;
}