#ifndef LABO_1_OPERATION_H
#define LABO_1_OPERATION_H


/**
 * Operation class
 * @brief The Operation class is the base class for all operations.
 * @tparam T
 * @author Maxime Scharwath
 * @author Nicolas Crausaz
 */
template<typename T>
class Operation {
public:
    /**
     * execute the operation
     * @param a - first operand
     * @param b - second operand
     * @return the result of the operation
     */
    virtual T execute(T a, T b) const = 0;
};


#endif //LABO_1_OPERATION_H
