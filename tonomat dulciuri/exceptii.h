#ifndef UNTITLED_EXCEPTII_H
#define UNTITLED_EXCEPTII_H
#include <stdexcept>
#include <string>


class Exceptie : public std::runtime_error {
public:
    Exceptie(const std::string& message) : std::runtime_error(message) {}
};

class ValidareException : public Exceptie {
public:
    ValidareException(const std::string& message) : Exceptie(message) {}
};

class StocInsuficientException : public Exceptie {
public:
    StocInsuficientException(const std::string& message) : Exceptie(message) {}
};

class RestInsuficientException : public Exceptie {
public:
    RestInsuficientException(const std::string& message) : Exceptie(message) {}
};
#endif //UNTITLED_EXCEPTII_H
