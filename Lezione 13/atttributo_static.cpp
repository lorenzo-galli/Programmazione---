#include <iostream>

class Particella {
private:
    static inline int totale_ = 0;
public:
    Particella() { totale_++; }
    ~Particella() { totale_--; }
    static int quante() { return totale_; }
};

int main() {
    Particella a, b;
    std::cout << Particella::quante() << "\n";
    return 0;
}