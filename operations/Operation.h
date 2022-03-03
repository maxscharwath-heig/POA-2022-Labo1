#ifndef LABO_1_OPERATION_H
#define LABO_1_OPERATION_H


template<typename T>
class Operation {
public:
   Operation() {
      std::cout << "Operation constructor" << std::endl;
   }

   ~Operation() {
      std::cout << "Operation destructor" << std::endl;
   }

   virtual T execute(T a, T b) const = 0;
};


#endif //LABO_1_OPERATION_H
