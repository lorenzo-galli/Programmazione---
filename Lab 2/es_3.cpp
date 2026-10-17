#include <cstdlib>   // std::srand
#include <ctime>     // std::time
#include <iostream>
#include <cmath>


double derivata_quadratica(double x){
    return 2 * x;
}

int main() {
    int a = 10;
    int b = 3;

    std::cout << "a/b senza cast: " << a/b << "\n";
    std::cout << "a/b con cast: " << static_cast<double>(a) / b << "\n";

    double eta;
    double error;
    int i = 1;

    double pos;

    for(i = 1; i <= 5; i++){
        pos = 1;
        eta = i * 0.25;

        std::cout << "Learning rate (eta): " << eta << "\n\n";

        std::cout << "Posizione iniziale: " << pos << "\n\n";


        int j = 0;
        for (j = 0; j < 5; j++){


            pos = pos - eta * derivata_quadratica(pos);

            std::cout << "Posizione " << j + 1 << ": " << pos << "\n"; 

        }

        error = pos*pos;

        std::cout << "Posizione finale: " << pos << "\n\n"; 
        std::cout << "Errore (MSE): " << error << "\n\n";
        std::cout << "-------------\n\n";

    }
}