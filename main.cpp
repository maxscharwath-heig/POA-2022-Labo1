#include <iostream>
#include "Matrix.h"

using namespace std;

void unit_tests() {
    // Row 0, col 0 (empty)

    // Row 1

    // Standard

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
