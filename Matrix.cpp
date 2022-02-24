#include <iostream>
#include "Matrix.h"

Matrix::Matrix(unsigned int rows, unsigned int cols) : rows(rows), cols(cols) {
    data = new unsigned *[rows];

    for (unsigned i = 0; i < rows; ++i) {
        data[i] = new unsigned[cols];
    }

    for (unsigned i = 0; i < rows; ++i) {
        for (unsigned j = 0; j < cols; ++j) {
            data[i][j] = 0;
        }
    }
}

Matrix::Matrix(unsigned int rows) : Matrix(rows, rows) {}

Matrix::~Matrix() {

    for (unsigned i = 0; i < rows; ++i) {
        delete[] this->data[i];
    }

    delete[] data;
}
