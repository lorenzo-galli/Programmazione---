#include <chrono>
#include <iostream>

const int N = 4000;
double M[N][N];                    // 128 MB, globale

int main() {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            M[i][j] = 0.001 * (i + j);
    auto inizio = std::chrono::high_resolution_clock::now();
    double s = 0.0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            s += M[i][j];
    auto fine = std::chrono::high_resolution_clock::now();
    auto ms = std::chrono::duration_cast<
        std::chrono::milliseconds>(fine - inizio).count();
    std::cout << "somma = " << s << "\n";
    std::cout << "tempo: " << ms << " ms\n";
    return 0;
}