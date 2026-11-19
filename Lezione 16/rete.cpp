#include <iostream>
#include <vector>
#include "layers.hpp"

int main() {
    std::vector<Layer*> rete;
    rete.push_back(new DenseLayer(128, 784));
    rete.push_back(new SigmoidLayer());
    rete.push_back(new DenseLayer(10, 128));
    rete.push_back(new SigmoidLayer());

    int pesi = 0;
    for (Layer* l : rete) {
         pesi += l->numero_pesi();
    }
    std::cout << "pesi della rete: " << pesi << "\n";

    for (Layer* l : rete) delete l;
    return 0;
}