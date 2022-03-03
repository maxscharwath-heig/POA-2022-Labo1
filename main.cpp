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

   // Copy constructor
   Matrix m3(m1);
   cout << m3;
   //verify(m3 == m1);
   cout << &m1 << "==" << &m3 << "=" << ((&m1 == &m3) ? "True" : "False") << endl;
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
   Matrix onePlusTwo1 = one.addCopy(two);
   cout << "addCopy()" << endl << onePlusTwo1 << endl;

   Matrix oneCopy = one;
   Matrix onePlusTwo2 = oneCopy.add(two);
   cout << "add()" << endl << onePlusTwo2 << endl;

   Matrix *onePlusTwo3 = one.addDyn(two);
   cout << "addDyn()" << endl << *onePlusTwo3 << endl;
   delete onePlusTwo3;
   //
   cout << "one - two" << endl;
   Matrix oneMinusTwo1 = one.subCopy(two);
   cout << "subCopy()" << endl << oneMinusTwo1 << endl;

   Matrix oneCopy2 = one;
   Matrix oneMinusTwo2 = oneCopy2.sub(two);
   cout << "sub()" << endl << oneMinusTwo2 << endl;

   Matrix *oneMinusTwo3 = one.subDyn(two);
   cout << "subDyn()" << endl << *oneMinusTwo3 << endl;
   delete oneMinusTwo3;
   //
   cout << "one * two" << endl;
   //
   Matrix oneTimesTwo1 = one.multCopy(two);
   cout << "mulCopy()" << endl << oneTimesTwo1 << endl;

   Matrix oneCopy3 = one;
   Matrix oneTimesTwo2 = oneCopy3.mult(two);
   cout << "mul()" << endl << oneTimesTwo2 << endl;

   Matrix *oneTimesTwo3 = one.multDyn(two);
   cout << "mulDyn()" << endl << *oneTimesTwo3 << endl;
   delete oneTimesTwo3;

   // More specific tests
   cout << "Tests" << endl;
   unit_tests();
   return 0;
}
