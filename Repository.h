#pragma once

#include <exception>
#include <vector>
#include "Domain.h"
#include <algorithm>
#include "RepoException.h"

typedef Event TElement;
class repo{
private:
    std::vector<TElement> dv;

public:

    void add(const TElement& e);
    // adds element if it is unique

    void update(TElement& e);
    // updates element with matching time and title

    void del(TElement& e);
    // deletes element with matching time and title

    int getLength();
    // returns length

    std::string toString(int i, int i1);
    // return formatted string of element at pos i

    TElement getElement(int i);
    // returns the elements at position i

    void addattendee(int i);
    // attendees++

    void removeattendee(int i);
    // attendees--

    int getPos(const TElement& event);
    // returns the positions of the given event in the vector

    static bool compare(TElement e1, TElement e2);
    // returns true if element e1 is greater than e2 (calls a domain function)

    bool checkUnique(TElement e);
};


