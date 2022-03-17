#pragma once

#include <exception>
#include <string>

class RepoException : public std::exception{
private:
    std::string error;
public:
    explicit RepoException(const std::string& err);
    std::string what();
};