#ifndef LABO_1_MATRIX_H
#define LABO_1_MATRIX_H

#include <iostream>

using namespace std;

using DataType = unsigned int;

/**
 * Matrix class
 * This class is used to represent a matrix.
 * @author Crausaz Nicolas & Scharwath Maxime
 */

class Matrix {
public:
    friend ostream &operator<<(ostream &os, const Matrix &m);

    Matrix(DataType rows, DataType cols, unsigned modulo);

    Matrix(DataType rows, unsigned modulo);

    ~Matrix();

private:
    const DataType rows, cols;
    unsigned const modulo;
    DataType **data;
};

#endif //LABO_1_MATRIX_H
