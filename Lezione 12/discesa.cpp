#include "Vettore2D.hpp"
#include "Funzione2D.hpp"
#include <iostream>


int discesa(const Funzione2D& f, Vettore2D &x, double eta, int max_passi) {
    for (int n = 1; n <= max_passi; ++n) {
        Vettore2D risultato_gradiente = f.gradiente(x);
        x = x - risultato_gradiente * eta;
        // da completare: il passo, x = x - f.gradiente(x) * eta;
        double g = risultato_gradiente.norma();
        if (g < 1e-6) { return n; }
        else if (g > 1e10) { return -1; }
        // da completare: se g < 1e-6 restituite n (convergenza)
        // da completare: se g > 1e10 restituite -1 (divergenza)
    }
    return max_passi;
}

void prova(const Funzione2D& f, const std::string& nome, Vettore2D x, double eta) {
    const int max_passi = 1000000;
    int passi = discesa(f, x, eta, max_passi);
    std::cout << nome << ", eta = " << eta << ": ";
    if (passi < 0) {
        std::cout << "diverge\n";
        return;
    }
    if (passi == max_passi) std::cout << "non converge";
    else                    std::cout << passi << " passi";
    std::cout << ", x = (" << x.getX() << ", " << x.getY() << "), F = " << f.valore(x) << "\n";
}

int main() {
    Paraboloide p;
    Rosenbrock r;
    prova(p, "Paraboloide", Vettore2D(2.0, 1.0), 0.2);
    prova(r, "Rosenbrock", Vettore2D(-1.2, 1.0), 0.001);
    prova(r, "Rosenbrock", Vettore2D(-1.2, 1.0), 0.0019);
    prova(r, "Rosenbrock", Vettore2D(-1.2, 1.0), 0.002);
    return 0;
}