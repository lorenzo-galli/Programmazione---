#ifndef SEQUENTIAL_HPP
#define SEQUENTIAL_HPP
#include <vector>
#include "layer.hpp"

class Sequential {
private:
    std::vector<Layer*> layers;
public:
    Sequential() {}
    ~Sequential();

    // Non vogliamo che siano assegnati / copiati quindi li distruggiamo
    Sequential(const Sequential&) = delete;
    Sequential& operator=(const Sequential&) = delete;
    
    void add(Layer* layer);
    Eigen::MatrixXd forward(const Eigen::MatrixXd& input);
    int size() const { return layers.size(); }
};
#endif