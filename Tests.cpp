#include "Tests.h"
#include "Domain.h"
#include "Repository.h"
#include "Service.h"
#include <cassert>

void tests::domaintests(){
    Event e("Party", "AWESOME PARTY", 21012018, 9001, "party.com");
    Event copy{"0", "1", 21111118, 3, "4"};
    Event copy2{"0", "1", 21111118, 3, "4"};
    assert(e.getTitle() == "Party");
    assert(e.getDesc() ==  "AWESOME PARTY");
    assert(e.getTime() == 21012018);
    assert(e.getLink() == "party.com");
    assert(e.getAttendees() == 9001);
    e.addattendee();
    assert(e.getAttendees() == 9002);
    e.removeattendee();
    assert(e.getAttendees() == 9001);
    copy = e;
    Event a{copy};
    assert(copy.getTitle() == "Party");
    assert(a.getTitle() == "Party");
    std::string s = e.toString();
    std::string p = copy2.toString();
}

void tests::repotests(){
    repo r;
    assert(r.getLength() == 0);
    Event w("Party", "AWESOME PARTY", 21012018, 9001, "party.com");
    r.add(w);
    assert((Event) r.getElement(0) == w);
    r.addattendee(0);
    r.removeattendee(0);
    r.add(Event("Birthday", "Someone's birthday", 25012018, 5, "whydoihaveasite.com"));
    r.add(Event("Circus", "It's a circus with lions", 15022012, 300, "defaultcircus.com"));
    r.add(Event("John's Birthday", "This time it's John's", 11022020, 6, "johnjohn.nz"));
    r.add(Event("Nothing Special", "I'm running out of jokes", 17122013, 1, "hopa.ro"));
    r.add(Event("Resizing", "This event made me double my capacity", 22022022, 2, "doubletrouble.org"));

    try{
        r.add(Event("Birthday", "Someone's birthday", 25012018, 5, "whydoihaveasite.com"));
        assert(false);
    }
    catch (const RepoException&){}
    try{
        Event b("irthday", "Someone's birthday", 25012018, 5, "whydoihaveasite.com");
        r.update(b);
        assert(false);
    }
    catch (const RepoException&){}
    try{
        Event b("irthday", "Someone's birthday", 25012018, 5, "whydoihaveasite.com");
        r.del(b);
        assert(false);
    }
    catch (const RepoException&){}
    Event b("irthday", "Someone's birthday", 25012018, 5, "whydoihaveasite.com");
    assert(r.getPos(b) == -1);
    std::string x = r.toString(0, 1);
    std::string x1 = r.toString(0, 2);
    assert(x.size() == 0);
    assert(x1.size() == 0);
    assert(r.getLength() == 6);
    assert(r.compare(w, w) == false);
}

void tests::servicetests() {
    service s("txt", "");
    s.add("Party", "AWESOME PARTY", 21012018, 9001, "party.com");
    s.add("Birthday", "Someone's birthday", 25012018, 5, "whydoihaveasite.com");
    assert(s.getLength() == 2);
    std::string s1 = "Party";
    std::string s2 = "a";
    std::string s3 = "a.a";
    std::string s4 = s.list(0, 0);
    s.update(s1, s2, 21012018, 9001, s3);
    s.del("Party", 21012018);
    assert(s.getLength() == 1);
    assert(s.getLength2() == 0);
    s.attend(0);
    try{
        s.attend(0);
        assert(false);
    }
    catch (const ServiceException&){}
    s4 = s.listuser(0, 0);
    assert(s.getLength2() == 1);
    s.deluser("Birthday",25012018);
    try{
        s.deluser("Party",21012018);
        assert(false);
    }
    catch (const ServiceException&){}
    assert(s.getLength2() == 0);
}