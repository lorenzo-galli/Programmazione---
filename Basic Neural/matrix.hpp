#ifndef MATRIX_HPP
#define MATRIX_HPP

class Matrix {
private:
    int rows;
    int cols;
    double* data;  // rows * cols, row-major

public:
    Matrix(int r, int c);
    ~Matrix();
    Matrix(const Matrix& altra);
    Matrix& operator=(const Matrix& altra);

    double get(int r, int c) const;
    void set(int r, int c, double val);
    int getRows() const;
    int getCols() const;
};

#endif