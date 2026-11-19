#ifndef LAYERS_HPP
#define LAYERS_HPP

class Layer {
public:
    virtual ~Layer() = default;
    virtual int numero_pesi() const {return 0;};
};

class DenseLayer : public Layer {
private:
    int Nn_, Ni_;
public:
    DenseLayer(int Nn, int Ni) : Nn_(Nn), Ni_(Ni) {}
    int numero_pesi() const override { return Nn_ * Ni_; }
};

class SigmoidLayer : public Layer {};

#endif