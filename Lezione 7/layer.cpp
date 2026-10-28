#include <iostream>


class DenseLayer {

    int Nnodes;
    int Nin;

public:
    DenseLayer(int Nn, int Ni): Nnodes(Nn), Nin(Ni) {}

    int numParametri(){ return Nnodes * Nin; }

    void descrivi(){
        std::cout << "DenseLayer " << Nnodes << "-> " << Nin << ": " << numParametri() << " parametri\n"; 
    }

    
};

class SigmoidLayer{
    
public:

    int numParametri() {return 0;}
    void descrivi(){
        std::cout << "SigmoidLayer: " << numParametri() << " parametri\n"; 
    }
};

int main(){
    DenseLayer d1(200, 784);
    SigmoidLayer s;
    DenseLayer d2(10, 200);

    d1.descrivi();
    s.descrivi();
    d2.descrivi();

    std::cout << "Num totale di parametri: " << d1.numParametri() + d2.numParametri() + 2 * s.numParametri() << "\n";

}