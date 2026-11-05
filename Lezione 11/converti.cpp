#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
int main() {
    std::stringstream ss("7,0,128.9,255");
    std::string campo;
    std::getline(ss, campo, ',');      // l'etichetta
    int etichetta = std::stoi(campo);
    int somma = 0;
    while (std::getline(ss, campo, ',')) {
        somma += std::stoi(campo);
    }
    std::cout << etichetta << " " << somma << "\n";
    try {
        std::stoi("abc");
    } catch (const std::invalid_argument& e) {
        std::cout << "eccezione: " << e.what() << "\n";
    }
    return 0;
}