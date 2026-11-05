#ifndef PARAMETRIC_LAYER_HPP
#define PARAMETRIC_LAYER_HPP

#include <Eigen/Dense>

class DenseLayer {
private:
    Eigen::MatrixXd Wt;       // W: Nn x Ni
    Eigen::MatrixXd biases;   // b: Nn x 1

public:
    DenseLayer(int Nn, int Ni);  // neuroni, ingressi

    Eigen::MatrixXd forward(
        const Eigen::MatrixXd& input);

    const Eigen::MatrixXd& getWeights() const;
    const Eigen::MatrixXd& getBiases() const;
};

#endif