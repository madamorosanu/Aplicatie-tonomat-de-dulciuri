#include "validatori.h"

template<typename T>
void ValidatorTonomat<T>::validateProduct(const T& produs) {
    if (produs.getName().empty()) {
        throw ValidareException("Numele produsului nu poate fi nul.");
    }
    if (produs.getPrice() <= 0) {
        throw ValidareException("Pretul produsului trebuie sa fie mai mare ca 0.");
    }
    if (produs.getCod() == 000) {
        throw ValidareException("Codul produsului nu poate fi nul.");
    }
}
