//
// Created by vibii on 10/05/2021.
//

#include "ServiceException.h"

ServiceException::ServiceException(const std::string &err) {
    this->error = err;
}

std::string ServiceException::what() {
    return this->error;
}
