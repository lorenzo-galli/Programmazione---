#include <cmath>
#include <iostream>
#include "parametricLayer.hpp"
#include "randnumgen.hpp"

// Task 3: un numero gaussiano di media 0 e varianza 1 (Box-Muller)
static double gauss() {
    double x1, x2;
    do {
        x1 = rng.ranf();
        x2 = rng.ranf();
    } while (x1 == 0 || x2 == 0);
    return std::cos(2 * M_PI * x2) * std::sqrt(-2.0 * std::log(x1));
}

DenseLayer::DenseLayer(int Nn, int Ni, InitType type,
                       DistroType distro) {
    // da completare: uno switch su type, senza default,
    double s;

    switch (type) {
        case InitType::HE:

            switch (distro) {
                case DistroType::UNIFORM:
                    s = std::sqrt(6.0/Ni);
                    break;
                case DistroType::GAUSSIAN:
                    s = std::sqrt(2.0/Ni);
                    std::cout << "Il valore di s è: " << s << "\n" ;
                    break;
            }
            break;

        case InitType::XAVIER:

            switch (distro) {
                case DistroType::UNIFORM:
                    s = std::sqrt(6.0/(Ni+Nn));
                    break;
                case DistroType::GAUSSIAN:
                    s = std::sqrt(2.0/(Ni+Nn));
                    break;
            }
            break;

    }

    // che calcola s con le formule della tabella
    // pesi uniformi in [-s, s), o gaussiani con sigma = s
    Wt = Eigen::MatrixXd(Nn, Ni);
    for (int i = 0; i < Nn; i++) {
        for (int j = 0; j < Ni; j++) {
            if (distro == DistroType::UNIFORM)
                Wt(i, j) = 2.0 * s * (rng.ranf() - 0.5);
            else
                Wt(i, j) = s * gauss();
        }
    }
    biases = Eigen::MatrixXd::Zero(Nn, 1);   // bias nulli
}

Eigen::MatrixXd DenseLayer::forward(const Eigen::MatrixXd& input) {
    return Wt * input + biases;
}

const Eigen::MatrixXd& DenseLayer::getWeights() const { return Wt; }
const Eigen::MatrixXd& DenseLayer::getBiases() const { return biases; }