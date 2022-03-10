#include <iostream>
#include <ctime>
#include "Matrix.h"

using namespace std;

/**
 * Unit test for Matrix class.
 */
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

   // Addition (self)
   // Même taille
   Matrix add1 = Matrix(4, 5, 4);
   Matrix toAdd1 = Matrix(4, 5, 4);
   add1.add(toAdd1);
   cout << add1 << endl;
   // Taille différente

   // Une matrice totalement plus grande
   Matrix add2 = Matrix(5, 6, 4);
   Matrix toAdd2 = Matrix(3, 2, 4);
   add2.add(toAdd2);
   cout << add2 << endl;

   // Colonne plus grande
   Matrix add3 = Matrix(2, 4, 4);
   Matrix toAdd3 = Matrix(3, 2, 4);
   add3.add(toAdd3);
   cout << add3 << endl;

   // Lignes plus grande
   Matrix add4 = Matrix(4, 2, 4);
   Matrix toAdd4 = Matrix(6, 2, 4);
   add4.add(toAdd4);
   cout << add4 << endl;


   // Addition (copie)
   // Même taille
   Matrix addCopy1 = Matrix(4, 5, 4);
   Matrix toAddCopy1 = Matrix(4, 5, 4);
   cout << addCopy1.addCopy(toAddCopy1) << endl;
   // Taille différente
   // Une matrice totalement plus grande
   Matrix addCopy2 = Matrix(5, 6, 4);
   Matrix toAddCopy2 = Matrix(3, 2, 4);
   cout << addCopy2.addCopy(toAddCopy2) << endl;

   // Colonne plus grande
   Matrix addCopy3 = Matrix(2, 4, 4);
   Matrix toAddCopy3 = Matrix(3, 2, 4);
   cout << addCopy3.addCopy(toAddCopy3) << endl;

   // Lignes plus grande
   Matrix addCopy4 = Matrix(4, 2, 4);
   Matrix toAddCopy4 = Matrix(6, 2, 4);
   cout << addCopy4.addCopy(toAddCopy4) << endl;


   // Addition (dynamic allocation)
   // Même taille
   Matrix addDyn1 = Matrix(4, 5, 4);
   Matrix toAddDyn1 = Matrix(4, 5, 4);
   Matrix *dyn1 = addDyn1.addDyn(toAddDyn1);
   cout << *dyn1 << endl;
   delete dyn1;

   // Taille différente
   // Une matrice totalement plus grande
   Matrix addDyn2 = Matrix(5, 6, 4);
   Matrix toAddDyn2 = Matrix(3, 2, 4);
   Matrix *dyn2 = addDyn2.addDyn(toAddDyn2);
   cout << *dyn2 << endl;
   delete dyn2;

   // Colonne plus grande
   Matrix addDyn3 = Matrix(2, 4, 4);
   Matrix toAddDyn3 = Matrix(3, 2, 4);
   Matrix *dyn3 = addDyn3.addDyn(toAddDyn3);
   cout << *dyn3 << endl;
   delete dyn3;

   // Lignes plus grande
   Matrix addDyn4 = Matrix(4, 2, 4);
   Matrix toAddDyn4 = Matrix(6, 2, 4);
   Matrix *dyn4 = addCopy4.addDyn(toAddCopy4);
   cout << *dyn4 << endl;
   delete dyn4;

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

/**
 * Main program entry point
 * @author Maxime Scharwath
 * @author Nicolas Crausaz
 * @return
 */
int main() {
   srand(time(nullptr)); // Initialize random seed

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
