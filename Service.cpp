#include "Service.h"
#include <iostream>


void service::add(std::string title, std::string description, int time, int attendees, std::string link) {
    TElement e{std::move(title), std::move(description), time, attendees, std::move(link)};
    Validator::check(&e);
    r.add(e);
}

void service::update(std::string& title, std::string& description, int time, int attendees,  std::string& link) {
    TElement e{std::move(title), std::move(description), time, attendees, std::move(link)};
    Validator::check(&e);
    r.update(e);
}

void service::del(const std::string& title, int time) {
    TElement e{title, "0", time, 0, "0.0"};
    r.del(e);
}

int service::getLength() {
    return this->r.getLength();
}

std::string service::list(int pos, int m) {
    return this->r.toString(pos, m);
}

std::string service::listuser(int pos, int m) {
    return this->user.toString(pos, m);
}

void service::attend(int pos) {
    TElement old = this->r.getElement(pos);
    TElement n{old};
    try{
        user.add(n);
        r.addattendee(pos);
    }catch (RepoException& re){
        throw ServiceException("Already attending this event");
    }
}

int service::getLength2() {
    return this->user.getLength();
}

void service::deluser(std::string title, int time) {
    TElement e{std::move(title), "0", time, 0, "0.0"};
    int pos = r.getPos(e);
    try{
        user.del(e);
        r.removeattendee(pos);
    }catch (RepoException& re){
        throw ServiceException("Not attending this event");
    }
}

service::service(const std::string &typeAdmin, const std::string& typeUser) {
    if(typeAdmin == "txt"){
        auto* a = new FileText;
        this->A = a;
    }
    if(typeUser == "HTML"){
        auto* u = new FileHTML;
        this->U = u;
    }
    if(typeUser == "CSV"){
        auto* u = new FileCSV;
        this->U = u;
    }
}

void service::read() {
    A->read(r);
}

void service::write() {
    A->write(r);
}

void service::openUser() {
    U->open();
}

void service::writeUser() {
    U->write(this->user);
}

TElement service::getElem(int i) {
    TElement local{this->r.getElement(i)};
    return local;
}
