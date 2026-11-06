#ifndef LAYER_HPP
#define LAYER_HPP

#include <Eigen/Dense>

class Layer {
public:
    virtual ~Layer() {}
    virtual Eigen::MatrixXd forward(
        const Eigen::MatrixXd& input) = 0;
};

#endif