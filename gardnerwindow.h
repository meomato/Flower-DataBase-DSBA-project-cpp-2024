#ifndef GARDNERWINDOW_H
#define GARDNERWINDOW_H

#include <QWidget>
#include <QSettings>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QMessageBox>
#include <QFile>
#include <QTableWidget>
#include <QDateTimeEdit>
#include <QComboBox>
#include "flowercontainer.h"

class GardnerWindow : public QWidget
{
    Q_OBJECT
public:
    explicit GardnerWindow(QStringList flowNameList, QWidget *parent = nullptr);
private:
    QSettings *auth{};

    QLabel *lb_login{};
    QLineEdit *le_login{};
    QLabel *lb_password{};
    QLineEdit *le_password{};
    QPushButton *pb_access{};
    QPushButton *pb_exit{};

    QGridLayout *mainLayout{};

};

#endif // GARDNERWINDOW_H
