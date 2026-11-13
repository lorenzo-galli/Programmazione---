#include <cmath>
#include <iostream>

class Complesso {
private:
    double re_, im_;
public:
    Complesso(double re, double im) : re_(re), im_(im) {}
    double modulo() const { return std::sqrt(re_ * re_ + im_ * im_); }
    // da completare: le dichiarazioni friend di operator<< e operator*
};

// da completare: operator<<, che scrive z nella forma (re + i*im)
// da completare: operator*, che restituisce il Complesso z per s

int main() {
    Complesso z(1.5, 2.0);
    std::cout << "|z| = " << z.modulo() << "\n";
    // std::cout << "z = " << z << "\n";             // da scommentare
    // std::cout << "2 * z = " << 2.0 * z << "\n";   // da scommentare
    return 0;
}