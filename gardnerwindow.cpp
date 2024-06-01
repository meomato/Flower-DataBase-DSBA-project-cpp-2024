#include "gardnerwindow.h"

GardnerWindow::GardnerWindow(QStringList flowNameList, QWidget *parent)
    : QWidget{parent}
{
    auth = new QSettings("auth", QSettings::IniFormat);
    setWindowTitle("Bloom Baze | Registration/Autorization");

    setFixedSize(200,150);

    mainLayout = new QGridLayout();
    setLayout(mainLayout);

    lb_login    = new QLabel("Enter name:");
    le_login    = new QLineEdit();
    lb_password = new QLabel("Enter password:");
    le_password = new QLineEdit();
    pb_access   = new QPushButton("Log in");
    pb_access->setEnabled(false);
    connect(le_login, &QLineEdit::textChanged, this, [&](QString text){
        if(!text.size())
            pb_access->setEnabled(false);
        else
            pb_access->setEnabled(true);
    });

    pb_exit = new QPushButton("Close");

    mainLayout->addWidget(lb_login,0,0,1,2);
    mainLayout->addWidget(le_login,1,0,1,2);
    mainLayout->addWidget(lb_password,2,0,1,2);
    mainLayout->addWidget(le_password,3,0,1,2);
    mainLayout->addWidget(pb_access,4,0);
    mainLayout->addWidget(pb_exit,4,1);
}


