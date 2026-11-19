#include <iostream>

// Il numero magico è una flag data per selezionare qualcosa e che non è chiara se non ti metti a leggere dentro le funzioni

// type:   0 = He, 1 = Xavier
// distro: 0 = uniforme, 1 = gaussiana
void init_weights(int type, int distro) {
    if (type == 0) std::cout << "He, ";
    else           std::cout << "Xavier, ";
    if (distro == 0) std::cout << "uniforme\n";
    else             std::cout << "gaussiana\n";
}

int main() {
    init_weights(0, 1);    // He, gaussiana
    return 0;
}