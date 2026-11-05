#include "matrix.hpp"
#include <stdexcept>   // invalid_argument, out_of_range

Matrix::Matrix(int r, int c) : rows(r), cols(c) {
    if (r <= 0 || c <= 0) {
        throw std::invalid_argument(
            "Matrix: dimensioni non positive");
    }
    data = new double[rows * cols];
    for (int i = 0; i < rows * cols; i++) {
        data[i] = 0.0;
    }
}

Matrix::~Matrix() {
    delete[] data;
}

// elemento (r, c): la riga r comincia alla cella r * cols
double Matrix::get(int r, int c) const {
    if (r < 0 || r >= rows || c < 0 || c >= cols) {
        throw std::out_of_range("Matrix::get: indici fuori dai limiti");
    }
    return data[r * cols + c];
}

void Matrix::set(int r, int c, double val){
    if (r < 0 || r >= rows || c < 0 || c >= cols) {
        throw std::out_of_range("Matrix::get: indici fuori dai limiti");
    }

    data[r * cols + c] = val;

}

// un blocco nuovo, con gli stessi valori di altra
Matrix::Matrix(const Matrix& altra)
    : rows(altra.rows), cols(altra.cols),
      data(new double[altra.rows * altra.cols]) {
    for (int i = 0; i < rows * cols; i++) {
        data[i] = altra.data[i];
    }
}

Matrix& Matrix::operator=(const Matrix& altra) {
    if (this == &altra) return *this;  // a. auto-assegnamento: m = m
    // b. liberare il vecchio blocco
    delete[] this->data;
    // c. copiare rows e cols, allocare un blocco nuovo e copiarvi i valori
    this->cols = altra.cols;
    this->rows = altra.rows;

    this->data = (new double[this->rows * this->cols]);

    for (int i = 0; i < rows * cols; i++) {
        data[i] = altra.data[i];
    }

    return *this;                      // d. restituire l'oggetto stesso
}

int Matrix::getRows() const { return rows; }
int Matrix::getCols() const { return cols; }