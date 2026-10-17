#include <cstdlib>   // std::srand
#include <ctime>     // std::time
#include <iostream>
#include <cmath>

double derivata_quadratica(double x){
    return 2 * x;
}

double sigmoide(double x){
    return 1.0 / (1.0 + std::exp(-x));
}

double derivata_sigmoide(double a){
    return a * (1 - a);
}


int main() {

    double x = 1.0, y = 0.8, mse;

    double z[2], a[2], delta[2], w[2] = {1.0, 1.0}, sigma_primo[2], dE_dw[2];

    // Forward pass
    z[0] = w[0] * x;
    a[0] = sigmoide(z[0]);

    z[1] = w[1] * a[0];
    a[1] = sigmoide(z[1]);

    // Backward propagation

    mse = (a[1] - y) * (a[1] - y);
    sigma_primo[1] = derivata_sigmoide(a[1]);

    delta[1] = 2 * (a[1] - y) * sigma_primo[1];
    dE_dw[1] = delta[1]*a[0];

    sigma_primo[0] = derivata_sigmoide(a[0]);
    delta[0] = delta[1] * sigma_primo[0]*w[1];
    dE_dw[0] = delta[0] * x;

    // Tabella

    std::cout << "Tabella grandezze\n\n" << "\tstrato 1\tstrato 2\n\n";
    std::cout << "z\t" << z[0] << "\t" << z[1] << "\n";
    std::cout << "a\t" << a[0] << "\t" << a[1] << "\n";
    std::cout << "sigma'\t" << sigma_primo[0] << "\t" << sigma_primo[1] << "\n";
    std::cout << "delta\t" << delta[0] << "\t" << delta[1] << "\n";
    std::cout << "dE_dw\t" << dE_dw[0] << "\t" << dE_dw[1] << "\n\n\n";
    

}