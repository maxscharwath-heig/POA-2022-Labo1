#ifndef LABO_1_ADDITIONOPERATION_H
#define LABO_1_ADDITIONOPERATION_H

#include "Operation.h"

template<typename T>
class AdditionOperation : public Operation<T> {
public:
   T execute(T a, T b) const override {
      return a + b;
   }
};


#endif //LABO_1_ADDITIONOPERATION_H
