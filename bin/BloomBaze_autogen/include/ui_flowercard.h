/********************************************************************************
** Form generated from reading UI file 'flowercard.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FLOWERCARD_H
#define UI_FLOWERCARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FlowerCard
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QLabel *l_fname;
    QFormLayout *formLayout;
    QTableWidget *tableWidget;
    QTableWidget *tableWidget_2;

    void setupUi(QWidget *FlowerCard)
    {
        if (FlowerCard->objectName().isEmpty())
            FlowerCard->setObjectName("FlowerCard");
        FlowerCard->resize(707, 471);
        gridLayout_2 = new QGridLayout(FlowerCard);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        l_fname = new QLabel(FlowerCard);
        l_fname->setObjectName("l_fname");
        QFont font;
        font.setPointSize(20);
        l_fname->setFont(font);
        l_fname->setWordWrap(true);

        gridLayout->addWidget(l_fname, 0, 1, 1, 1);

        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        tableWidget = new QTableWidget(FlowerCard);
        if (tableWidget->columnCount() < 2)
            tableWidget->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        if (tableWidget->rowCount() < 3)
            tableWidget->setRowCount(3);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(2, __qtablewidgetitem4);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setShowGrid(false);
        tableWidget->horizontalHeader()->setVisible(false);
        tableWidget->verticalHeader()->setVisible(false);

        formLayout->setWidget(0, QFormLayout::SpanningRole, tableWidget);


        gridLayout->addLayout(formLayout, 1, 1, 1, 1);

        tableWidget_2 = new QTableWidget(FlowerCard);
        if (tableWidget_2->columnCount() < 1)
            tableWidget_2->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(0, __qtablewidgetitem5);
        if (tableWidget_2->rowCount() < 2)
            tableWidget_2->setRowCount(2);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget_2->setVerticalHeaderItem(0, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget_2->setVerticalHeaderItem(1, __qtablewidgetitem7);
        tableWidget_2->setObjectName("tableWidget_2");
        tableWidget_2->setShowGrid(false);
        tableWidget_2->setGridStyle(Qt::NoPen);
        tableWidget_2->horizontalHeader()->setVisible(false);
        tableWidget_2->verticalHeader()->setVisible(false);

        gridLayout->addWidget(tableWidget_2, 1, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);


        retranslateUi(FlowerCard);

        QMetaObject::connectSlotsByName(FlowerCard);
    } // setupUi

    void retranslateUi(QWidget *FlowerCard)
    {
        FlowerCard->setWindowTitle(QCoreApplication::translate("FlowerCard", "Form", nullptr));
        l_fname->setText(QCoreApplication::translate("FlowerCard", "FName", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_2->verticalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("FlowerCard", "\320\235\320\276\320\262\320\260\321\217 \321\201\321\202\321\200\320\276\320\272\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FlowerCard: public Ui_FlowerCard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FLOWERCARD_H
