#include <cstdlib>   // std::srand
#include <ctime>     // std::time
#include <iostream>
#include <cmath>


double ReLU(double x){

    if (x < 0) {
            return 0;
        } else {
            return x;
        };

}

double derivata_ReLU(double x){

    if (x < 0) {
            return 0;
        } else {
            return 1;
        };

}

double sigmoide(double x){
    return 1.0 / (1.0 + std::exp(-x));
}

double derivata_sigmoide(double x){
    double a = sigmoide(x);
    return a * (1 - a);
}

double tanh_mia(double x){
    return std::tanh(x);
}

double derivata_tanh(double x){
    double tanh = std::tanh(x);
    return (1 - tanh*tanh);
}

double derivata_num_sigmoide(double x, double h = 1e-5){
    return (sigmoide(x + h) - sigmoide(x - h)) / (2 * h);
}

double derivata_num_tanh(double x, double h = 1e-5){
    return (tanh_mia(x + h) - tanh_mia(x - h)) / (2 * h);
}

int main(){
    std::cout << "ReLu di -2.0: " << ReLU(-2.0) << "\n";
    std::cout << "ReLu di 0.0: " << ReLU(0.0) << "\n";
    std::cout << "ReLu di 2.0: " << ReLU(2.0) << "\n";


    std::cout << "Derivata di ReLu di -2.0: " << derivata_ReLU(-2.0) << "\n";
    std::cout << "Derivata di ReLu di 0.0: " << derivata_ReLU(0.0) << "\n";
    std::cout << "Derivata di ReLu di 2.0: " << derivata_ReLU(2.0) << "\n";

    int i = -5;
    std::cout << "x\tReLU(x)\tDerivata ReLU(x)\tsigmoide(x)\tDerivata sigmoide(x)\tTanh(x)\tDerivata Tanh(x)\n";

    for (i = -5; i <= 5; i++){
        std::cout << i << "\t" << ReLU(i) << "\t" << derivata_ReLU(i) << "\t\t\t" << sigmoide(i) << "\t\t" << derivata_sigmoide(i) << "\t" << tanh(i) << "\t" << derivata_tanh(i) << "\n";
    }

    double x, max_err_der_sigmoide, max_err_der_tanh; 
    for (i = -5; i <= 5; i++){
        x = 0.5 * i;
        if (std::fabs(derivata_sigmoide(x) - derivata_num_sigmoide(x)) > max_err_der_sigmoide){
            max_err_der_sigmoide = std::fabs(derivata_sigmoide(x) - derivata_num_sigmoide(x));
        }
        if (std::fabs(derivata_tanh(x) - derivata_num_tanh(x)) > max_err_der_tanh){
            max_err_der_tanh = std::fabs(derivata_tanh(x) - derivata_num_tanh(x));
        }   
    }

    std::cout << "Max errore derivata sigmoide: " << max_err_der_sigmoide << "\n";
    std::cout << "Max errore derivata tanh: " << max_err_der_tanh << "\n";

    if (max_err_der_sigmoide < 1e-6 && max_err_der_tanh < 1e-6){
        std::cout << "Derivate corrette\n";
    } else {
        std::cout << "Derivate errate\n";
    }

    // Studiamo il variare dell'errore al variare di h
    x = 1.0;
    double h;

    std::cout << "h\tErrore derivata sigmoide\tErrore derivata tanh\n";

    for (i = 0; i < 14; i++){
        h = std::pow(10, -i);

        std::cout << h << "\t" << std::fabs(derivata_sigmoide(x) - derivata_num_sigmoide(x, h)) << "\t\t\t" << std::fabs(derivata_tanh(x) - derivata_num_tanh(x, h)) << "\n";
    }
}