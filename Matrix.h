#ifndef LABO_1_MATRIX_H
#define LABO_1_MATRIX_H

#include <iostream>
#include "operations/Operation.h"

using namespace std;

using DataType = unsigned int; // Data type of the matrix

/**
 * Matrix class
 * This class is used to represent a matrix.
 * @author Crausaz Nicolas & Scharwath Maxime
 */
class Matrix {
public:
    /**
     * Output Flux Operators for the Matrix Class
     * @param os The output stream
     * @param m The matrix to output
     * @return The output stream
     */
    friend ostream& operator<<(ostream& os, const Matrix& m);

    /**
     * Main Constructor for the Matrix Class
     * @param rows The number of rows
     * @param cols The number of columns
     * @param modulo The modulo to use
     */
    Matrix(unsigned int rows, unsigned int cols, unsigned int modulo);

    /**
     * Square Constructor for the Matrix Class
     * @param size The size of the square matrix
     * @param modulo The modulo to use
     */
    Matrix(unsigned int size, unsigned int modulo);

    /**
     * Allocator operator for the Matrix Class
     * @param other The matrix to copy
     * @return The new matrix
     */
    Matrix& operator=(const Matrix& other);

    /**
     * Copy constructor for the Matrix Class
     * @param other The matrix to copy
     */
    Matrix(const Matrix& other);

    /**
     * Destructor for the Matrix Class
     */
    ~Matrix();

    /**
     * Addition operator edit the current matrix
     * @param other The matrix to add
     * @return the edited matrix
     */
    Matrix& add(const Matrix& other);

    /**
     * Addition operator return a new matrix
     * @param other The matrix to add
     * @return the new matrix
     */
    Matrix addCopy(const Matrix& other) const;

    /**
     * Addition operator dynamic version
     * @param other The matrix to add
     * @return the new matrix pointer
     */
    Matrix* addDyn(const Matrix& other) const;

    /**
     * Subtraction operator edit the current matrix
     * @param other The matrix to substract
     * @return the edited matrix
     */
    Matrix& sub(const Matrix& other);

    /**
     * Subtraction operator return a new matrix
     * @param other The matrix to substract
     * @return the new matrix
     */
    Matrix subCopy(const Matrix& other) const;

    /**
     * Subtraction operator dynamic version
     * @param other The matrix to substract
     * @return the new matrix pointer
     */
    Matrix* subDyn(const Matrix& other) const;

    /**
     * Multiplication operator edit the current matrix
     * @param other The matrix to multiply
     * @return the edited matrix
     */
    Matrix& mult(const Matrix& other);

    /**
     * Multiplication operator return a new matrix
     * @param other The matrix to multiply
     * @return the new matrix
     */
    Matrix multCopy(const Matrix& other) const;

    /**
     * Multiplication operator dynamic version
     * @param other The matrix to multiply
     * @return the new matrix pointer
     */
    Matrix* multDyn(const Matrix& other) const;

private:
    unsigned int rows, cols;
    unsigned int modulo;
    DataType** data;

    /**
     * Allocate a new matrix with random values
     * @return the matrix data pointer
     */
    DataType** allocateMatrix() const;

    /**
     * Allocate a new matrix with the values of another matrix
     * @warning No check is done on the dimensions
     * @param other The matrix to copy
     * @return the matrix data pointer
     */
    DataType** allocateMatrix(const Matrix& other) const;

    /**
     * Deallocate the matrix data
     */
    void deleteMatrix();

    /**
     * Execute an operation on the current matrix
     * @param operation The operation to execute
     * @param other The matrix to use with
     * @throw std::runtime_error if matrix modulo are different
     */
    void operation(const Operation<DataType>& operation, const Matrix& other);
};

#endif //LABO_1_MATRIX_H
