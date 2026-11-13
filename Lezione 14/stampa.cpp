#include <iostream>

class Vettore2D {
private:
    double x_, y_;
public:
    Vettore2D(double x, double y) : x_(x), y_(y) {}
    friend std::ostream& operator<<(std::ostream& os,
                                    const Vettore2D& v);
};

std::ostream& operator<<(std::ostream& os, const Vettore2D& v) {
    os << "(" << v.x_ << ", " << v.y_ << ")";
    return os;
}

int main() {
    Vettore2D v(3.0, 4.0);
    std::cout << "v = " << v << "\n";
    return 0;
}