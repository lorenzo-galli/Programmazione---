#include <iostream>

class Particella {
    double massa_;
    double velocita_;

public:
    Particella(double massa, double velocita){
        massa_ = massa;
        velocita_ = velocita;
    }

    double calcola_energia(){
        return 0.5 * massa_ * velocita_ * velocita_;
    }

};


int main(){
    Particella p(2.0, 10.0);
    std::cout << "Energia: " << p.calcola_energia() << "\n";

}

