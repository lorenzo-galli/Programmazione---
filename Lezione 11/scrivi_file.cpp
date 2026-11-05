#include <fstream>
#include <iostream>

int main() {
    std::ofstream os("loss.csv");
    if (!os.is_open()) {
        std::cerr << "Errore: impossibile "
                     "scrivere loss.csv\n";
        return 1;
    }
    os << "epoca,loss\n";
    for (int epoca = 1; epoca <= 3; epoca++) {
        os << epoca << "," << 1.0 / epoca << "\n";
    }
    return 0;
}

