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
    void imposta(int i, double v) { data_[i] = v; }
    double leggi(int i) const { return data_[i]; }
};

int main() {
    DynamicArray a(5);
    a.imposta(0, 1.0);
    DynamicArray b(5);
    b.imposta(0, 9.0);
    std::cout << a.leggi(0) << "\n";
    return 0;
}