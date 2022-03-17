#pragma once

#include <exception>
#include <string>


class ServiceException : public std::exception {
private:
    std::string error;
public:
    explicit ServiceException(const std::string& error);
    std::string what();
};
