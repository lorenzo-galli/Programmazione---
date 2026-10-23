#pragma once
#include "misure.hpp"

class Statistiche {
private:
    double media_;
    double sigma_;

public:
    Statistiche(Misure& m);
    double media();
    double sigma();
};