#include <iostream>
#include <vector>

class Layer {
public:
    virtual ~Layer() { std::cout << "~Layer\n"; }
    virtual void forward() const = 0;
};

class DenseLayer : public Layer {
private:
    int Nn_, Ni_;
public:
    DenseLayer(int Nn, int Ni) : Nn_(Nn), Ni_(Ni) {}
    ~DenseLayer() { std::cout << "~DenseLayer\n"; }
    void forward() const override { std::cout << "DenseLayer: " << Nn_ << " x " << Ni_ << "\n"; }
};

class SigmoidLayer : public Layer {
public:
    ~SigmoidLayer() { std::cout << "~SigmoidLayer\n"; }
    void forward() const override { std::cout << "SigmoidLayer\n"; }
};
int main() {
    std::vector<Layer*> rete;
    rete.push_back(new DenseLayer(128, 784));
    rete.push_back(new SigmoidLayer());
    for (Layer* l : rete) {
        l->forward();
    }
    for (Layer* l : rete) {
        delete l;
    }
    return 0;
}