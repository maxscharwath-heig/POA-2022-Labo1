#ifndef LABO_1_MATRIX_H
#define LABO_1_MATRIX_H

/**
 * Matrix class
 * This class is used to represent a matrix.
 * @author Crausaz Nicolas & Maxime Scharwath
 */
class Matrix {
public:
    Matrix (unsigned rows, unsigned cols);
    Matrix(unsigned rows);

    ~Matrix();

private:
    const unsigned rows, cols;
    unsigned **data;
};


#endif //LABO_1_MATRIX_H
