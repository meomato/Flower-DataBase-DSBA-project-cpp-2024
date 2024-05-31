#include <iostream>
#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDebug>
#include <QDir>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    settings = new QSettings("stat", QSettings::IniFormat, this);
    openCsv();

    tw = ui->tableWidget;
    loadFlowers();

    ui->tw_filterList->setColumnWidth(0, 250);
}

MainWindow::~MainWindow()
{
    delete ui;
}

QStringList MainWindow::split(QString full)
{
    QStringList result{};
    int commaIndex{};
    while(commaIndex >= 0)
    {
        int marksIndex  = full.indexOf('"');
        if(!marksIndex)
            marksIndex++;
        commaIndex = full.indexOf(',');
        if(marksIndex != -1)
        {
            if(commaIndex < marksIndex)
            {
                result.push_back(full.left(commaIndex));
                full.remove(0, commaIndex+1);
            }
            else
            {
                int marksIndex2 = full.indexOf('"',marksIndex);
                int commaIndex2 = full.indexOf(',',marksIndex2);
                QString str = full.left(commaIndex2);
                str.remove('"');
                result.push_back(str);
                full.remove(0, commaIndex2+1);
            }
        }
        else
        {
            result.push_back(full.left(commaIndex));
            full.remove(0, commaIndex+1);
        }
    }
    return result;
}

void MainWindow::openCsv()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Открытие базы цветов"), "", tr("CSV файл (*.csv)"));
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    int strIndex{};

    while (!file.atEnd()) {
        QByteArray line = file.readLine();
        QString currString = QString::fromUtf8(line);
        QStringList items = split(currString);
        items << settings->value(items[1]).toString();
        int colIndex{};
        for(const auto item : items)
        {
            if(!strIndex)
            {
                topics.push_back(item);
                flowersDb.insert(colIndex, {});
            }
            else
            {
                flowersDb[colIndex].push_back(item);
                if(colIndex == 1)
                {
                    if(!settings->contains(item))
                    {
                        settings->setValue(item, 0);
                    }
                }

            }
            colIndex++;
        }
        strIndex++;
    }
}

void MainWindow::loadFlowers(QString subString)
{
    if(fcVector.size())
    {
        for(auto fc: fcVector)
        {
            delete fc;
            fcVector.remove(fcVector.indexOf(fc));
        }
    }


    tw->setRowCount(0);
    bool isLeft = true;
    int newRow{};
    int iterIndex{};

    QMultiMap<int, int>::Iterator mmIter{};

    if(popularityMMap.size())
    {
        if(qobject_cast<QRadioButton*>(ui->tw_filterList->cellWidget(1,0))->isChecked())
        {
            mmIter = popularityMMap.begin();
        }
        else
        {
            mmIter = --popularityMMap.end();
        }
    }

    while(iterIndex < flowersDb[1].count())
    {
        QString flowerName = flowersDb.value(1).at(iterIndex);

        if(subString.length())
        {
            if(!flowerName.contains(subString))
            {
                iterIndex++;
                continue;
            }
        }

        if(flowGroupVector.length())
        {
            if(!flowGroupVector.contains(flowersDb.value(0).at(iterIndex)))
            {
                iterIndex++;
                continue;
            }
        }

        if(qualitiesVector.length())
        {
            if(!qualitiesVector.contains(flowersDb.value(5).at(iterIndex)))
            {
                iterIndex++;
                continue;
            }
        }

        if(containerVector.length())
        {
            if(!containerVector.contains(flowersDb.value(3).at(iterIndex)))
            {
                iterIndex++;
                continue;
            }
        }

        if(popularityMMap.size())
        {
            iterIndex = mmIter.value();
            flowerName = flowersDb.value(1).at(iterIndex);
            if(qobject_cast<QRadioButton*>(ui->tw_filterList->cellWidget(1,0))->isChecked())
            {
                mmIter++;
                if(mmIter == popularityMMap.end())
                {
                    break;
                }
            }
            else
            {
                if(mmIter == popularityMMap.begin())
                {
                    break;
                }
                mmIter--;
            }
        }

        FlowerContainer *fc = new FlowerContainer(this);
        fcVector.push_back(fc);
        fc->vDataFlowers.push_back(flowersDb.value(4).at(iterIndex));
        fc->vDataFlowers.push_back(flowersDb.value(7).at(iterIndex));
        fc->vDataFlowers.push_back(flowersDb.value(6).at(iterIndex));
        fc->vDataFlowers.push_back(flowersDb.value(0).at(iterIndex));
        fc->vDataFlowers.push_back(flowersDb.value(9).at(iterIndex));
        fc->vDataFlowers.push_back(flowersDb.value(3).at(iterIndex));
        fc->vDataFlowers.push_back(flowersDb.value(8).at(iterIndex));
        fc->vDataFlowers.push_back(flowersDb.value(2).at(iterIndex));

        QDir currDir("./img/"+flowerName);
        QString fAddress{};
        fAddress ="./img/"+flowerName+"/"+currDir.entryList().value(2);


        if(!fc->setInfo(fAddress, flowerName))
        {
            iterIndex++;
            continue;
        }

        if(isLeft)
        {
            newRow = tw->rowCount();
            tw->insertRow(newRow);
            tw->setCellWidget(newRow, 0, fc);
        }
        else
        {
            tw->setCellWidget(newRow, 1, fc);
        }
        isLeft = !isLeft;

        for(const auto fName : currDir.entryList())
        {
            if(fName!="." && fName!="..")
            {
                fc->vUrlFlowers.push_back("./img/"+flowerName+"/"+fName);
            }
        }

        if(!popularityMMap.size())
        {
            iterIndex++;
        }
    }
}

void MainWindow::processFlowGroupVector(bool isChecked)
{
    int rowNum = ui->tw_filterList->currentRow();
    QString str = qobject_cast<QCheckBox*>(ui->tw_filterList->cellWidget(rowNum, 0))->text();
    if(isChecked)
    {
        flowGroupVector << str;
    }
    else
    {
        flowGroupVector.remove(flowGroupVector.indexOf(str));
    }
    loadFlowers();
}

void MainWindow::processQualityVector(bool isChecked)
{
    int rowNum = ui->tw_filterList->currentRow();
    QString str = qobject_cast<QCheckBox*>(ui->tw_filterList->cellWidget(rowNum, 0))->text();
    if(isChecked)
    {
        qualitiesVector << str;
    }
    else
    {
        qualitiesVector.remove(qualitiesVector.indexOf(str));
    }
    loadFlowers();
}

void MainWindow::processContainerVector(bool isChecked)
{
    int rowNum = ui->tw_filterList->currentRow();
    QString str = qobject_cast<QCheckBox*>(ui->tw_filterList->cellWidget(rowNum, 0))->text();
    if(isChecked)
    {
        containerVector << str;
    }
    else
    {
        containerVector.remove(containerVector.indexOf(str));
    }
    loadFlowers();
}

void MainWindow::processPopularityVector()
{
    popularityMMap.clear();
    for(int strIndex = 0; strIndex < flowersDb[1].count(); strIndex++)
    {
        popularityMMap.insert(flowersDb[29].at(strIndex).toInt(), strIndex);
    }
    loadFlowers();
}

void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    loadFlowers(arg1);
}

void MainWindow::on_pb_flowerGroup_clicked(bool checked)
{
    ui->tw_filterList->setRowCount(0);
    if(checked)
    {
        ui->pb_container->setChecked(false);
        ui->pb_flowerGroup->setChecked(true);
        ui->pb_qualities->setChecked(false);
        ui->pb_popularity->setChecked(false);
    }
    QVector<QString> flowerGroup = flowersDb.value(0);

    flowerGroup.sort();
    QString lastFlowerGroup{};
    for(const auto group: flowerGroup)
    {
        if(group != lastFlowerGroup)
        {
            lastFlowerGroup = group;
            int newRowNum = ui->tw_filterList->rowCount();
            ui->tw_filterList->insertRow(newRowNum);
            QCheckBox *chBox = new QCheckBox(group, this);
            connect(chBox, &QCheckBox::clicked, this, &MainWindow::processFlowGroupVector);
            ui->tw_filterList->setCellWidget(newRowNum,  0, chBox);
        }
    }
}

void MainWindow::on_pb_container_clicked(bool checked)
{
    ui->tw_filterList->setRowCount(0);
    if(checked)
    {
        ui->pb_container->setChecked(true);
        ui->pb_flowerGroup->setChecked(false);
        ui->pb_qualities->setChecked(false);
        ui->pb_popularity->setChecked(false);
    }
    QVector<QString> container = flowersDb.value(3);

    container.sort();
    QString lastContainer{};
    for(const auto cont: container)
    {
        if(cont != lastContainer)
        {
            lastContainer = cont;
            int newRowNum = ui->tw_filterList->rowCount();
            ui->tw_filterList->insertRow(newRowNum);
            QCheckBox *chBox = new QCheckBox(cont, this);
            connect(chBox, &QCheckBox::clicked, this, &MainWindow::processContainerVector);
            ui->tw_filterList->setCellWidget(newRowNum,  0, chBox);
        }
    }
}

void MainWindow::on_pb_popularity_clicked(bool checked)
{
    ui->tw_filterList->setRowCount(2);
    if(checked)
    {
        ui->pb_container->setChecked(false);
        ui->pb_flowerGroup->setChecked(false);
        ui->pb_qualities->setChecked(false);
        ui->pb_popularity->setChecked(true);
    }

    QRadioButton *rbMaxBegin = new QRadioButton("Сначала популярные",this);
    connect(rbMaxBegin, &QCheckBox::clicked, this, &MainWindow::processPopularityVector);
    ui->tw_filterList->setCellWidget(0,  0, rbMaxBegin);
    QRadioButton *rbMaxEnd = new QRadioButton("Сначала не популярные", this);
    connect(rbMaxEnd, &QCheckBox::clicked, this, &MainWindow::processPopularityVector);
    ui->tw_filterList->setCellWidget(1,  0, rbMaxEnd);
}



void MainWindow::on_pb_qualities_clicked(bool checked)
{
    ui->tw_filterList->setRowCount(0);
    if(checked)
    {
        ui->pb_container->setChecked(false);
        ui->pb_flowerGroup->setChecked(false);
        ui->pb_qualities->setChecked(true);
        ui->pb_popularity->setChecked(false);
    }
    QVector<QString> qualities = flowersDb.value(5);

    qualities.sort();
    QString lastQuality{};
    for(const auto quality: qualities)
    {
        if(quality != lastQuality)
        {
            lastQuality = quality;
            int newRowNum = ui->tw_filterList->rowCount();
            ui->tw_filterList->insertRow(newRowNum);
            QCheckBox *chBox = new QCheckBox(quality, this);
            connect(chBox, &QCheckBox::clicked, this, &MainWindow::processQualityVector);
            ui->tw_filterList->setCellWidget(newRowNum,  0, chBox);
        }
    }
}
