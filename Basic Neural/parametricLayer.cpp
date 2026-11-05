#include "parametricLayer.hpp"

DenseLayer::DenseLayer(int Nn, int Ni) {
    Wt = Eigen::MatrixXd::Random(Nn, Ni);        // valori casuali tra -1 e 1
    biases = Eigen::MatrixXd::Zero(Nn, 1);       // bias nulli
}

Eigen::MatrixXd DenseLayer::forward(const Eigen::MatrixXd& input) {
    return Wt * input + biases;
}

const Eigen::MatrixXd& DenseLayer::getWeights() const { return Wt; }
const Eigen::MatrixXd& DenseLayer::getBiases() const { return biases; }