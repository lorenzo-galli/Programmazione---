#pragma once
#include "Vettore2D.hpp"

class Funzione2D {
public:
    virtual ~Funzione2D() {}
    virtual double valore(const Vettore2D& p) const = 0;
    virtual Vettore2D gradiente(const Vettore2D& p) const = 0;
};

class Paraboloide : public Funzione2D {
public:
    double valore(const Vettore2D& p) const override {
        double x = p.getX(), y = p.getY();
        return x * x + 4.0 * y * y;
    }
    Vettore2D gradiente(const Vettore2D& p) const override {
        return Vettore2D(2.0 * p.getX(), 8.0 * p.getY());
    }
};
class Rosenbrock : public Funzione2D {
public:
    double valore(const Vettore2D& p) const override {
        double x = p.getX(), y = p.getY();
        return (1 - x) * (1 - x) + 100 * (y - x*x) * (y - x*x);
    }
    Vettore2D gradiente(const Vettore2D& p) const override {
       double x = p.getX(), y = p.getY();

        // da completare: (-2 (1-x) - 400 x (y-x^2), 200 (y-x^2))
        return Vettore2D(-2 * (1-x) - 400 * x * (y - x*x), 200 * (y-x*x));
    }
};