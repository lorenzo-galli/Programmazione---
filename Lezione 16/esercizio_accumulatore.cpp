#include <iostream>
#include <string>

// da completare: un template di classe Accumulatore, con
// - due attributi private: somma_ di tipo T, la somma degli elementi aggiunti,
//   e n_ di tipo int, che conta quanti elementi sono stati aggiunti;
// - un costruttore senza argomenti che inizializza somma_ a T{}
//   (un T creato senza argomenti: 0 per i numeri, "" per le stringhe) e n_ a 0;
// - void aggiungi(const T& v): aggiunge v a somma_ e incrementa n_;
// - T totale() const e int quanti() const, che restituiscono somma_ e n_;
// - double media() const: 0.0 se n_ vale 0, altrimenti
//   static_cast<double>(somma_) / n_

template <typename T>
class Accumulatore{
    private:
        T somma_;
        int n_;
    public:

        Accumulatore() : n_(0) {
        somma_ = T{};
        }
       void aggiungi(const T& v){
            somma_ += v;
            n_++;
       }
       T totale() const { return somma_; }
       int quanti() const { return n_; }

       double media() const{
        if(n_ == 0){
            return 0.0;
        } else {
            return static_cast<double>(somma_) / n_;
        }
       }

        

};

int main() {
    // da scommentare:
    Accumulatore<int> a;
    a.aggiungi(3);
    a.aggiungi(4);
    a.aggiungi(5);
    std::cout << a.totale() << " " << a.media() << "\n";

    Accumulatore<double> b;
    b.aggiungi(0.1);
    b.aggiungi(0.2);
    std::cout << b.totale() << " " << b.media() << "\n";

    Accumulatore<std::string> s;
    s.aggiungi("ciao ");
    s.aggiungi("mondo");
    std::cout << s.totale() << " " << "\n";

    return 0;
}