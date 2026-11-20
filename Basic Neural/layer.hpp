#ifndef LAYER_HPP
#define LAYER_HPP

#include <Eigen/Dense>

enum class InitType   { HE, XAVIER };
enum class DistroType { UNIFORM, GAUSSIAN };

class Layer {
public:
    virtual ~Layer() {}
    virtual Eigen::MatrixXd forward(
        const Eigen::MatrixXd& input) = 0;
};

#endif