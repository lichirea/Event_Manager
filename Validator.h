#pragma once

#include <string>
#include "Domain.h"
#include "ValidatorException.h"

class Validator {
public:
    static void checkAttendance(int attendance);
    static void checkLink(std::string link);
    static void checkTime(int time);
    static void checkText(std::string title, std::string desc);
    static void check(Event* e);
};
