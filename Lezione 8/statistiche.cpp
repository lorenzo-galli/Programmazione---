#include "statistiche.hpp"
#include <cmath>

Statistiche::Statistiche(Misure& m) {
    int n = m.numero();
    double somma = 0.0;
    for (int i = 0; i < n; ++i) somma += m.valore(i);
    media_ = somma / n;
    double s2 = 0.0;
    for (int i = 0; i < n; ++i) {
        double d = m.valore(i) - media_;
        s2 += d * d;
    }
    sigma_ = std::sqrt(s2 / (n - 1));
}

double Statistiche::media() { return media_; }

double Statistiche::sigma() { return sigma_; }