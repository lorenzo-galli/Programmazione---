#include <iostream>
#include <vector>

class Layer {
public:
    virtual void forward() const { std::cout << "Layer::forward\n"; }
};

class DenseLayer : public Layer {
private:
    int Nn_, Ni_;
public:
    DenseLayer(int Nn, int Ni) : Nn_(Nn), Ni_(Ni) {}
    void forward() const override {
        std::cout << "DenseLayer: W x + b, W di " << Nn_ << " x " << Ni_ << "\n";
    }
};

class SigmoidLayer : public Layer {
public:
    void forward() const override { std::cout << "SigmoidLayer: sigma(z)\n"; }
};
int main() {
    DenseLayer d(128, 784);
    SigmoidLayer s;
    std::vector<Layer*> rete;
    rete.push_back(&d);
    rete.push_back(&s);
    for (Layer* l : rete) {
        l->forward();
    }
    return 0;
}