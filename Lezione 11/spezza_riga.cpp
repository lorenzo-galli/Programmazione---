#include <iostream>
#include <sstream>
#include <string>

int main() {
    std::string riga = "7,0,128,255";
    std::stringstream ss(riga);
    std::string campo;
    while (std::getline(ss, campo, ',')) {
        std::cout << "[" << campo << "]\n";
    }
    return 0;
}