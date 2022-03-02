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

   Matrix &operator=(const Matrix &other);

   Matrix(DataType rows, DataType cols, unsigned modulo);

   Matrix(DataType rows, unsigned modulo);

   Matrix(const Matrix &other);

   ~Matrix();

   // Operations
   // Addition
   // self
   // Static
   // Dynamic

private:
    DataType rows, cols;
    unsigned modulo;
    DataType **data;


    // void applyOperation(const Operation& operation, const Matrix& matrix);
    void copyMatrixData(const Matrix& matrix);

    void allocateMatrix();
    void deleteMatrix();
};

#endif //LABO_1_MATRIX_H
