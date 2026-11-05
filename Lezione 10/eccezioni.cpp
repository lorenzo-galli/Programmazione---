#include <iostream>
#include <stdexcept>

class DynamicArray {
private:
    int size_;
    double* data_;
public:
    DynamicArray(int size)
        : size_(size), data_(new double[size]) {}
    ~DynamicArray() {
        delete[] data_;
        std::cout << "distruttore\n";
    }
    double leggi(int indice) const {
        if (indice < 0 || indice >= size_) {
            throw std::out_of_range("indice non valido");
        }
        return data_[indice];
    }
};
int main() {
    try {
        DynamicArray a(5);
        std::cout << a.leggi(7) << "\n";
        std::cout << "non stampato\n";
    } catch (const std::out_of_range& e) {
        std::cerr << "Errore: " << e.what() << "\n";
    }
    return 0;
}