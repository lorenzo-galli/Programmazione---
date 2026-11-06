#ifndef PARAMETRIC_LAYER_HPP
#define PARAMETRIC_LAYER_HPP
#include "layer.hpp"

class DenseLayer : public Layer {
private:
    Eigen::MatrixXd Wt;       // W: Nn x Ni
    Eigen::MatrixXd biases;   // b: Nn x 1

public:
    DenseLayer(int Nn, int Ni);  // neuroni, ingressi

    Eigen::MatrixXd forward(
        const Eigen::MatrixXd& input) override;

    const Eigen::MatrixXd& getWeights() const;
    const Eigen::MatrixXd& getBiases() const;
};

#endif