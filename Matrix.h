#ifndef LABO_1_MATRIX_H
#define LABO_1_MATRIX_H

#include <iostream>
#include "operations/Operation.h"

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

    Matrix &operator=(const Matrix &other);

    Matrix(DataType rows, DataType cols, unsigned modulo);

    Matrix(DataType rows, unsigned modulo);

    Matrix(const Matrix &other);

    ~Matrix();

    // Operations
    Matrix &add(const Matrix &other);

    Matrix addCopy(const Matrix &other) const;

    Matrix *addDyn(const Matrix &other) const;

    Matrix &sub(const Matrix &other);

    Matrix subCopy(const Matrix &other) const;

    Matrix *subDyn(const Matrix &other) const;

    Matrix &mult(const Matrix &other);

    Matrix multCopy(const Matrix &other) const;

    Matrix *multDyn(const Matrix &other) const;
    // Addition
    // self
    // Static
    // Dynamic

private:
    DataType rows, cols;
    unsigned modulo;
    DataType **data;

    DataType **allocateMatrix() const;

    DataType **allocateMatrix(const Matrix &other) const;

    void deleteMatrix();

    void operation(const Operation<DataType> &operation, const Matrix &other);
};

#endif //LABO_1_MATRIX_H
