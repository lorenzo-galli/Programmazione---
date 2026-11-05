#include <iostream>

// Task 5 

struct CMatrix {
    int rows;
    int cols;
    double* data;   // rows*cols double consecutivi, in ordine row-major
};

CMatrix cmat_alloc(int rows, int cols) {
        CMatrix m;
        m.rows = rows; // specifico il numero (proprio un int) di righe e colonne
        m.cols = cols;
        m.data = new double[rows * cols]; // alloco lo spazio tramite new
        return m;
    }

void cmat_free(CMatrix& m) {
        delete[] m.data;
        m.data = nullptr;
        m.rows = 0;
        m.cols = 0;
    }

double cmat_get(const CMatrix& m, int i, int j){
    return m.data[i * m.cols + j]; // convenzione row-major
}

void cmat_set(CMatrix& m, int i, int j, double val){
    m.data[i * m.cols + j] = val; // convenzione row-major
}


void layer_forward(const CMatrix& W, const double* x, const double* b, double* z){
    int i, j;
    double acc;

    for(j = 0; j < W.rows; j++){

        acc = 0;

        for(i = 0; i < W.cols; i++){

            acc += cmat_get(W, j, i) * x[i];
        }

        z[j] = acc + b[j];
    }
}

int main() {

    // Task 1 

    int N, i, j;

    std::cout << "Inserisci il numero di input del neurone (es. 784): " << std::endl;
    std::cin >> N;

    if (N <= 0) {
        std::cerr << "Errore: il numero di input deve essere positivo." << std::endl;
        return 1;
    }

    double* pesi = new double[N];
    double* input = new double[N];

    // Task 2

    for (i = 0; i < N; ++i) {
        pesi[i] = 0.01; 
        input[i] = 1.0; 
    }

    // Task 3

    double b = 0.5; // Bias
    double z = 0.0; // Output 

    for (i = 0; i < N; ++i) {
        z += pesi[i] * input[i];
    }
    z += b; // Aggiungo bias solo alla fine una volta

    std::cout << "Risultato del calcolo (Z): <z> = " << z << std::endl;


    // Task 4

    delete[] pesi;
    delete[] input;

    // Task 6

    int M = 3; 
    CMatrix W = cmat_alloc(M, N);

    double* bias = new double[M];
    double* z_out = new double[M];

    double* x = new double[N];

    for(i = 0; i < N; i++){
        x[i] = 1.0;
    }

    for(i = 0; i < M; i++){
        bias[i] = 0.5;
    }

    for(j = 0; j < M; j++){
        for(i = 0; i < N; i++){
            cmat_set(W, j, i, 0.01*(j+1));
        }
    }

    layer_forward(W, x, bias, z_out);

    for (j = 0; j < M; j++){
        
        std::cout << "z_out[j] = " << z_out[j] << "\n";

    }

    // cmat_free(W);
    delete[] bias;
    delete[] z_out;
    delete[] x;
    

    // Task 7

    CMatrix W2 = W;
    cmat_free(W2);
    cmat_free(W);

    // Domanda 1:
    // Ricevo questo errore di double free: ==83658==ERROR: AddressSanitizer: attempting double-free on 0x62900000a200 in thread T0:


    // Domanda 2:
    // Nessuno, posso andare a pescare valori fuori dall'array, chissà cosa trovo

  return 0;
}