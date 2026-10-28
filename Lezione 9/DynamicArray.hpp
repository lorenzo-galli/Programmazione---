#pragma once

class DynamicArray {
private:
    int size_;
    double* data_;
public:
    DynamicArray(int size);
    ~DynamicArray();
    void imposta(int indice, double valore);
    double leggi(int indice) const;
};