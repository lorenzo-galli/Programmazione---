#include <iostream>
#include "misure.hpp"
#include "statistiche.hpp"

int main() {
    Misure periodo;
    periodo.aggiungi(2.01);
    periodo.aggiungi(1.98);
    periodo.aggiungi(2.03);
    periodo.aggiungi(1.99);
    periodo.aggiungi(2.00);

    Statistiche s(periodo);
    std::cout << "T = " << s.media() << " s, sigma = " << s.sigma() << " s\n";
    return 0;
}