#include <iostream>
#include "layers.hpp"

void stampa_pesi(Layer* l) {
    DenseLayer* d = dynamic_cast<DenseLayer*>(l);
    if (d != nullptr)
        std::cout << d->numero_pesi() << " pesi\n";
    else
        std::cout << "non è un DenseLayer\n";
}

int main() {
    Layer* p = new DenseLayer(128, 784);
    Layer* q = new SigmoidLayer();
    stampa_pesi(p);
    stampa_pesi(q);
    delete p;
    delete q;
    return 0;
}