#include <iostream>
#include <sstream>

class DenseLayer {
private:
    int Nnodes, Nin;
public:
    DenseLayer(int Nn, int Ni) : Nnodes(Nn), Nin(Ni) {}
    void stampa() const {
        std::cout << Nnodes << " x " << Nin << "\n";
    }
    static DenseLayer* create_from_stream(std::istream& is) {
        int nodes, in_features;
        is >> nodes >> in_features;   // qua mi legge lo stream per separare i due numeri
        return new DenseLayer(nodes, in_features);
    }
};

int main() {
    std::stringstream file("128 784");
    DenseLayer* l = DenseLayer::create_from_stream(file);
    l->stampa();
    delete l;
    return 0;
}