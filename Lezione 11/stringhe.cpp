#include <iostream>
#include <string>

int main() {
    std::string nome = "mnist_test.csv";
    std::string vuota;
    std::cout << nome << " ha " << nome.size()
              << " caratteri\n";
    std::cout << vuota.empty() << "\n";
    std::string percorso = "../" + nome;
    std::cout << percorso << "\n";
    return 0;
}