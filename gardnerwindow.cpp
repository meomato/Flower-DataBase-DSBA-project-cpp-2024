#include "gardnerwindow.h"
#include <QMessageBox>

GardnerWindow::GardnerWindow(QStringList flowNameList, QWidget *parent)
    : QWidget{parent},
    flowNameList(flowNameList)
{
    auth = new QSettings("auth", QSettings::IniFormat);
    setWindowTitle("Bloom Baze | Registration/Authorization");
    setWindowIcon(QIcon(":/img/purple_flower_icon_transparent.ico"));

    setFixedSize(200,150);

    mainLayout = new QGridLayout();
    setLayout(mainLayout);

    lb_login    = new QLabel("Enter name:");
    le_login    = new QLineEdit();
    lb_password = new QLabel("Enter password:");
    le_password = new QLineEdit();
    pb_access   = new QPushButton("Log in");
    pb_access->setEnabled(false);
    connect(pb_access, &QPushButton::clicked, this, &GardnerWindow::showGardenerMain);
    connect(le_login, &QLineEdit::textChanged, this, [&](QString text){
        pb_access->setEnabled(!text.isEmpty());
    });

    pb_exit = new QPushButton("Close");
    connect(pb_exit, &QPushButton::clicked, this, &GardnerWindow::close);

    pb_logout = new QPushButton("Log out");
    pb_logout->setFixedSize(80, 30);
    pb_logout->hide();
    connect(pb_logout, &QPushButton::clicked, this, &GardnerWindow::logout);

    mainLayout->addWidget(lb_login,0,0,1,2);
    mainLayout->addWidget(le_login,1,0,1,2);
    mainLayout->addWidget(lb_password,2,0,1,2);
    mainLayout->addWidget(le_password,3,0,1,2);
    mainLayout->addWidget(pb_access,4,0);
    mainLayout->addWidget(pb_exit,4,1);
    mainLayout->addWidget(pb_logout,5,0,1,2);
}

void GardnerWindow::logout()
{
    setWindowTitle("Bloom Baze | Registration/Authorization");
    setWindowIcon(QIcon(":/img/purple_flower_icon_transparent.ico"));
    lb_login->show();
    le_login->show();
    lb_password->show();
    le_password->show();
    pb_access->show();
    pb_exit->show();
    pb_logout->hide();

    setFixedSize(200,150);

    twFlowers->hide();
    twNotes->hide();
    addFlowBtn->hide();
    addNoteBtn->hide();
}

void GardnerWindow::showGardenerMain()
{
    QSettings gardnerSettings(le_login->text(), QSettings::IniFormat);
    processAuth();
    hideAuthInterface();
    prepareFlowTable(gardnerSettings);
    prepareNotesTable(gardnerSettings);

    pb_logout->show();
}

bool GardnerWindow::openGardnerFile()
{
    QFile file(le_login->text());
    if (!file.open(QIODevice::WriteOnly))
    {
        qDebug() << "File opening error";
    }
    return true;
}

void GardnerWindow::hideAuthInterface()
{
    setWindowTitle("Bloom Baze | Your profile");
    lb_login->hide();
    le_login->hide();
    lb_password->hide();
    le_password->hide();
    pb_access->hide();
    pb_exit->hide();

    setFixedSize(600,500);
}

void GardnerWindow::processAuth()
{
    QStringList logins{};
    int arrLoginSize = auth->beginReadArray("logins");
    for(int loginIndex = 0; loginIndex < arrLoginSize; loginIndex++)
    {
        auth->setArrayIndex(loginIndex);
        logins << auth->value("login").toString();
    }
    auth->endArray();

    if(!logins.contains(le_login->text()))
    {
        QMessageBox msgBox;
        msgBox.setText("Are you new Gardener?");
        msgBox.addButton(QMessageBox::Yes);
        msgBox.addButton(QMessageBox::No);
        int btn = msgBox.exec();
        switch(btn)
        {
        case QMessageBox::Yes:
            logins.append(le_login->text());
            auth->beginWriteArray("logins");
            for(int loginIndex = 0; loginIndex < logins.size(); loginIndex++)
            {
                auth->setArrayIndex(loginIndex);
                auth->setValue("login", logins.at(loginIndex));
            }
            auth->endArray();
            break;
        case QMessageBox::No:
            return;
            break;
        default:
            return;

        }
    }
}

void GardnerWindow::prepareFlowTable(QSettings &gardnerSettings)
{
    twFlowers = new QTableWidget(this);

    twFlowers->setColumnCount(2);
    twFlowers->setColumnWidth(0, 300);
    twFlowers->setHorizontalHeaderLabels({"Flower name", "Watering"});
    mainLayout->addWidget(twFlowers,0,0);

    int flowCount = gardnerSettings.beginReadArray("flowers");


    for (int fIndex = 0; fIndex < flowCount; fIndex++)
    {
        twFlowers->blockSignals(true);
        gardnerSettings.setArrayIndex(fIndex);
        int newRowNum = twFlowers->rowCount();
        addFlower();
        QComboBox *currCombo = static_cast<QComboBox*>(twFlowers->cellWidget(newRowNum, 0));
        currCombo->blockSignals(true);

        QStringList allKeys = gardnerSettings.allKeys();

        currCombo->setCurrentText(allKeys.at(0));
        twFlowers->setItem(newRowNum, 1, new QTableWidgetItem(gardnerSettings.value(gardnerSettings.allKeys().at(0)).toString()));
        currCombo->blockSignals(false);
        twFlowers->blockSignals(false);
    }
    connect(twFlowers, &QTableWidget::itemChanged, this, &GardnerWindow::saveGurdnerData);

    addFlowBtn = new QPushButton("Add new flower",this);
    mainLayout->addWidget(addFlowBtn, 0,1);
    connect(addFlowBtn, &QPushButton::clicked, this, &GardnerWindow::addFlower);
    gardnerSettings.endArray();
}

void GardnerWindow::prepareNotesTable(QSettings &gardnerSettings)
{
    twNotes = new QTableWidget(this);
    twNotes->setColumnCount(2);
    twNotes->setColumnWidth(0,130);
    twNotes->setColumnWidth(1,300);
    twNotes->setHorizontalHeaderLabels({"Data", "Notes"});
    mainLayout->addWidget(twNotes,1,0);

    int noteCount = gardnerSettings.beginReadArray("notes");

    for (int nIndex = 0; nIndex < noteCount; nIndex++)
    {
        gardnerSettings.setArrayIndex(nIndex);

        addNote();

        QString dateTimeKey = gardnerSettings.allKeys().at(0);
        dateTimeKey.remove('t');
        static_cast<QDateTimeEdit*>(twNotes->cellWidget(nIndex, 0))->setDateTime(QDateTime::fromSecsSinceEpoch(dateTimeKey.toInt()));
        twNotes->blockSignals(true);
        twNotes->setItem(nIndex, 1, new QTableWidgetItem(gardnerSettings.value(gardnerSettings.allKeys().at(0)).toString()));
        twNotes->blockSignals(false);
    }
    connect(twNotes, &QTableWidget::itemChanged, this, &GardnerWindow::saveGurdnerData);

    addNoteBtn = new QPushButton("New note",this);
    mainLayout->addWidget(addNoteBtn, 1,1);
    connect(addNoteBtn, &QPushButton::clicked, this, &GardnerWindow::addNote);
    gardnerSettings.endArray();
}

void GardnerWindow::addFlower()
{
    int newRowNum = twFlowers->rowCount();
    twFlowers->insertRow(newRowNum);
    QComboBox *cb = new QComboBox(twFlowers);

    cb->addItem("Choose the flower...");
    cb->addItems(flowNameList);
    connect(cb, &QComboBox::currentIndexChanged, this, &GardnerWindow::saveGurdnerData);
    twFlowers->blockSignals(true);
    twFlowers->setCellWidget(newRowNum, 0, cb);
    twFlowers->setItem(newRowNum, 1, new QTableWidgetItem("0"));
    twFlowers->blockSignals(false);
}

void GardnerWindow::addNote()
{
    QSettings gardnerSettings(le_login->text(), QSettings::IniFormat);
    int newRowNum = twNotes->rowCount();
    twNotes->insertRow(newRowNum);
    QDateTime currTime = QDateTime::currentDateTime();

    twNotes->setCellWidget(newRowNum, 0, new QDateTimeEdit(currTime));
    static_cast<QDateTimeEdit*>(twNotes->cellWidget(newRowNum, 0))->setCalendarPopup(true);
}

void GardnerWindow::saveCurrFlower()
{
    QSettings gardnerSettings(le_login->text(), QSettings::IniFormat);

    gardnerSettings.beginWriteArray("flowers");
    for(int fIndex = 0; fIndex < twFlowers->rowCount(); fIndex++)
    {
        QComboBox *cb = qobject_cast<QComboBox*>(twFlowers->cellWidget(fIndex, 0));
        QTableWidgetItem *item = twFlowers->item(fIndex, 1);

        if(cb->currentIndex() && item->text().length())
        {
            gardnerSettings.setArrayIndex(fIndex);
            gardnerSettings.setValue(cb->currentText(), item->text());
        }
    }
    gardnerSettings.endArray();
    gardnerSettings.sync();
}

void GardnerWindow::saveCurrNote()
{
    QSettings gardnerSettings(le_login->text(), QSettings::IniFormat);

    gardnerSettings.beginWriteArray("notes");
    for(int fIndex = 0; fIndex < twNotes->rowCount(); fIndex++)
    {
        QString dateTime = QString::number(static_cast<QDateTimeEdit*>(twNotes->cellWidget(fIndex, 0))->dateTime().toSecsSinceEpoch());
        QTableWidgetItem *item = twNotes->item(fIndex, 1);

        if(item->text().length())
        {
            gardnerSettings.setArrayIndex(fIndex);
            gardnerSettings.setValue("t"+dateTime, item->text());
        }
    }
    gardnerSettings.endArray();
    gardnerSettings.sync();
}

void GardnerWindow::saveGurdnerData()
{
    QSettings gardnerSettings(le_login->text(), QSettings::IniFormat);
    gardnerSettings.clear();
    gardnerSettings.sync();
    saveCurrFlower();
    saveCurrNote();
}
