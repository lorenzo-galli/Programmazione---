#include <iostream>

class Neurone{

double peso_;
double lr_;

public:

    double get_Peso(){return peso_;}
    double get_Lr(){return lr_;}

    void setLr(double nuovo){
        if(nuovo > 0 && nuovo <= 1) {
            lr_ = nuovo;
        }
        else{
            std::cerr << "Learning rate non compreso tra (0, 1]\n" ;
        }

    }

    Neurone() : peso_(0.0), lr_(0.1) {};
    Neurone(double peso, double lr) : peso_(peso), lr_(0.1) {setLr(lr);}


    

};


int main(){

    Neurone n; 
    n.setLr(5.0);
    n.setLr(0.5);

    std::cout << "Learning rate: " << n.get_Lr() << "\n";

    Neurone m(0.7, 99.0);

    std::cout << "Peso di m: " << m.get_Peso() << "\n";
    std::cout << "Peso di m: " << m.get_Lr() << "\n";
    

}