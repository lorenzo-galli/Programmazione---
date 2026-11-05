#include <fstream>
#include <iostream>

int main() {
    std::ifstream dataset("mnist_test.csv");
    if (!dataset.is_open()) {
        std::cerr << "Errore: impossibile "
                     "aprire mnist_test.csv\n";
        return 1;
    }
    std::cout << "File aperto\n";
    return 0;
}