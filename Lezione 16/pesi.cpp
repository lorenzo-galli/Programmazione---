#include <iostream>
#include <vector>

template <typename T>
class Pesi {
private:
    std::vector<T> w_;
public:
    Pesi(int Nn, int Ni) : w_(Nn * Ni) {}
    int quanti() const { return w_.size(); }
    int byte() const { return w_.size() * sizeof(T); }
};

int main() {
    Pesi<float>  f(128, 784);
    Pesi<double> d(128, 784);
    std::cout << f.quanti() << " pesi\n";
    std::cout << "float:  " << f.byte() << " byte\n";
    std::cout << "double: " << d.byte() << " byte\n";
    return 0;
}