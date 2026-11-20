#include <iostream>
#include <stdexcept>
#include <chrono>
#include <cmath>
#include <Eigen/Dense>
#include "parametricLayer.hpp"
#include "sequential.hpp"
#include "activation_layers.hpp"
#include "randnumgen.hpp"


void prova_dense_layer() {
    // un'immagine MNIST: 784 pixel in colonna
    Eigen::MatrixXd x = Eigen::MatrixXd::Random(784, 1);
    // 128 neuroni, 784 ingressi
    DenseLayer strato(128, 784);
    Eigen::MatrixXd z = strato.forward(x);
    std::cout << "z: " << z.rows() << " x " << z.cols()
              << std::endl;

    // z(0,0) ricalcolato con il ciclo del Laboratorio 04
    const Eigen::MatrixXd& W = strato.getWeights();
    double acc = 0.0;
    for (int i = 0; i < 784; i++) {
        acc += W(0, i) * x(i, 0);
    }
    acc += strato.getBiases()(0, 0);
    std::cout << z(0, 0) << " " << acc << std::endl;
}

// Task 5: una rete di due layer, 784 -> 128 -> 10
void prova_sequential() {
    Eigen::MatrixXd x = Eigen::MatrixXd::Random(784, 1);
    Sequential rete;
    rete.add(new DenseLayer(128, 784));
    rete.add(new DenseLayer(10, 128));
    Eigen::MatrixXd z = rete.forward(x);
    std::cout << "layer: " << rete.size() << ", z: "
              << z.rows() << " x " << z.cols() << std::endl;
}

// Task 3: 784 -> 128 -> 10, sigmoide dopo ogni DenseLayer
void costruisci_rete(Sequential& rete) {
    rete.add(new DenseLayer(128, 784));
    rete.add(new SigmoidLayer());
    rete.add(new DenseLayer(10, 128));
    rete.add(new SigmoidLayer());
}

void prova_rete() {
    Eigen::MatrixXd x = Eigen::MatrixXd::Random(784, 1);
    Sequential rete;
    costruisci_rete(rete);
    Eigen::MatrixXd y = rete.forward(x);
    std::cout << "y: " << y.rows() << " x " << y.cols()
              << ", min " << y.minCoeff()
              << ", max " << y.maxCoeff() << std::endl;
}

// Laboratorio 07, Task 4: il tempo di n forward della rete
void misura_tempo() {
    Eigen::MatrixXd x = Eigen::MatrixXd::Random(784, 1);
    Sequential rete;
    costruisci_rete(rete);
    int n = 10000;   // una sola forward e' troppo breve da misurare
    auto inizio = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < n; i++) {
        rete.forward(x);
    }
    auto fine = std::chrono::high_resolution_clock::now();
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(
        fine - inizio).count();
    std::cout << n << " forward: " << ms << " ms" << std::endl;
}

// Laboratorio 08, Task 5: la deviazione standard dei pesi
void prova_inizializzazione() {
    DenseLayer l(128, 784);    // He, gaussiana: i default
    const Eigen::MatrixXd& W = l.getWeights();
    double media = W.mean();
    double sigma = std::sqrt((W.array() - media).square().mean());
    std::cout << "deviazione standard dei pesi: " << sigma
              << ", attesa: " << std::sqrt(2.0 / 784) << std::endl;
}

// Laboratorio 08, Task 5: una rete con la tanh in uscita
void prova_tanh() {
    Eigen::MatrixXd x = Eigen::MatrixXd::Random(784, 1);
    Sequential rete;
    rete.add(new DenseLayer(128, 784));
    rete.add(new SigmoidLayer());
    rete.add(new DenseLayer(10, 128, InitType::XAVIER,
                            DistroType::UNIFORM));
    rete.add(new TanhLayer());
    Eigen::MatrixXd y = rete.forward(x);
    std::cout << "tanh: min " << y.minCoeff()
              << ", max " << y.maxCoeff() << std::endl;
}

// Laboratorio 08, Task 6 (facoltativo): il test del chi quadro
// da scrivere: come chiSquare del Listato 7.11 del libro
double chi_quadro(const int* oss, const double* att, int K){
    
    double phi = 0, delta; 

    for(int i = 0; i < K; i++){
        delta = oss[i]-att[i];
        phi += delta*delta/(att[i]); 
    }

    return phi;
}

// Laboratorio 08, Task 6: i pesi di He contro la gaussiana
void prova_chi_quadro() {
    const int K = 20;
    DenseLayer l(128, 784);    // He, gaussiana
    const Eigen::MatrixXd& W = l.getWeights();
    double s = std::sqrt(2.0 / 784);
    double xmin = -4 * s, dx = 8 * s / K;
    int oss[K] = {0};
    for (int i = 0; i < W.rows(); i++)
        for (int j = 0; j < W.cols(); j++) {
            int k = (int) std::floor((W(i, j) - xmin) / dx);
            k = (k < 0) ? 0 : (k > K - 1) ? K - 1 : k;   // estremi fino a -/+infinito
            oss[k]++;
        }
    double att[K];
    for (int k = 0; k < K; k++) {
        double a = (k == 0) ? -INFINITY : xmin + k * dx;
        double b = (k == K - 1) ? INFINITY : xmin + (k + 1) * dx;
        att[k] = 0.5 * W.size() * (std::erf(b / (s * std::sqrt(2.0)))
                                 - std::erf(a / (s * std::sqrt(2.0))));
    }
    std::cout << "chi quadro: " << chi_quadro(oss, att, K)
              << ", gradi di liberta': " << K - 1 << std::endl;
}

int main() {
    rng.seed(42);
    prova_dense_layer();
    prova_sequential();
    prova_rete();
    misura_tempo();
    prova_inizializzazione();
    prova_tanh();
    prova_chi_quadro();
    return 0;
}

// SENZA Ottimizzazioni con address Sanitizer ---- 10000 forward: 15961 ms
// SENZA Ottimizzazioni ---- 10000 forward: 6818 ms
// 01 --- 10000 forward: 120 ms
// 02 --- 10000 forward: 124 ms
// 03 --- 10000 forward: 121 ms
// -O3 -march=native --- 120 ms