#include <iostream>
#include <ctime>
#include "Matrix.h"

using namespace std;

/**
 * Unit test for Matrix class.
 */
void unit_tests() {
    const unsigned MOD = 8;
    // TEST 1a
    cout << "TEST 1a" << endl;
    try {
        // Should throw
        Matrix mInvalidModulo2(2, 3, 0);
    }
    catch (const std::exception& e) {
        cout << e.what() << endl;
    }

    // TEST 1b
    cout << "TEST 1b" << endl;
    try {
        // Should throw
        Matrix mInvalidModulo1(2, 0);
    }
    catch (const std::exception& e) {
        cout << e.what() << endl;
    }

    // TEST 2a
    cout << "TEST 2a" << endl;
    try {
        // Should throw
        Matrix mInvalidRowsAndCols(0, 0, MOD);
    }
    catch (const std::exception& e) {
        cout << e.what() << endl;
    }

    // TEST 2b
    cout << "TEST 2b" << endl;
    try {
        // Should throw
        Matrix mInvalidRows(0, 2, MOD);
    }
    catch (const std::exception& e) {
        cout << e.what() << endl;
    }

    // TEST 2c
    cout << "TEST 2c" << endl;
    try {
        // Should throw
        Matrix mInvalidCols(2, 0, MOD);
    }
    catch (const std::exception& e) {
        cout << e.what() << endl;
    }

    // TEST 2d
    cout << "TEST 2d" << endl;
    try {
        // Should throw
        Matrix mInvalidCols(0, MOD);
    }
    catch (const std::exception& e) {
        cout << e.what() << endl;
    }

    // TEST 3a
    cout << "TEST 3a" << endl;
    Matrix validMatrix = Matrix(4, 5, MOD);
    cout << validMatrix << endl;

    // TEST 3b
    cout << "TEST 3b" << endl;
    Matrix validSquareMatrix = Matrix(4, MOD);
    cout << validSquareMatrix << endl;

    // TEST 4a
    cout << "TEST 4a" << endl;
    Matrix mOneRow(1, 2, MOD);
    cout << mOneRow << endl;

    // TEST 4b
    cout << "TEST 4b" << endl;
    Matrix mOneCol(3, 1, MOD);
    cout << mOneCol << endl;

    // TEST 5a
    cout << "TEST 5a" << endl;
    Matrix m1(3, 4, MOD);
    Matrix m2(m1);
    cout << m1 << endl << m2 << endl;

    // TEST 5b
    cout << "TEST 5b" << endl;
    Matrix m3(3, MOD);
    cout << m1 << endl << m3 << endl;
    m1 = m3;
    cout << m1 << endl << m3 << endl;

    // TEST 6a
    cout << "TEST 6a" << endl;
    Matrix add1 = Matrix(4, 5, MOD);
    Matrix toAdd1 = Matrix(4, 5, MOD);
    cout << add1 << "+" << endl << toAdd1 << "=" << endl;
    add1.add(toAdd1);
    cout << add1 << endl;

    // TEST 6b
    cout << "TEST 6b" << endl;
    Matrix add2 = Matrix(2, 4, MOD);
    Matrix toAdd2 = Matrix(3, 2, MOD);
    cout << add2 << "+" << endl << toAdd2 << "=" << endl << add2.add(toAdd2) << endl;

    // TEST 6c
    cout << "TEST 6c" << endl;
    Matrix addCopy1 = Matrix(4, 5, MOD);
    Matrix toAddCopy1 = Matrix(4, 5, MOD);
    cout << addCopy1 << "+" << endl << toAddCopy1 << "=" << endl << add(addCopy1, toAddCopy1) << endl;

    // TEST 6d
    cout << "TEST 6d" << endl;
    Matrix addCopy2 = Matrix(2, 4, MOD);
    Matrix toAddCopy2 = Matrix(3, 2, MOD);
    cout << addCopy2 << "+" << endl << toAddCopy2 << "=" << endl << add(addCopy2, toAddCopy2) << endl;

    // TEST 6e
    cout << "TEST 6e" << endl;
    Matrix addDyn1 = Matrix(4, 5, MOD);
    Matrix toAddDyn1 = Matrix(4, 5, MOD);
    Matrix* dyn1 = addDyn(addDyn1, toAddDyn1);
    cout << addDyn1 << "+" << endl << toAddDyn1 << "=" << endl << *dyn1 << endl;
    delete dyn1;

    // TEST 6f
    cout << "TEST 6f" << endl;
    Matrix addDyn2 = Matrix(2, 4, MOD);
    Matrix toAddDyn2 = Matrix(3, 2, MOD);
    Matrix* dyn2 = addDyn(addDyn2, toAddDyn2);
    cout << addDyn2 << "+" << endl << toAddDyn2 << "=" << endl << *dyn2 << endl;
    delete dyn2;

    // TEST 7a
    cout << "TEST 7a" << endl;
    Matrix sub1 = Matrix(4, 5, MOD);
    Matrix toSub1 = Matrix(4, 5, MOD);
    cout << sub1 << "-" << endl << toSub1 << "=" << endl << endl;
    sub1.sub(toSub1);
    cout << sub1 << endl;

    // TEST 7b
    cout << "TEST 7b" << endl;
    Matrix sub2 = Matrix(2, 4, MOD);
    Matrix toSub2 = Matrix(3, 2, MOD);
    cout << sub2 << "-" << endl << toSub2 << "=" << endl << endl;
    sub2.sub(toSub2);
    cout << sub2 << endl;

    // TEST 7c
    cout << "TEST 7c" << endl;
    Matrix subCopy1 = Matrix(4, 5, MOD);
    Matrix toSubCopy1 = Matrix(4, 5, MOD);
    cout << subCopy1 << "-" << endl << toSubCopy1 << "=" << endl << sub(subCopy1, toSubCopy1) << endl;

    // TEST 7d
    cout << "TEST 7d" << endl;
    Matrix subCopy2 = Matrix(2, 4, MOD);
    Matrix toSubCopy2 = Matrix(3, 2, MOD);
    cout << subCopy2 << "-" << endl << toSubCopy2 << "=" << endl << sub(subCopy2, toSubCopy2) << endl;

    // TEST 7e
    cout << "TEST 7e" << endl;
    Matrix subDyn1 = Matrix(4, 5, MOD);
    Matrix toSubDyn1 = Matrix(4, 5, MOD);
    Matrix* dyn3 = subDyn(subDyn1, toSubDyn1);
    cout << subDyn1 << "-" << endl << toSubDyn1 << "=" << endl << *dyn3 << endl;
    delete dyn3;

    // TEST 6f
    cout << "TEST 6f" << endl;
    Matrix subDyn2 = Matrix(2, 4, MOD);
    Matrix toSubDyn2 = Matrix(3, 2, MOD);
    Matrix* dyn4 = subDyn(subDyn2, toSubDyn2);
    cout << subDyn2 << "-" << endl << toSubDyn2 << "=" << endl << *dyn4 << endl;
    delete dyn4;

    // TEST 8a
    cout << "TEST 8a" << endl;
    Matrix mult1 = Matrix(4, 5, MOD);
    Matrix toMult1 = Matrix(4, 5, MOD);
    cout << mult1 << "*" << endl << toMult1 << "=" << endl << endl;
    mult1.mult(toMult1);
    cout << mult1 << endl;

    // TEST 8b
    cout << "TEST 8b" << endl;
    Matrix mult2 = Matrix(4, 5, MOD);
    Matrix toMult2 = Matrix(4, 5, MOD);
    cout << mult2 << "*" << endl << toMult2 << "=" << endl << endl;
    mult2.mult(toMult2);
    cout << mult2 << endl;

    // TEST 8c
    cout << "TEST 8c" << endl;
    Matrix multCopy1 = Matrix(4, 5, MOD);
    Matrix toMultCopy1 = Matrix(4, 5, MOD);
    cout << multCopy1 << "*" << endl << toMultCopy1 << "=" << endl << mult(multCopy1, toMultCopy1) << endl;

    // TEST 8d
    cout << "TEST 8d" << endl;
    Matrix multCopy2 = Matrix(2, 4, MOD);
    Matrix toMultCopy2 = Matrix(3, 2, MOD);
    cout << multCopy2 << "*" << endl << toMultCopy2 << "=" << endl << mult(multCopy2, toMultCopy2) << endl;

    // TEST 8e
    cout << "TEST 8e" << endl;
    Matrix multDyn1 = Matrix(4, 5, MOD);
    Matrix toMultDyn1 = Matrix(4, 5, MOD);
    Matrix* dyn5 = multDyn(multDyn1, toMultDyn1);
    cout << multDyn1 << "*" << endl << toMultDyn1 << "=" << endl << *dyn5 << endl;
    delete dyn5;

    // TEST 8f
    cout << "TEST 8f" << endl;
    Matrix multDyn2 = Matrix(2, 4, MOD);
    Matrix toMultDyn2 = Matrix(3, 2, MOD);
    Matrix* dyn6 = multDyn(multDyn2, toMultDyn2);
    cout << multDyn2 << "*" << endl << toMultDyn2 << "=" << endl << *dyn6 << endl;
    delete dyn6;
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
    /*

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

    Matrix* onePlusTwo3 = one.addDyn(two);
    cout << "addDyn()" << endl << *onePlusTwo3 << endl;
    delete onePlusTwo3;
    //
    cout << "one - two" << endl;
    Matrix oneMinusTwo1 = one.subCopy(two);
    cout << "subCopy()" << endl << oneMinusTwo1 << endl;

    Matrix oneCopy2 = one;
    Matrix oneMinusTwo2 = oneCopy2.sub(two);
    cout << "sub()" << endl << oneMinusTwo2 << endl;

    Matrix* oneMinusTwo3 = one.subDyn(two);
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

    Matrix* oneTimesTwo3 = one.multDyn(two);
    cout << "mulDyn()" << endl << *oneTimesTwo3 << endl;
    delete oneTimesTwo3;
     */

    // More specific tests
    cout << "Tests" << endl;
    unit_tests();
    return 0;
}
