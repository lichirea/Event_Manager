//
// Created by vibii on 09/05/2021.
//

#include "Validator.h"

void Validator::checkAttendance(int attendance) {
    if(attendance < 0) throw ValidatorException("Attendance can't be negative!");
}

void Validator::checkLink(std::string link) {
    if(link.find_first_of('.') == -1) throw ValidatorException("Invalid link");
}

void Validator::checkTime(int time) {
    if(time < 1000000 || time > 99999999) throw ValidatorException("Invalid time");
}

void Validator::checkText(std::string title, std::string desc) {
    if(title.empty() || desc.empty()) throw ValidatorException("Title or description can't be empty!");
}


void Validator::check(Event *e) {
    checkAttendance(e->getAttendees());
    checkLink(e->getLink());
    checkTime(e->getTime());
    checkText(e->getTitle(), e->getDesc());
}
