#include <iostream>

class DynamicArray {
private:
    int size_;
    double* data_;
public:
    DynamicArray(int size) : size_(size), data_(new double[size]) {}
    DynamicArray(const DynamicArray& altro)
        : size_(altro.size_), data_(new double[altro.size_]) {
        for (int i = 0; i < size_; i++) data_[i] = altro.data_[i];
    }
    DynamicArray& operator=(const DynamicArray& altro) {
        if (this == &altro) return *this;
        delete[] data_;
        size_ = altro.size_;
        data_ = new double[size_];
        for (int i = 0; i < size_; i++) data_[i] = altro.data_[i];
        return *this;
    }
    ~DynamicArray() { delete[] data_; }
    void imposta(int i, double v) { data_[i] = v; }
    double leggi(int i) const { return data_[i]; }
};

int main() {
    DynamicArray a(5);
    a.imposta(0, 1.0);
    DynamicArray b = a;        // costruttore di copia
    DynamicArray c(3);
    c = a;                     // operatore di assegnamento
    b.imposta(0, 9.0);
    c.imposta(0, 7.0);
    std::cout << a.leggi(0) << " " << b.leggi(0)
              << " " << c.leggi(0) << "\n";
    return 0;
}