#include <iostream>
#include "Tests.h"
#include "UI.h"
#include "Interface.h"
#include <iostream>

int main(int argc, char* argv[]){
    std::cout << "Hello!!!! ";

    tests::domaintests();
    tests::repotests();
    tests::servicetests();

    QApplication a(argc, argv);
    auto* i = new Interface;
    return a.exec();
//    {
//        Console c;
//        c.start();
//    }
}
