#pragma  once

#include "Repository.h"
#include <Windows.h>
#include <shellapi.h>
#include <unistd.h>

class FileAdmin {
public:
    virtual void read(repo& r)=0;

    virtual void write(repo& r)=0;

};

class FileText: public FileAdmin {
public:
    void read(repo& r) override;

    void write(repo& r) override;
};

class FileUser {
public:
    virtual void write(repo& r)=0;

    virtual void open()=0;

};


class FileHTML: public FileUser {
public:
    void open() override;

    void write(repo& r) override;
};

class FileCSV: public FileUser {
public:
    void open() override;

    void write(repo& r) override;
};
