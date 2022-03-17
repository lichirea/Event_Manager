#include "RepoException.h"

RepoException::RepoException(const std::string &err) {
    this->error = err;
}

std::string RepoException::what() {
    return this->error;
}
