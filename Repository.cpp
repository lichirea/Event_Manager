#include "Repository.h"

void repo::add(const Event &e) {
    if(!checkUnique(e)) throw RepoException("Element not unique!");
    this->dv.push_back(e);
    std::sort(this->dv.begin(), this->dv.end(), compare);
}

void repo::update(Event& e) {
    for(auto& i : this->dv){
        if(i == e){
            i = e;
            std::sort(this->dv.begin(), this->dv.end(), compare);
            return;
        }
    }
    throw RepoException("No such event in database!");
}

std::string repo::toString(int i, int m) {
    if(this->dv[i].getTime()/10000%100 == m || m == 0) return this->dv[i].toString();
    return std::string{""};
}

void repo::del(TElement& e) {
    for(auto i : this->dv){
        if(e == i){
            auto position = std::find(this->dv.begin(), this->dv.end(), e);
            this->dv.erase(position);
            std::sort(this->dv.begin(), this->dv.end(), compare);
            return;
        }
    }
    throw RepoException("No such event in database!");
}

int repo::getLength() {
    return this->dv.size();
}

TElement repo::getElement(int i) {
    return this->dv[i];
}

void repo::addattendee(int i) {
    this->dv[i].addattendee();
}

void repo::removeattendee(int i){
    this->dv[i].removeattendee();
}

int repo::getPos(const TElement& event) {
    for(int i = 0; i < getLength(); i++){
        if(dv[i] == event){
            return i;
        }
    }
    return -1;
}

bool repo::compare(TElement e1, TElement e2) {
    return Event::compare(e1, e2);
}

bool repo::checkUnique(TElement e) {
    return std::all_of(this->dv.begin(), this->dv.end(), [e](TElement i){if(i == e) return false; return true;});
}
