#ifndef LABO_1_SUBSTRATIONOPERATION_H
#define LABO_1_SUBSTRATIONOPERATION_H

#include "Operation.h"

template<typename T>
class SubstractionOperation : public Operation<T> {
public:
    T execute(T a, T b) const override {
        return a - b;
    }
};

#endif //LABO_1_SUBSTRATIONOPERATION_H
