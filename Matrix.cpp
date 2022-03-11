#include "Matrix.h"
#include "operations/AdditionOperation.h"
#include "operations/SubstrationOperation.h"
#include "operations/MultiplicationOperation.h"

// Friend

ostream& operator<<(ostream& os, const Matrix& m) {
    for (unsigned i = 0; i < m.rows; i++) {
        for (unsigned j = 0; j < m.cols; j++) {
            os << m.data[i][j] << " ";
        }
        os << endl;
    }
    return os;
}

Matrix add(const Matrix& lhs, const Matrix& rhs) {
    Matrix result(lhs);
    return result.add(rhs);
}

Matrix* addDyn(const Matrix& lhs, const Matrix& rhs) {
    auto* result = new Matrix(lhs);
    result->add(rhs);
    return result;
}

Matrix sub(const Matrix& lhs, const Matrix& rhs) {
    Matrix result(lhs);
    return result.sub(rhs);
}

Matrix* subDyn(const Matrix& lhs, const Matrix& rhs) {
    auto* result = new Matrix(lhs);
    result->sub(rhs);
    return result;
}

Matrix mult(const Matrix& lhs, const Matrix& rhs) {
    Matrix result(lhs);
    return result.mult(rhs);
}

Matrix* multDyn(const Matrix& lhs, const Matrix& rhs) {
    auto* result = new Matrix(lhs);
    result->mult(rhs);
    return result;
}

// Public

Matrix::Matrix(unsigned int rows, unsigned int cols, unsigned int modulo) :
        rows(rows), cols(cols), modulo(modulo) {

    // Verify params
    if (rows <= 0 || cols <= 0) {
        throw runtime_error("Matrix dimensions must be greater than 0");
    }

    if (modulo <= 0) {
        throw runtime_error("Matrix modulo must be greater than 0");
    }

    data = allocateMatrix();
}

Matrix::Matrix(unsigned int size, unsigned int modulo) :
        Matrix(size, size, modulo) {}

Matrix::~Matrix() {
    deleteMatrix();
}

Matrix& Matrix::operator=(const Matrix& other) {
    if (this != &other) {
        deleteMatrix();
        initFrom(other);
    }
    return *this;
}

Matrix::Matrix(const Matrix& other) {
    initFrom(other);
}

// Private

void Matrix::initFrom(const Matrix& other) {
    rows = other.rows;
    cols = other.cols;
    modulo = other.modulo;
    data = allocateMatrix(other);
}

DataType** Matrix::allocateMatrix() const {
    auto** tmpData = new DataType* [rows];

    for (unsigned i = 0; i < rows; ++i) {
        tmpData[i] = new DataType[cols];
        for (unsigned j = 0; j < cols; ++j) {
            tmpData[i][j] = (DataType) (rand() / (RAND_MAX + 1.0) * modulo);
        }
    }
    return tmpData;
}

DataType** Matrix::allocateMatrix(const Matrix& other) const {
    auto** tmpData = new DataType* [rows];

    for (unsigned i = 0; i < rows; ++i) {
        tmpData[i] = new DataType[cols];
        for (unsigned j = 0; j < cols; ++j) {
            tmpData[i][j] = other.data[i][j];
        }
    }
    return tmpData;
}

void Matrix::deleteMatrix() {
    for (unsigned i = 0; i < rows; ++i) {
        delete[] this->data[i];
    }
    delete[] data;
}

Matrix& Matrix::add(const Matrix& other) {
    static AdditionOperation<DataType> op;
    operation(op, other);
    return *this;
}

Matrix& Matrix::sub(const Matrix& other) {
    static SubstractionOperation<DataType> op;
    operation(op, other);
    return *this;
}

Matrix& Matrix::mult(const Matrix& other) {
    static MultiplicationOperation<DataType> op;
    operation(op, other);
    return *this;
}

void Matrix::operation(const Operation<DataType>& operation, const Matrix& other) {
    if (modulo != other.modulo) {
        throw runtime_error("Matrices must have the same modulo");
    }

    unsigned maxRows = max(rows, other.rows);
    unsigned maxCols = max(cols, other.cols);

    auto** tmp = new DataType* [maxRows];

    for (unsigned i = 0; i < maxRows; ++i) {
        tmp[i] = new DataType[maxCols];
        for (unsigned j = 0; j < maxCols; ++j) {
            DataType a = (i < rows && j < cols) ? data[i][j] : 0;
            DataType b = (i < other.rows && j < other.cols) ? other.data[i][j] : 0;
            tmp[i][j] = operation.execute(a, b) % modulo;
        }
    }
    deleteMatrix();
    data = tmp;
    rows = maxRows;
    cols = maxCols;
}




