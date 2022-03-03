#ifndef LABO_1_MULTIPLICATIONOPERATION_H
#define LABO_1_MULTIPLICATIONOPERATION_H

#include "Operation.h"

template<typename T>
class MultiplicationOperation : public Operation<T> {
public:
    T execute(T a, T b) const override {
        return a * b;
    }
};

#endif //LABO_1_MULTIPLICATIONOPERATION_H
