#include "Matrix.h"
#include "operations/AdditionOperation.h"

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

Matrix::Matrix(unsigned int rows, unsigned int cols, unsigned int modulo) : rows(
      rows), cols(cols), modulo(modulo) {

   // Verify params
   if (rows == 0 || cols == 0) {
      throw runtime_error("Matrix dimensions must be greater than 0");
   }

   if (modulo == 0) {
      throw runtime_error("Matrix modulo must be greater than 0");
   }

   allocateMatrix();

   for (unsigned i = 0; i < rows; ++i) {
      for (unsigned j = 0; j < cols; ++j) {
         data[i][j] = (DataType) (rand() / (RAND_MAX + 1.0) * modulo);
      }
   }
}

Matrix::Matrix(unsigned int rows, unsigned modulo) : Matrix(rows, rows, modulo) {}

Matrix::~Matrix() {
   deleteMatrix();
}

Matrix &Matrix::operator=(const Matrix &other) {
   if (this != &other) {
      rows = other.rows;
      cols = other.cols;
      modulo = other.modulo;

      deleteMatrix();
      allocateMatrix();
      copyMatrixData(other);
   }
   return *this;
}

void Matrix::copyMatrixData(const Matrix &m) {
   for (unsigned i = 0; i < rows; ++i) {
      for (unsigned j = 0; j < cols; ++j) {
         data[i][j] = m.data[i][j];
      }
   }
}

void Matrix::allocateMatrix() {
   data = new DataType *[rows];
   for (unsigned i = 0; i < rows; ++i) {
      data[i] = new DataType[cols];
   }
}

void Matrix::deleteMatrix() {
   for (unsigned i = 0; i < rows; ++i) {
      delete[] this->data[i];
   }
   delete[] data;
}

Matrix::Matrix(const Matrix &other) {
   rows = other.rows;
   cols = other.cols;
   modulo = other.modulo;
   allocateMatrix();
   copyMatrixData(other);
}

Matrix Matrix::operator+(const Matrix &other) const {
   Matrix result(*this);
   AdditionOperation<DataType> add;
   result.operation(add, other);
   return result;
}

void Matrix::operation(const Operation<DataType> &operation, const Matrix &other) {
   if (modulo != other.modulo) {
      throw runtime_error("Matrices must have the same modulo");
   }
   unsigned maxRows = max(rows, other.rows);
   unsigned maxCols = max(cols, other.cols);

   auto **tmp = new DataType *[maxRows];
   for (unsigned i = 0; i < maxRows; ++i) {
      tmp[i] = new DataType[maxCols];
      for (unsigned j = 0; j < maxCols; ++j) {
         DataType a = (i < rows && j < cols) ? data[i][j] : 0;
         DataType b = (i < other.rows && j < other.cols) ? other.data[i][j] : 0;
         tmp[i][j] = operation.execute(a, b);
      }
   }
   deleteMatrix();
   data = tmp;
   rows = maxRows;
   cols = maxCols;
}
