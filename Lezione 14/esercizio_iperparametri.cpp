#include <iostream>
#include <stdexcept>
#include <string>

int main(int argc, char* argv[]) {
    // da completare: se gli argomenti sono meno di tre, stampate su std::cerr
    // come si usa il programma e restituite 1

    if (argc < 4){
        std::cerr << "Uso: " << argv[0] << "<batch_size> <learning_rate> <dataset>\n";
        return 1;
    }

    try {
        int batch = std::stoi(argv[1]);
        double lr = std::stof(argv[2]);

        std::string dataset = argv[3];

        std::cout << " Training sul dataset: "<< dataset << ". Batch: " << batch << ", LR: " << lr << "\n";
    } catch (const std::invalid_argument& e) {
        std::cerr << "Argomento non numerico (" << e.what() << ")\n";
        return 1;
    }

    return 0;
}