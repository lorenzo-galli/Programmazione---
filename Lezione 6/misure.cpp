#include <iostream>
#include <cmath>

const int MAX_MISURE = 100;

class Misure{
    double x_[MAX_MISURE];
    int n_;

public: 
    Misure() {n_ = 0;}
    void aggiungi(double v){
        if(n_ < MAX_MISURE) {
            x_[n_] = v;
            n_++;
        }
    }

    // n_ rappresenta il numero di elementi inseriti.
    int numero(){
        return n_;
    }

    double valore(int i){
        return x_[i];
    }

};


class Statistiche {
    double media_;
    double sigma_;

public:
// Passo un oggetto m del tipo Misure
    Statistiche(Misure& m){

        media_ = 0;
        sigma_ = 0;

        // Inizializza la media
        for(int i = 0; i < m.numero(); i++){
            media_ += m.valore(i);
        }
        media_ = media_ / m.numero();


        // Inizializza la sigma
        for(int i = 0; i < m.numero(); i++){
            double d = m.valore(i) - media_;
            sigma_ += (d * d);
        }

        sigma_ = sigma_ / (m.numero() - 1);
        sigma_ = std::sqrt(sigma_);
        
    }

    double media() {return media_;}
    double sigma() {return sigma_;}
};


int main(){

    Misure m;
    m.aggiungi(2.01);
    m.aggiungi(1.98);
    m.aggiungi(2.03);
    m.aggiungi(1.99);
    m.aggiungi(2.00);

    Statistiche stats(m);

    std::cout << "Media: " << stats.media() << "\nSigma: " << stats.sigma() << "\n";
}