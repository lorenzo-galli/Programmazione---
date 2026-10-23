#include <iostream>

double** creaMatrice(int righe, int colonne) {
    double** m = new double*[righe];              // l'array dei puntatori
    for (int i = 0; i < righe; ++i)
        m[i] = new double[colonne];               // poi ogni riga
    return m;
}

void distruggiMatrice(double** m, int righe) {
    delete[] m;               // poi l'array dei puntatori
}

int main() {
    const int R = 3, C = 4;
    double** W = creaMatrice(R, C);
    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j)
            W[i][j] = i * C + j;
    std::cout << "W[2][3] = " << W[2][3] << "\n";
    distruggiMatrice(W, R);
}