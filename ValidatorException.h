#pragma once

#include <string>

class ValidatorException{
private:
    std::string error;
public:
    explicit ValidatorException(const std::string& err);
    std::string what() const;
};
