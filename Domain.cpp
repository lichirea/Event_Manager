
#include "Domain.h"


Event::Event() {
    this->title = "0";
    this->description = "0";
    this->time = 0;
    this->link = "0";
    this->attendees = 0;
}

Event::Event(std::string title, std::string description, int time, int attendees, std::string link){
    this->title = std::move(title);
    this->description = std::move(description);
    this->time = time;
    this->link = std::move(link);
    this->attendees = attendees;
}

Event::Event(const Event &e) {
    this->title = e.title;
    this->description = e.description;
    this->time = e.time;
    this->link = e.link;
    this->attendees = e.attendees;
}

bool Event::operator==(const Event &e) {
    if(e.time != this->time) return false;
    if(e.title != this->title) return false;
    return true;
}


std::string Event::getTitle() const{
    return this->title;
}

std::string Event::getDesc() const{
    return this->description;
}

int Event::getTime() const{
    return this->time;
}

int Event::getAttendees() const{
    return this->attendees;
}

std::string Event::getLink() const{
    return this->link;
}

std::string Event::toString() {
    if(this->time/10000%100 < 10){
        return std::string(this->title + "~ " + this->description + "; Time:" + std::to_string(this->time/1000000) + ".0" +
       std::to_string(this->time/10000%100) + "." + std::to_string(this->time/100%100) + " at " + std::to_string(this->time%100)
       + ":00 Attendees: " + std::to_string(this->attendees) + " " + this->link);
    }
    return std::string(this->title + "~ " + this->description + "; Time:" + std::to_string(this->time/1000000) + "." +
    std::to_string(this->time/10000%100) + "." + std::to_string(this->time/100%100) + " at " + std::to_string(this->time%100)
    + ":00 Attendees: " + std::to_string(this->attendees) + " " + this->link);
}

std::string Event::toStringSimple(){
    std::string result = this->getTitle() + ";" + this->getDesc() + ";" + std::to_string(this->getTime()) + ";" +
           std::to_string(this->getAttendees()) + ";" + this->getLink();
    return result;
}

void Event::addattendee() {
    this->attendees++;
}

void Event::removeattendee() {
    this->attendees--;
}

bool Event::compare(Event &e1, Event &e2) {
    int t1 = e1.getTime(); int t2 = e2.getTime();
    int y1 = t1/100%100; int y2 = t2/100%100;
    int m1 = t1/10000%100; int m2 = t2/10000%100;
    int d1 = t1/1000000; int d2 = t2/1000000;
    int h1 = t1%100; int h2 = t2%100;
    if(y1 > y2) return true;
    else if(y1 == y2 && m1 > m2) return true;
    else if(y1 == y2 && m1 == m2 && d1 > d2) return true;
    else if(y1 == y2 && m1 == m2 && d1 == d2 && h1 > h2) return true;
    return false;
}

std::ostream &operator<<(std::ostream &output, const Event &e) {
    output << e.getTitle() << std::endl << e.getDesc() << std::endl << e.getTime() << std::endl
    << e.getAttendees() << std::endl << e.getLink();
    return output;
}

std::istream &operator>>(std::istream &input, Event &e) {
    std::getline(input, e.title);
    std::getline(input, e.description);
    input >> e.time;
    input >> e.attendees;
    std::string nothing;
    std::getline(input, nothing);
    std::getline(input, e.link);
    return input;
}