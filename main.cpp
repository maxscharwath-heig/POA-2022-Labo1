#include <iostream>
#include "Matrix.h"

using namespace std;

int main() {
   Matrix m1 = Matrix(4, 6, 4);
   cout << m1 << endl;

   Matrix m2 = Matrix(4, 8);

   cout << m2 << endl;
   return 0;
}
