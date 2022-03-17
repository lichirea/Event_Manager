#pragma once

#include "Service.h"

class Console{
private:
    service* s;
public:
    void add_entries();

    void start();

    static char menu();

    void admin();

    void user();

    static char menu2();
};