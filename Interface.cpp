#include "Interface.h"

#include <utility>
#include <iostream>



Interface::Interface(QWidget *parent) : QWidget{parent}{
    this->login = new LoginWidget(this);
    this->show();

    this->admin = new AdminWidget(this);

    this->user = new UserWidget(this);
}

void Interface::startAdmin(QString &password) {
    if(password == "admin"){
        this->login->close();
        this->admin->show();
    }
    else{
        e = new QErrorMessage;
        e->showMessage("Invalid password!");

    }
}

void Interface::startUser(std::string filetype) {
    this->login->close();
    this->user->filetype = std::move(filetype);
    this->user->show();
}

Interface::~Interface() = default;


LoginWidget::LoginWidget(QWidget* parent){
    this->setParent(parent);
    auto* hLayout = new QVBoxLayout{this};

    this->adminLabel = new QLabel("Enter password to login as Admin:");
    this->passwd = new QLineEdit;
    this->adminLabel->setBuddy(this->passwd);
    hLayout->addWidget(this->adminLabel);
    hLayout->addWidget(this->passwd);

    this->admin = new QPushButton("Login as &Admin");
    hLayout->addWidget(this->admin);

    this->user = new QPushButton("Login as &User");
    hLayout->addWidget(this->user);


    buttons = new QWidget;
    auto* radioLayout = new QHBoxLayout{buttons};
    this->csv = new QRadioButton("CSV");
    this->html = new QRadioButton("HTML");
    radioLayout->addWidget(csv);
    radioLayout->addWidget(html);

    hLayout->addWidget(buttons);


    // connecting signals and slots
    QObject::connect(this->admin, &QPushButton::clicked, this, &LoginWidget::adminButtonHandler);
    QObject::connect(this->user, &QPushButton::clicked, this, &LoginWidget::userButtonHandler);

    QObject::connect(this, SIGNAL(startAdminSignal(QString&)), this->parentWidget(), SLOT(startAdmin(QString&)));
    QObject::connect(this, SIGNAL(startUserSignal(std::string)), this->parentWidget(), SLOT(startUser(std::string)));

}

void LoginWidget::adminButtonHandler() {
    QString password = this->passwd->text();
    emit startAdminSignal(password);
}

void LoginWidget::userButtonHandler() {
    std::string filetype;
    if(csv->isChecked()){
        filetype = csv->text().toStdString();
    }
    else{
        filetype = html->text().toStdString();
    }
    emit startUserSignal(filetype);
}

AdminWidget::AdminWidget(QWidget *parent) {
    this->setParent(parent);
    this->s = new service("txt", "");
    auto* layout = new QHBoxLayout{ this };
    s->read();

    q = new QErrorMessage;

    this->eventList = new QListWidget{};
    this->eventList->setSelectionMode(QAbstractItemView::SingleSelection);
    layout->addWidget(this->eventList);


    //right side of window, input area for add and update as 2 rows
    auto* rightSide = new QWidget;
    auto* rightLayout = new QHBoxLayout{rightSide};
    auto* fields = new QWidget;
    auto* fieldsLayout = new QVBoxLayout{fields};
    auto* buttons = new QWidget;
    auto* buttonsLayout = new QVBoxLayout{buttons};

    //fields
    this->titleLabel = new QLabel("Title:");
    this->title = new QLineEdit;
    this->titleLabel->setBuddy(this->title);
    fieldsLayout->addWidget(this->titleLabel);
    fieldsLayout->addWidget(this->title);

    this->descLabel = new QLabel("Description:");
    this->desc = new QLineEdit;
    this->descLabel->setBuddy(this->desc);
    fieldsLayout->addWidget(this->descLabel);
    fieldsLayout->addWidget(this->desc);

    this->timeLabel = new QLabel("Time:");
    this->time = new QLineEdit;
    this->timeLabel->setBuddy(this->time);
    fieldsLayout->addWidget(this->timeLabel);
    fieldsLayout->addWidget(this->time);

    this->attendeeLabel = new QLabel("Attendees:");
    this->attendee = new QLineEdit;
    this->attendeeLabel->setBuddy(this->attendee);
    fieldsLayout->addWidget(this->attendeeLabel);
    fieldsLayout->addWidget(this->attendee);

    this->linkLabel = new QLabel("Link:");
    this->link = new QLineEdit;
    this->linkLabel->setBuddy(this->link);
    fieldsLayout->addWidget(this->linkLabel);
    fieldsLayout->addWidget(this->link);

    //buttons
    this->addButton = new QPushButton("Add Event");
    this->updateButton = new QPushButton("Update Event");
    this->deleteButton = new QPushButton("Delete Event");
    buttonsLayout->addWidget(this->addButton);
    buttonsLayout->addWidget(this->updateButton);
    buttonsLayout->addWidget(this->deleteButton);

    //add everything to the parent layout
    rightLayout->addWidget(fields);
    rightLayout->addWidget(buttons);
    layout->addWidget(rightSide);


    //connections
    //buttons
    QObject::connect(this, &AdminWidget::EventsUpdatedSignal, this, &AdminWidget::populateEventList);
    QObject::connect(this->eventList, &QListWidget::itemSelectionChanged, this, [this]() {this->listItemChanged(); });

    QObject::connect(this->addButton, &QPushButton::clicked, this, &AdminWidget::addEventButtonHandler);
    QObject::connect(this->updateButton, &QPushButton::clicked, this, &AdminWidget::updateEventButtonHandler);
    QObject::connect(this->deleteButton, &QPushButton::clicked, this, &AdminWidget::deleteEventButtonHandler);


    QObject::connect(this, SIGNAL(addEventSignal(std::string, std::string,
                                    int, int, std::string)),
                     this, SLOT(addEvent(std::string, std::string,
                                    int, int, std::string)));
    QObject::connect(this, SIGNAL(updateEventSignal(std::string, std::string,
                                                 int, int, std::string)),
                     this, SLOT(updateEvent(std::string, std::string,
                                         int, int, std::string)));
    QObject::connect(this, SIGNAL(deleteEventSignal(std::string, int)),
                     this, SLOT(deleteEvent(std::string,  int)));

    populateEventList();
}

void AdminWidget::populateEventList() {
    if (this->eventList->count() > 0)
        this->eventList->clear();

    for (int i = 0; i < this->s->getLength(); i++)
    {
        TElem g = this->s->getElem(i);
        QString itemInList = QString::fromStdString(g.getTitle() + " - " + g.getDesc() + " - " +
                std::to_string(g.getTime()) + " - " + std::to_string(g.getAttendees()) + " - " + g.getLink());
        QFont f{ "Verdana", 15 };
        auto* item = new QListWidgetItem{ itemInList };
        item->setFont(f);
        this->eventList->addItem(item);
    }

    // set the selection on the first item in the list
    if (this->s->getLength() > 0)
        this->eventList->setCurrentRow(0);
}

void AdminWidget::listItemChanged() {
    std::cout<<"CHANGED\n";
    int idx = this->getSelectedIndex();
    if (idx == -1)
        return;

    // get the item at the selected index
    if (idx >= this->s->getLength())
        return;
    std::cout<<"CHANGED11111\n";
    TElem g = this->s->getElem(idx);
    std::cout<<"CHANGED22222\n";
    std::cout << g.toStringSimple();

    this->title->setText(QString::fromStdString(g.getTitle()));
    this->desc->setText(QString::fromStdString(g.getDesc()));
    this->time->setText(QString::fromStdString(std::to_string(g.getTime())));
    this->attendee->setText(QString::fromStdString(std::to_string(g.getAttendees())));
    this->link->setText(QString::fromStdString(g.getLink()));
}

int AdminWidget::getSelectedIndex() {
    if (this->eventList->count() == 0)
        return -1;

    // get selected index
    QModelIndexList index = this->eventList->selectionModel()->selectedIndexes();
    if (index.size() == 0)
    {
        this->title->clear();
        this->time->clear();
        this->desc->clear();
        this->link->clear();
        this->attendee->clear();
        return -1;
    }

    int idx = index.at(0).row();
    return idx;
}

void AdminWidget::addEventButtonHandler() {
    QString t = this->title->text();
    QString d = this->desc->text();
    QString tm = this->time->text();
    QString a = this->attendee->text();
    QString l = this->link->text();

    emit addEventSignal(t.toStdString(), d.toStdString(), tm.toInt(), a.toInt(), l.toStdString());
}

void AdminWidget::addEvent(std::string title, std::string description, int time, int attendees, std::string link) {
    try{
        this->s->add(std::move(title), std::move(description), time, attendees, std::move(link));
    }
    catch(...){
        q->showMessage("Error!");
    }
    emit EventsUpdatedSignal();
}

void AdminWidget::updateEventButtonHandler() {
    QString t = this->title->text();
    QString d = this->desc->text();
    QString tm = this->time->text();
    QString a = this->attendee->text();
    QString l = this->link->text();

    emit updateEventSignal(t.toStdString(), d.toStdString(), tm.toInt(), a.toInt(), l.toStdString());

}

void AdminWidget::updateEvent(std::string title, std::string description, int time, int attendees, std::string link) {
    try{
        this->s->update(title, description, time, attendees, link);
    }
    catch(...){
        q->showMessage("Error!");
    }
    emit EventsUpdatedSignal();
}

void AdminWidget::deleteEventButtonHandler() {
    QString t = this->title->text();
    QString tm = this->time->text();

    emit deleteEventSignal(t.toStdString(),tm.toInt());

}

void AdminWidget::deleteEvent(const std::string& title, int time) {
    try{
        this->s->del(title,  time);
    }
    catch(...){
        q->showMessage("Error!");
    }
    emit EventsUpdatedSignal();
}

UserWidget::UserWidget(QWidget *parent) {
    this->setParent(parent);

    auto layout = new QVBoxLayout(this);
    eventList = new QListWidget;
    layout->addWidget(eventList);

    current = new QLabel("Nothing selected yet");
    layout->addWidget(current);

    add = new QPushButton("Add");
    next = new QPushButton("Next");
    del = new QPushButton("Del");
    layout->addWidget(add);
    layout->addWidget(next);
    layout->addWidget(del);
}
