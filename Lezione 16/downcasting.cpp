#include <iostream>
#include "layers.hpp"

int main() {
    Layer* p = new DenseLayer(128, 784);
    Layer* q = new SigmoidLayer();
    DenseLayer* d = static_cast<DenseLayer*>(p);
    std::cout << d->numero_pesi() << "\n";
    delete p;
    delete q;
    return 0;
}