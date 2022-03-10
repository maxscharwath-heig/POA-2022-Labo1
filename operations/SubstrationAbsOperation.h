#ifndef LABO_1_SUBSTRATIONABSOPERATION_H
#define LABO_1_SUBSTRATIONABSOPERATION_H

#include "Operation.h"

/**
 * Subtraction operation.
 * @warning The result is converted to absolute value. Ex: 3-5=2.
 * @tparam T
 * @author Maxime Scharwath
 * @author Nicolas Crausaz
 */
template<typename T>
class SubstractionAbsOperation : public Operation<T> {
public:
    T execute(T a, T b) const override {
        return (a < b) ? b - a : a - b;
    }
};

#endif //LABO_1_SUBSTRATIONABSOPERATION_H
