#ifndef ACTIVATION_LAYERS_HPP
#define ACTIVATION_LAYERS_HPP

#include "layer.hpp"

// Task 4: la classe base delle attivazioni, per ora vuota
class ActivationLayer : public Layer {
};

class SigmoidLayer : public ActivationLayer {
public:
    Eigen::MatrixXd forward(
        const Eigen::MatrixXd& input) override;
};

class TanhLayer : public ActivationLayer {
public:
    Eigen::MatrixXd forward(
        const Eigen::MatrixXd& input) override;
};

#endif