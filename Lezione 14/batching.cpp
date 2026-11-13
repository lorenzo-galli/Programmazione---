#include <chrono>
#include <iostream>
#include <Eigen/Dense>

int main() {
    int neuroni = 128;          // come in DenseLayer(128, 784)
    int n = 1000;               // ripetizioni
    Eigen::MatrixXd W = Eigen::MatrixXd::Random(neuroni, 784);
    Eigen::MatrixXd x = Eigen::MatrixXd::Random(784, 1);   // 1 immagine
    Eigen::MatrixXd X = Eigen::MatrixXd::Random(784, 64);  // 64 immagini
    Eigen::MatrixXd z, Z;
    auto t0 = std::chrono::high_resolution_clock::now();
    for (int r = 0; r < 64 * n; r++) { z = W * x; }   // una alla volta
    auto t1 = std::chrono::high_resolution_clock::now();
    for (int r = 0; r < n; r++) { Z = W * X; }        // 64 insieme
    auto t2 = std::chrono::high_resolution_clock::now();
    std::cout << "una alla volta: " << std::chrono::duration_cast<
        std::chrono::milliseconds>(t1 - t0).count() << " ms\n";
    std::cout << "64 insieme: " << std::chrono::duration_cast<
        std::chrono::milliseconds>(t2 - t1).count() << " ms\n";
    return 0;
}