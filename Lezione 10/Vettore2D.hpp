#pragma once

class Vettore2D {
private:
    double x_, y_;
public:
    Vettore2D(double x, double y) : x_(x), y_(y) {}
    Vettore2D operator+(const Vettore2D& altro) const;
    Vettore2D operator*(double scalare) const;
    double getX() const { return x_; }
    double getY() const { return y_; }

    Vettore2D operator-(const Vettore2D& altro) const;
    double norma() const;
};