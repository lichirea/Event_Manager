#pragma once

#include <string>
#include <qwidget.h>
#include <QApplication>
#include <QWidget>
#include <QLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QString>
#include <QListWidget>
#include <QListWidgetItem>
#include <vector>
#include "Domain.h"
#include "FileRepo.h"
#include "Service.h"
#include <QErrorMessage>
#include <QRadioButton>

typedef Event TElem;


class AdminWidget: public QWidget{
    Q_OBJECT
public:
    explicit AdminWidget(QWidget* parent);
private:
    service* s;
    std::vector<TElem> v;
    QErrorMessage* q;
    QListWidget* eventList;
    QLabel* titleLabel;
    QLabel* descLabel;
    QLabel* timeLabel;
    QLabel* attendeeLabel;
    QLabel* linkLabel;
    QLineEdit* title;
    QLineEdit* desc;
    QLineEdit* time;
    QLineEdit* attendee;
    QLineEdit* link;
    QPushButton* addButton;
    QPushButton* updateButton;
    QPushButton* deleteButton;

    void populateEventList();
    void listItemChanged();
    int getSelectedIndex();

signals:
    void EventsUpdatedSignal();
    void addEventSignal(std::string title, std::string description,
                        int time, int attendees, std::string link);
    void updateEventSignal(std::string title, std::string description,
                           int time, int attendees, std::string link);
    void deleteEventSignal(std::string title,
                           int time);
public slots:
    void addEventButtonHandler();
    void addEvent(std::string title, std::string description,
                  int time, int attendees, std::string link);
    void updateEventButtonHandler();
    void updateEvent(std::string title, std::string description,
                     int time, int attendees, std::string link);
    void deleteEventButtonHandler();
    void deleteEvent(const std::string& title,
                           int time);
};


class UserWidget: public QWidget{
    Q_OBJECT
private:
    QListWidget* eventList;
    QLabel*  current;
    QPushButton* add;
    QPushButton* next;
    QPushButton* del;
public:
    std::string filetype;
    explicit UserWidget(QWidget* parent);
};


class LoginWidget: public QWidget{
    Q_OBJECT
public:
    explicit LoginWidget(QWidget* parent);
private:
    QErrorMessage* e;
    QLabel* adminLabel;
    QPushButton* admin;
    QPushButton* user;
    QLineEdit* passwd;
    QRadioButton* csv;
    QRadioButton* html;
    QWidget* buttons;
signals:
    void startAdminSignal(QString& password);
    void startUserSignal(std::string filetype);
private slots:
    void adminButtonHandler();
    void userButtonHandler();
};


class Interface : public QWidget{
    Q_OBJECT
private:
    QErrorMessage* e;
    LoginWidget* login;
    AdminWidget* admin;
    UserWidget* user;
    service* s;
public slots:
    void startAdmin(QString& password);
    void startUser(std::string filetype);
public:
    explicit Interface(QWidget* parent = nullptr);
    ~Interface();
};

