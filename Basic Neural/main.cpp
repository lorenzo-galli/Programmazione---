#include <iostream>

// Soluzione del Laboratorio 02, Task 1: il main.cpp del framework, punto di
// partenza del Laboratorio 03. Gli altri task sono programmi a se', ciascuno
// col suo main(): task2_tipi.cpp, task3_discesa.cpp, task4_backprop.cpp e
// task5_addestramento.cpp. Nel CMakeLists.txt c'e' un eseguibile per task:
//   ./build/basic_neural   ./build/task2   ./build/task3   ./build/task4   ./build/task5

int main() {

    // Task 1 

    int N, i;

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
  return 0;
}