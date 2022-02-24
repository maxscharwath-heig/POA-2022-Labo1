#ifndef LABO_1_MATRIX_H
#define LABO_1_MATRIX_H

#include <iostream>

using namespace std;

using DataType = unsigned int;

/**
 * Matrix class
 * This class is used to represent a matrix.
 * @author Crausaz Nicolas & Maxime Scharwath
 */
class Matrix {
public:
   Matrix(unsigned rows, unsigned cols);

   Matrix(unsigned rows);

public:
   friend ostream &operator<<(ostream &os, const Matrix &m);

   ~Matrix();

private:
   const unsigned rows, cols;
   DataType **data;
};

#endif //LABO_1_MATRIX_H
