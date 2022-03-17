#pragma once

#include <string>
#include <fstream>

class Event {
private:
    std::string title;
    std::string description;
    int time;
    int attendees;
    std::string link;

public:

    Event();

    Event(std::string title, std::string description, int time, int attendees, std::string link);
    // constructor

    Event(const Event &e);
    // copy constructor

    bool operator==(const Event &e);
    // == overload

    std::string getTitle() const;
    std::string getDesc() const;
    int getTime() const;
    int getAttendees() const;
    std::string getLink() const;
    //getters

    std::string toString();
    // returns a formatted string

    void addattendee();
    // attendees++

    void removeattendee();
    // attendees--

    static bool compare(Event &e1, Event &e2);
    // returns true if e1 happens earlier than e2

    friend std::ostream &operator<<( std::ostream &output, const Event &e );

    friend std::istream &operator>>( std::istream &input, Event &e );

    std::string toStringSimple();
};