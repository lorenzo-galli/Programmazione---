#include <iostream>

enum InitType   { HE, XAVIER };
enum DistroType { UNIFORM, GAUSSIAN };

void init_weights(InitType type, DistroType distro) {
    if (type == HE) std::cout << "He, ";
    else            std::cout << "Xavier, ";
    if (distro == UNIFORM) std::cout << "uniforme\n";
    else                   std::cout << "gaussiana\n";
}

int main() {
    init_weights(HE, GAUSSIAN);
    int n = XAVIER;      // un enum si converte in int
    std::cout << n << "\n";
    return 0;
}