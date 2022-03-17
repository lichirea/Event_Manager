#include "ValidatorException.h"


ValidatorException::ValidatorException(const std::string &err) {
    this->error = err;
}

std::string ValidatorException::what() const {
    return this->error;
}
