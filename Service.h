#pragma once

#include "Repository.h"
#include "Domain.h"
#include "FileRepo.h"
#include "Validator.h"
#include "ServiceException.h"

class service{
private:
    repo r;
    repo user;
    FileAdmin* A;
    FileUser* U;
public:

    explicit service(const std::string& typeAdmin, const std::string& typeUser);

    void read();

    void write();

    void openUser();

    void writeUser();

    TElement getElem(int pos);

    void add(std::string title, std::string description, int time, int attendees, std::string link);
    // creates object and validates it, then calls repo

    int getLength();
    // calls repo function that returns length of the main repo

    int getLength2();
    // returns length of the user repo

    std::string list(int pos, int m);
    // calls repo function that returns formatted strings for all elements

    std::string listuser(int pos, int m);
    // calls user repo functions that returns formatted strings

    void update(std::string& title, std::string& description, int time, int attendees,  std::string& link);
    // creates objects and validates it, then calls repo

    void del(const std::string& basicString, int i);
    // calls repo function for deleting, has nothing to validate

    void attend(int pos);
    // attend the event at position pos in the repo to the user repo

    void deluser(std::string basicString, int i);
    // deletes the event from the user repo
};
