#include "Vettore2D.hpp"
#include <iostream>

Vettore2D gradF(const Vettore2D& p){
    return Vettore2D(2.0 * p.getX(), 8.0 * p.getY());
}

int discesa(Vettore2D x, double eta, int max_passi) {
    for (int n = 1; n <= max_passi; ++n) {
        x = x - gradF(x) * eta;
        // da completare: il passo, x = x - gradF(x) * eta;
        double g = gradF(x).norma();
        if (g < 1e-6) { return n; }
        else if (g > 1e10) { return -1; }
        // da completare: se g < 1e-6 restituite n (convergenza)
        // da completare: se g > 1e10 restituite -1 (divergenza)
    }
    return max_passi;
}


int main(){
    double etas[4] = {0.1, 0.2, 0.24, 0.26};
    double eta;
    int risultato;

    for (int i = 0; i < 4; i++){
        eta = etas[i];

        risultato = discesa(Vettore2D(2.0, 1.0), eta, 100000);

        std::cout << "eta= " << eta << ": " << risultato << " passi\n";
    }
}