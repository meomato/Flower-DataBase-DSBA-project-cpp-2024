#include "compflow.h"
#include "ui_compflow.h"
#include <QTableWidget>
#include <QHeaderView>

CompFlow::CompFlow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CompFlow)
{
    ui->setupUi(this);
    setWindowTitle("Bloom Baze | Flower Comparison");

}

CompFlow::~CompFlow()
{
    delete ui;
}

void CompFlow::setCompVector(QVector<FlowerContainer *> fcCompVector)
{
    clearWidgets();
    for(const auto fc: fcCompVector)
    {
        FlowerLabel *fl = new FlowerLabel;
        fl->setAlignment(Qt::AlignHCenter);
        QPixmap pix(fc->vUrlFlowers.at(0));
        fl->setPixmap(pix);
        int currColumn = ui->gridLayout->columnCount();
        ui->gridLayout->addWidget(fl,0,currColumn);

        QTableWidget *flowTable = new QTableWidget();
        flowTable->setAlternatingRowColors(true);
        flowTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        flowTable->setSelectionMode(QAbstractItemView::NoSelection);
        flowTable->setSelectionBehavior(QAbstractItemView::SelectRows);
        flowTable->horizontalHeader()->setVisible(false);
        flowTable->verticalHeader()->setVisible(false);
        ui->gridLayout->addWidget(flowTable, 1,currColumn);
        flowTable->setColumnCount(2);
        flowTable->setColumnWidth(0,123);
        flowTable->setColumnWidth(1,123);
        flowTable->setRowCount(8);

        int rowIndex{};
        while(rowIndex < flowTable->rowCount())
        {
            flowTable->setRowHeight(rowIndex, 50);
            rowIndex++;
        }

        flowTable->setItem(0,0,new QTableWidgetItem("Flower time:"));
        flowTable->setItem(0,1,new QTableWidgetItem(fc->vDataFlowers.at(0)));
        flowTable->setItem(1,0,new QTableWidgetItem("Life Cycle:"));
        flowTable->setItem(1,1,new QTableWidgetItem(fc->vDataFlowers.at(1)));
        flowTable->setItem(2,0,new QTableWidgetItem("Leaves:"));
        flowTable->setItem(2,1,new QTableWidgetItem(fc->vDataFlowers.at(2)));
        flowTable->setItem(3,0,new QTableWidgetItem("Flower group:"));
        flowTable->setItem(3,1,new QTableWidgetItem(fc->vDataFlowers.at(3)));
        flowTable->setItem(4,0,new QTableWidgetItem("Plant habit:"));
        flowTable->setItem(4,1,new QTableWidgetItem(fc->vDataFlowers.at(4)));
        flowTable->setItem(5,0,new QTableWidgetItem("Containers:"));
        flowTable->setItem(5,1,new QTableWidgetItem(fc->vDataFlowers.at(5)));
        flowTable->setItem(6,0,new QTableWidgetItem("Additional:"));
        flowTable->setItem(6,1,new QTableWidgetItem(fc->vDataFlowers.at(6)));
        flowTable->setItem(7,0,new QTableWidgetItem("URL:"));
        flowTable->setItem(7,1,new QTableWidgetItem(fc->vDataFlowers.at(7)));

        fl->setFocus();
    }
}

void CompFlow::clearWidgets()
{
    QLayoutItem *item;
    while ((item = ui->gridLayout->takeAt(0)) != nullptr)
    {
        if (item->widget()) {
            delete item->widget();
        }
        delete item;
    }
}
