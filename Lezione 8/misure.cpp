#include "misure.hpp"

Misure::Misure() : n_(0) {}

void Misure::aggiungi(double v) {
    if (n_ < MAX_MISURE) {
        x_[n_] = v;
        ++n_;
    }
}

int Misure::numero() { return n_; }

double Misure::valore(int i) { return x_[i]; }
