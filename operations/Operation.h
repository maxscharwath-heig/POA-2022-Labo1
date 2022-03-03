#ifndef LABO_1_OPERATION_H
#define LABO_1_OPERATION_H


template<typename T>
class Operation {
public:
   virtual T execute(T a, T b) const = 0;
};


#endif //LABO_1_OPERATION_H
