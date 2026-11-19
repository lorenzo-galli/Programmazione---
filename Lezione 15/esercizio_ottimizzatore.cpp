#include <iostream>
#include <string>

// da completare: l'enum class OptimizerType, con i valori SGD, ADAM e RMSPROP

enum class OptimizerType {SGD, ADAM, RMSPROP};


// da completare: il parametro diventa OptimizerType opt, e il corpo uno switch
// su opt, senza default, che restituisce "SGD", "Adam" o "RMSprop"
std::string nome(OptimizerType opt) {
    switch (opt) {
        case OptimizerType::SGD:
            return "SGD";
        case OptimizerType::ADAM:
            return "Adam";
        case OptimizerType::RMSPROP:
            return "RMSProp";
    }

    return "";
    
}

int main() {
    OptimizerType opt = OptimizerType::ADAM;
    std::cout << nome(opt) << "\n";
    std::cout << static_cast<int>(opt) << "\n";
    return 0;
}