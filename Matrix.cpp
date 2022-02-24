#include "Matrix.h"

/**
 * Output Flux Operators for the Matrix Class
 * @param os The output stream
 * @param m The matrix to output
 * @return The output stream
 */
ostream &operator<<(ostream &os, const Matrix &m) {
    for (unsigned i = 0; i < m.rows; i++) {
        for (unsigned j = 0; j < m.cols; j++) {
            os << m.data[i][j] << " ";
        }
        os << endl;
    }
    return os;
}

Matrix::Matrix(unsigned int rows, unsigned int cols, unsigned int modulo) : rows(rows), cols(cols), modulo(modulo) {
    data = new DataType *[rows];

    for (unsigned i = 0; i < rows; ++i) {
        data[i] = new DataType[cols];
    }

    for (unsigned i = 0; i < rows; ++i) {
        for (unsigned j = 0; j < cols; ++j) {
            data[i][j] = (DataType) (rand() / (RAND_MAX + 1.0) * modulo);
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
