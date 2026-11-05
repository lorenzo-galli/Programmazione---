#include <fstream>
#include <iostream>
#include <string>

int main() {
    std::ifstream dataset("mnist_test.csv");
    if (!dataset.is_open()) {
        std::cerr << "Errore: impossibile "
                     "aprire mnist_test.csv\n";
        return 1;
    }
    std::string riga;
    int n = 0;
    while (std::getline(dataset, riga)) {
        n++;
    }
    std::cout << "Lette " << n << " righe\n";
    return 0;
}