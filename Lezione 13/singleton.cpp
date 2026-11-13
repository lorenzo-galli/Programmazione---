#include <iostream>

class Generatore {
private:
    int n_ = 0;
    Generatore() {}
public:
    Generatore(const Generatore&) = delete;
    Generatore& operator=(const Generatore&) = delete;
    static Generatore& get() {
        static Generatore unico;
        return unico;
    }
    int prossimo() { return ++n_; }
};
void altra_funzione() {
    std::cout << Generatore::get().prossimo() << "\n";
}
int main() {
    Generatore& g = Generatore::get();
    std::cout << g.prossimo() << "\n";
    altra_funzione();
    std::cout << g.prossimo() << "\n";
    return 0;
}