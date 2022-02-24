#include <iostream>
#include "Matrix.h"

Matrix::Matrix(unsigned rows, unsigned int cols, unsigned modulo) : rows(rows), cols(cols), modulo(modulo) {

    data = new unsigned *[rows];

    for (unsigned i = 0; i < rows; ++i) {
        data[i] = new unsigned[cols];
    }

    for (unsigned i = 0; i < rows; ++i) {
        for (unsigned j = 0; j < cols; ++j) {
            data[i][j] = (1 + rand() / (RAND_MAX + 1.0) * modulo);
        }
    }
}

Matrix::Matrix(unsigned int rows, unsigned modulo) : Matrix(rows, rows, modulo) {}

Matrix::~Matrix() {

    for (unsigned i = 0; i < rows; ++i) {
        delete[] this->data[i];
    }

    delete[] data;
}
