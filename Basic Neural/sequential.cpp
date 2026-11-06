#include "sequential.hpp"

Sequential::~Sequential() {
    for(Layer* l : layers){
        delete l;
    }
    // da scrivere: un for sugli elementi di layers
    // che distrugge ogni layer
}

void Sequential::add(Layer* layer) {
    layers.push_back(layer);
    // da scrivere: aggiungere layer in fondo al vettore
}

Eigen::MatrixXd Sequential::forward(
        const Eigen::MatrixXd& input) {
    Eigen::MatrixXd corrente = input;
    for (Layer* l : layers) {
        corrente = l->forward(corrente);
    }
    return corrente;
}