#include <iostream>

class Layer {
public:
    virtual ~Layer() = default;
    virtual void forward() const {
        std::cout << "Layer::forward\n";
    }
};

class DenseLayer : public Layer {
private:
    int Nn_, Ni_;
public:
    DenseLayer(int Nn, int Ni) : Nn_(Nn), Ni_(Ni) {}
    void forward() const override {
        std::cout << "DenseLayer::forward\n";
    }
    int numero_pesi() const { return Nn_ * Ni_; }
};
int main() {
    DenseLayer d(128, 784);
    Layer* p = &d;          // upcasting
    p->forward();
    std::cout << d.numero_pesi() << "\n";
    return 0;
}