#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

void scrivi_csv() {
    std::ofstream os("finto_mnist.csv");
    os << "label,p0,p1,p2\n";
    os << "3,0,128,255\n";
    os << "1,0,0,255\n";
}   // qui os viene distrutto: il file è chiuso

void leggi_csv() {
    std::ifstream f("finto_mnist.csv");
    if (!f.is_open()) {
        std::cerr << "Errore: impossibile aprire finto_mnist.csv\n";
        return;
    }
    std::string riga;
    std::getline(f, riga);   // salta l'intestazione
    while (std::getline(f, riga)) {
        // da completare:
        // 1. uno std::stringstream ss costruito da riga
        std::stringstream ss(riga);
        // 2. l'etichetta, con std::getline(ss, campo, ',')
        std::string campo;
        std::getline(ss, campo, ',');

        // 3. la stampa di "Trovata immagine del numero: ",
        //    dell'etichetta convertita con std::stoi e di ". Pixel:"
        // L'etichetta sta come prima cosa della riga

        std::cout << "Trovata immagine del numero: " << std::stoi(campo) << "\n";

        // 4. un ciclo sugli altri campi: per ognuno, uno spazio
        //    e il valore convertito con std::stoi
        
        while(std::getline(ss, campo, ',')){
            std::cout << std::stoi(campo) << " ";
        }
        // 5. un a capo
        std::cout << "\n";
    }
}

int main() {
    scrivi_csv();
    leggi_csv();
    return 0;
}