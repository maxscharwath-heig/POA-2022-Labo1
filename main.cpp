#include <iostream>
#include "Matrix.h"

using namespace std;

void unit_tests() {
    // Invalid modulo
    try {
        // Should throw
        Matrix mInvalidModulo1(2, 0);
    }
    catch (const std::exception &e) {
        cout << e.what() << endl;
    }

    try {
        // Should throw
        Matrix mInvalidModulo2(2, 3, 0);
    }
    catch (const std::exception &e) {
        cout << e.what() << endl;
    }

    try {
        // Should throw
        Matrix mInvalidRowsAndCols(0, 0, 8);
    }
    catch (const std::exception &e) {
        cout << e.what() << endl;
    }

    try {
        // Should throw
        Matrix mInvalidRows(0, 2, 8);
    }
    catch (const std::exception &e) {
        cout << e.what() << endl;
    }

    try {
        // Should throw
        Matrix mInvalidCols(2, 0, 8);
    }
    catch (const std::exception &e) {
        cout << e.what() << endl;
    }

    // Matrix with one col / row
    Matrix mOneRow(1, 2, 5);
    Matrix mOneCol(3, 1, 5);

    cout << "Matrix with one row / one col" << endl;
    cout << mOneRow << endl << mOneCol << endl;

    // Matrix carrée
    Matrix carre = Matrix(3, 8);

    // Addition

    // Sub

    // Multiplication

    // Affectation
    Matrix m1(3, 8);
    Matrix m2(3, 8);

    cout << m1 << endl << m2 << endl;

    m1 = m2;

    cout << m1;
}

int main() {
    const unsigned MOD = 8;

    cout << "The modulus is " << 8 << endl;
    cout << "one" << endl;
    Matrix one = Matrix(3, 4, MOD);
    cout << one << endl;

    cout << "two" << endl;
    Matrix two = Matrix(3, 5, MOD);
    cout << two << endl;

    cout << "one + two" << endl;
    //
    cout << "one - two" << endl;
    //
    cout << "one * two" << endl;
    //

    // More specific tests
    cout << "Tests" << endl;
    unit_tests();
    return 0;
}
