#include "UI.h"
#include <iostream>
//#include <Windows.h>
//#include <shellapi.h>

void Console::start() {
    //Console::add_entries();
    std::cout << "\nADMIN (1) -- USER (2)\n";
    int n;
    std::cin >> n;
    if(n == 1) admin();
    else user();
}

void Console::user() {
    std::string type;
    std::cout << "CSV or HTML?\n";
    while(true){
        std::cin >> type;
        if(type == "CSV"){
            break;
        }
        if(type == "HTML"){
            break;
        }
        std::cout << "Invalid type, try again\n";
    }

    service local("txt", type);
    this->s = &local;
    this->s->read();

    bool done = false;
    while (!done) {
        try {
            char command = menu2();
            if(command == 'x'){
                done = true;
            }
            else if(command == '1'){
                int m;
                std::cout << "Month (0 for all months): \n";
                while(true) {
                    if (!(std::cin >> m)) {
                        std::cin.clear();
                        std::cin.ignore();
                        std::cout << "Incorrect type. Try again:\n";
                    }
                    else break;
                }
                bool done2 = false; int number = 0;
                while(!done2) {
                    try{
                        for (int i = 0; i < this->s->getLength(); i++) {
                            std::string p = s->list(i, m);
                            if (!p.empty()) {
                                number++;
                                std::cout <<"\n" << p << "\n" << "Attend this event? Y to attend; X for exit; anything else for next\n";
                                //ShellExecuteA(NULL, NULL, "edge.exe", reinterpret_cast<LPCSTR>(p.find_last_of(' ')), NULL, SW_SHOWMAXIMIZED);
                                char c;
                                std::cin >> c;
                                if (c == 'Y' || c == 'y') {
                                    s->attend(i);
                                }
                                if (c == 'X' || c == 'x') {
                                    done2 = true;
                                    break;
                                }
                            }
                        }
                        if(number == 0){
                            done2 = true;
                            std::cout<<"No events that month\n";
                        }
                    }catch (ServiceException& se){
                        std::cout<< se.what() <<"\n";
                    }
                }
            }
            else if(command == '2'){
                for(int i = 0; i < this->s->getLength2(); i++){
                    std::cout << s->listuser(i, 0) << "\n";
                }
            }
            else if(command == '3'){
                std::string o; std::string title; int time;
                std::cout << "Title\n";
                std::getline(std::cin, o); std::getline(std::cin, title);
                std::cout << "Time (DDMMYYHH)\n";
                while(true) {
                    if (!(std::cin >> time)) {
                        std::cin.clear();
                        std::cin.ignore();
                        std::cout << "Incorrect type. Try again:\n";
                    }
                    else break;
                }
                s->deluser(title, time);
            }
            else if(command == '4'){
                this->s->writeUser();
                this->s->openUser();
            }
        }
        catch (ServiceException& se){
            std::cout << se.what() <<"\n";
        }
    }
    this->s->writeUser();
}

void Console::admin() {

    service local("txt", "");
    this->s = &local;
    s->read();

    bool done = false;
    while(!done){
        try{
            char command = menu();
            if(command == 'x'){
                done = true;
            }
            else if(command == '1'){
                for(int i = 0; i < this->s->getLength(); i++){
                    std::cout << s->list(i, 0) << "\n";
                }
            }
            else if(command == '2'){
                std::string o; std::string title; std::string description; int time; int attendees; std::string link;

                std::cout << "Title\n";
                std::getline(std::cin, o);  std::getline(std::cin, title);
                std::cout << "Description\n";
                std::getline(std::cin, description);
                std::cout << "Time (DDMMYYHH)\n";
                while(true) {
                    if (!(std::cin >> time)) {
                        std::cin.clear();
                        std::cin.ignore();
                        std::cout << "Incorrect type. Try again:\n";
                    }
                    else break;
                }
                std::cout << "Attendees\n";
                while(true) {
                    if (!(std::cin >> attendees)) {
                        std::cin.clear();
                        std::cin.ignore();
                        std::cout << "Incorrect type. Try again:\n";
                    }
                    else break;
                }
                std::cout << "Link\n";
                std::cin >> link;

                s->add(title, description, time, attendees, link);
            }
            else if(command == '3'){
                std::string o; std::string title; std::string description; int time; int attendees; std::string link;

                std::cout << "Title\n";
                std::getline(std::cin, o);  std::getline(std::cin, title);
                std::cout << "Description\n";
                std::getline(std::cin, description);
                std::cout << "Time (DDMMYYHH)\n";
                while(true) {
                    if (!(std::cin >> time)) {
                        std::cin.clear();
                        std::cin.ignore();
                        std::cout << "Incorrect type. Try again:\n";
                    }
                    else break;
                }
                std::cout << "Attendees\n";
                while(true) {
                    if (!(std::cin >> attendees)) {
                        std::cin.clear();
                        std::cin.ignore();
                        std::cout << "Incorrect type. Try again:\n";
                    }
                    else break;
                }
                std::cout << "Link\n";
                std::cin >> link;

                s->update(title, description, time, attendees, link);
            }
            else if(command == '4'){
                std::string o; std::string title; int time;
                std::cout << "Title\n";
                std::getline(std::cin, o); std::getline(std::cin, title);
                std::cout << "Time (DDMMYYHH)\n";
                while(true) {
                    if (!(std::cin >> time)) {
                        std::cin.clear();
                        std::cin.ignore();
                        std::cout << "Incorrect type. Try again:\n";
                    }
                    else break;
                }

                s->del(title, time);
            }
        }
        catch (RepoException& re){
            std::cout << re.what() <<"\n";
        }
        catch (ValidatorException& ve){
            std::cout << ve.what() << "\n";
        }
    }
    s->write();
}

char Console::menu() {
    char c;
    std::cout << "1.List all events \n2.Add event\n3.Update event"
                 "\n4.Delete event\nx.Exit\n>>>";
    std::cin >> c;
    return c;
}

char Console::menu2() {
    char c;
    std::cout << "\n1.Choose events\n2.List events that I'm going to\n3.Delete an event from my list\n4.Open list\nx.Exit\n";
    std::cin >> c;
    return c;
}

void Console::add_entries() {
//    s.add("Party", "AWESOME PARTY", 21012018, 9001, "party.com");
//    s.add("Birthday", "Someone's birthday", 25012018, 5, "whydoihaveasite.com");
//    s.add("Circus", "It's a circus with lions", 15022012, 300, "defaultcircus.com");
//    s.add("John's Birthday", "This time it's John's", 11022020, 6, "johnjohn.nz");
//    s.add("Nothing Special", "I'm running out of jokes", 17122013, 1, "hopa.ro");
//    s.add("Resizing", "This event made me double my capacity", 22022022, 2, "doubletrouble.org");
//    s.add("Not a circus", "It's a circus without lions", 16022013, 2, "notacircus.org");
//    s.add("Resizing2:Electric Boogaloo", "This event made me double my TWICE", 22022222, 2, "doubletrouble.org");
//    s.add("Something special", "Everyone gets a McNuke", 12121212, 999999999, "2012.net");
//    s.add("One Piece Marathon", "We watch all of it", 22079724, 1000000, "world.gov");
//    s.add("Doctor Training", "Learn surgery for free! No takesy-backsies", 11105015, 5, "trafalgar.law");
}
