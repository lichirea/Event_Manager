#include "FileRepo.h"
#include <fstream>

using namespace std;
void FileText::read(repo &r) {
    ifstream file(R"(C:\Users\vibii\Documents\GitHub\a67-912-Chirea-Liviu\data.txt)");

    while(!file.eof()){
        TElement t;
        file >> t;
        r.add(t);
    }
    file.close();
}

void FileText::write(repo &r) {
    ofstream file(R"(C:\Users\vibii\Documents\GitHub\a67-912-Chirea-Liviu\data.txt)");
    file.clear();
    for(int i = 0; i < r.getLength(); i++){
        TElement k = r.getElement(i);
        if(i != 0) file << endl;
        file << k;
    }
}


void FileHTML::open() {
    ShellExecuteA(nullptr, nullptr,
                  R"(C:\Program Files (x86)\Microsoft\Edge\Application\msedge.exe)",
                  R"(C:\Users\vibii\Documents\GitHub\a67-912-Chirea-Liviu\userlist.html)",
                  nullptr, SW_SHOWMAXIMIZED);
}

void FileHTML::write(repo &r) {
    ofstream file(R"(C:\Users\vibii\Documents\GitHub\a67-912-Chirea-Liviu\userlist.html)");
    file.clear();

    file << "<!DOCTYPE html>" << std::endl;
    file << "<html>" << std::endl;
    file << "<head>" << std::endl;
    file << "<title>Events</title>" << std::endl;
    file << "</head>" << std::endl;
    file << "<body>" << std::endl;
    file << "<table border=\"1\">" << std::endl;

    file << "<tr>" << std::endl;
    file << "<td>" << "Title" << "</td>" << std::endl;
    file << "<td>" << "Description" << "</td>" << std::endl;
    file << "<td>" << "Time" << "</td>" << std::endl;
    file << "<td>" << "Attendees" << "</td>" << std::endl;
    file << "<td>" << "Link" << "</td>" << std::endl;
    file << "</tr>" << std::endl;

    for(int i = 0; i < r.getLength(); i++){
        TElement e = r.getElement(i);
        file << "<tr>" << std::endl;
        file << "<td>" << e.getTitle() << "</td>" << std::endl;
        file << "<td>" << e.getDesc() << "</td>" << std::endl;
        file << "<td>" << to_string(e.getTime()) << "</td>" << std::endl;
        file << "<td>" << to_string(e.getAttendees()) << "</td>" << std::endl;
        file << "<td><a href=\"" << e.getLink() << "\">Link<\a></td>" << std::endl;
        file << "</tr>" << std::endl;
    }
    file << "</table>" << std::endl;
    file << "</body>" << std::endl;
    file << "</html>" << std::endl;
    file.close();
}

void FileCSV::open() {
    ShellExecuteA(nullptr, nullptr,
                  R"(C:\Program Files (x86)\Notepad++\notepad++.exe)",
                  R"(C:\Users\vibii\Documents\GitHub\a67-912-Chirea-Liviu\userlist.csv)",
                  nullptr, SW_SHOWMAXIMIZED);
}

void FileCSV::write(repo &r) {
    ofstream file(R"(C:\Users\vibii\Documents\GitHub\a67-912-Chirea-Liviu\userlist.csv)");

    file.clear();
    for(int i = 0; i < r.getLength(); i++){
        TElement k = r.getElement(i);
        if(i != 0) file << endl;
        std::string s = k.toStringSimple();
        file << s;
    }

}
