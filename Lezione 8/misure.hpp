#ifndef MISURE_HPP
#define MISURE_HPP

const int MAX_MISURE = 100;

class Misure {
private:
    double x_[MAX_MISURE];
    int n_;

public:
    Misure();
    void aggiungi(double v);
    int numero();
    double valore(int i);
};

#endif