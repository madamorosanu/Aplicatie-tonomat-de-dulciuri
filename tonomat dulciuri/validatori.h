#ifndef UNTITLED_VALIDATORI_H
#define UNTITLED_VALIDATORI_H
#include "exceptii.h"
#include <string>
#include "entitate.h"

template<typename T>
class ValidatorTonomat {
public:
    static void validateProduct(const T& produs);
};


#endif //UNTITLED_VALIDATORI_H
