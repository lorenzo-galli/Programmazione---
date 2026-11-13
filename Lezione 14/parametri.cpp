#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cerr << "Uso: " << argv[0]
                  << " <epoche> <learning_rate>\n";
        return 1;
    }
    int epoche = std::stoi(argv[1]);
    double lr = std::stod(argv[2]);
    std::cout << "epoche: " << epoche << ", lr: " << lr << "\n";
    std::cout << "doppio delle epoche: " << 2 * epoche << "\n";
    return 0;
}