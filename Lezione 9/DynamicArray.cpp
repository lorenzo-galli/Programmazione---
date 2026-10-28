#include <iostream>
#include "DynamicArray.hpp"

DynamicArray::DynamicArray(int size) : size_(size), data_(nullptr) {
    data_ = new double[size_]; // da completare (una riga): data_ riceve un array di size_ double (new[])
}

DynamicArray::~DynamicArray() {
    delete[] data_; // da completare (una riga): liberate data_ con delete[]
    std::cout << "distruttore: liberati " << size_ << " elementi\n";
}

void DynamicArray::imposta(int indice, double valore) {
    if (indice >= 0 && indice < size_) {      // indice valido
        data_[indice] = valore; // da completare (una riga): scrivete valore in data_[indice]
    }
}

double DynamicArray::leggi(int indice) const {
    if (indice >= 0 && indice < size_) {      // indice valido
        return data_[indice]; // da completare (una riga): restituite data_[indice]
    }
    return 0.0;                               // indice non valido
}