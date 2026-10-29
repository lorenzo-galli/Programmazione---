#include <iostream>

class DynamicArray {
private:
    int size_;
    double* data_;
public:
    DynamicArray(int size)
        : size_(size), data_(new double[size]) {}
    ~DynamicArray() { delete[] data_; }
    int size() const { return size_; }
    // in più rispetto a copia_superficiale.cpp
    void stampaIndirizzo() const {
        std::cout << this << "\n";
    }
};

int main() {
    DynamicArray a(5);
    std::cout << &a << "\n";
    a.stampaIndirizzo();
    DynamicArray b(3);
    std::cout << &b << "\n";
    b.stampaIndirizzo();
    return 0;
}