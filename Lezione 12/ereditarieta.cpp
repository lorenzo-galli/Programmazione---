#include <iostream>
#include <string>
class Layer {
protected:
    std::string tipo_;
public:
    Layer(const std::string& tipo) : tipo_(tipo) {}
    void stampa_tipo() const { std::cout << "layer di tipo " << tipo_ << "\n"; }
};

class DenseLayer : public Layer {
private:
    int Nn_, Ni_;
public:
    DenseLayer(int Nn, int Ni) : Layer("DenseLayer"), Nn_(Nn), Ni_(Ni) {}
    void stampa_dimensioni() const {
        std::cout << tipo_ << ": " << Nn_ << " neuroni, " << Ni_ << " ingressi\n";
    }
};
int main() {
    DenseLayer d(128, 784);
    d.stampa_tipo();         // metodo ereditato da Layer
    d.stampa_dimensioni();   // metodo di DenseLayer
    return 0;
}