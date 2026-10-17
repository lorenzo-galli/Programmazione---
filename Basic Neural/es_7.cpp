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

double attiva(int tipo, double z){
    if (tipo == 0) {
        return sigmoide(z);
    } else if (tipo == 1) {
        return tanh_mia(z);
    } else if (tipo == 2) {
        return ReLU(z);
    } else {
        std::cerr << "Tipo di attivazione non valido: " << tipo << std::endl;
        return 0.0; // Valore di default in caso di errore
    }
}

double deriva(int tipo, double z){
    if (tipo == 0) {
        return derivata_sigmoide(z);
    } else if (tipo == 1) {
        return derivata_tanh(z);
    } else if (tipo == 2) {
        return derivata_ReLU(z);
    } else {
        std::cerr << "Tipo di derivata non valido: " << tipo << std::endl;
        return 0.0; // Valore di default in caso di errore
    }
}


void addestra(int tipo, double y, double w0, double eta){
    
    std::cout << "t\tE\t\tw1\tw2\n";

    double x = 1.0, mse;

    double z[2], a[2], delta[2], w[2] = {w0, w0}, sigma_primo[2], dE_dw[2];


    for (int t = 0; t <= 1000; ++t) {
        // Forward pass

        z[0] = w[0] * x;
        a[0] = attiva(tipo, z[0]);

        z[1] = w[1] * a[0];
        a[1] = attiva(tipo, z[1]);

        // Backward propagation

        mse = (a[1] - y) * (a[1] - y);
        sigma_primo[1] = deriva(tipo, a[1]);

        delta[1] = 2 * (a[1] - y) * sigma_primo[1];
        dE_dw[1] = delta[1]*a[0];


        sigma_primo[0] = deriva(tipo, a[0]);
        delta[0] = delta[1] * sigma_primo[0]*w[1];
        dE_dw[0] = delta[0] * x;
        
        // Stampa solo ogni _ iterazioni
        if (t % 500 == 0) { 
            
            std::cout << t << "\t" << mse << "\t" << w[0] << "\t" << w[1] << "\n";

        }

        w[0] = w[0] - eta * dE_dw[0];
        w[1] = w[1] - eta * dE_dw[1];
    }

}

int main() {
    int tipo = 2; // 0: sigmoide, 1: tanh, 2: ReLU
    double y = 0.8;
    double w0 = 5;
    double eta = 0.25;
    addestra(tipo, y, w0, eta);
    return 0;
}

// PUNTO 3
// Tutte raggiungono 0.8 ma la sigmoide rimane con E = e-12 mentre le altre due a E = e-32
// Sigmoide non ce la fa con y = 1, rimane con E = e-4, tangenteh sta a E = e-6, ReLU arrivata a 0 preciso

// PUNTO 4
// Perché chiaramente calcolando a2 = 1, quindi l'output del nostro ultimo layer è precisamente 1, come y
// Dato che i pesi sono negativi, il gradiente della funzione di attivazione ReLU è 0, quindi non c'è più aggiornamento dei pesi e l'errore rimane costante

// PUNTO 5 - caso w0 = 0
// L'unica che apprende è la sigmoide, la ReLU per lo stesso motivo del punto 4, il problema della tanh è che a 0 vale 0 e nel primo step forward a1 e a2 diventano 0 (dato che sono f(w * precedente))
// Quindi è proprio perché la sigmoide è sempre positiva che vince questa volta

// PUNTO 5 - caso w0 = 5
// La sigmoide va e arriva a E = e-13, la tanh arriva a 0 preciso e la ReLU con il fatto che non è limitata dà un errore molto grande al primo passo e poi i pesi vanno a valori negativi e si blocca
// Probabilmente tanh impara perché tanh(5) = 0.9999 e quindi lo becca quasi al primo tentativo