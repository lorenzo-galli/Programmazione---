#include "Vettore2D.hpp"
#include <cmath>

Vettore2D Vettore2D::operator+(const Vettore2D& altro) const {
    return Vettore2D(x_ + altro.x_, y_ + altro.y_);
}

Vettore2D Vettore2D::operator*(double scalare) const {
    return Vettore2D(x_ * scalare, y_ * scalare);
}

Vettore2D Vettore2D::operator-(const Vettore2D& altro) const {
    return Vettore2D(x_ - altro.x_, y_ - altro.y_);
}

double Vettore2D::norma() const{
    return std::sqrt(x_ * x_ + y_ * y_);
}