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


    double eta = 1;

    std::cout << "t\tE\t\tw1\tw2\n";

    for (int t = 0; t <= 200; ++t) {

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

        if (t % 20 == 0) { 
            
            std::cout << t << "\t" << mse << "\t" << w[0] << "\t" << w[1] << "\n";

        }

        w[0] = w[0] - eta * dE_dw[0];
        w[1] = w[1] - eta * dE_dw[1];

}
}

// Non arriva a convergere se y = 1 perché la sigmoide raggiunge 1 per z -> +inf