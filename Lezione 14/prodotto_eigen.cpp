#include <chrono>
#include <iostream>
#include <Eigen/Dense>

int main() {
    const int N = 500;
    Eigen::MatrixXd A(N, N), B(N, N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A(i, j) = 0.001 * (i + j);
            B(i, j) = 0.001 * (i - j);
        }
    }
    auto inizio = std::chrono::high_resolution_clock::now();
    Eigen::MatrixXd C = A * B;
    auto fine = std::chrono::high_resolution_clock::now();
    auto ms = std::chrono::duration_cast<
        std::chrono::milliseconds>(fine - inizio).count();
    std::cout << "C(1,2) = " << C(1, 2) << "\n";
    std::cout << "tempo: " << ms << " ms\n";
    return 0;
}