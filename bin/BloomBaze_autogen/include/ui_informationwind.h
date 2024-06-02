/********************************************************************************
** Form generated from reading UI file 'informationwind.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INFORMATIONWIND_H
#define UI_INFORMATIONWIND_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_InformationWind
{
public:
    QGridLayout *gridLayout;
    QToolButton *toolButton_5;
    QVBoxLayout *verticalLayout;
    QLabel *label;

    void setupUi(QDialog *InformationWind)
    {
        if (InformationWind->objectName().isEmpty())
            InformationWind->setObjectName("InformationWind");
        InformationWind->resize(444, 392);
        gridLayout = new QGridLayout(InformationWind);
        gridLayout->setObjectName("gridLayout");
        toolButton_5 = new QToolButton(InformationWind);
        toolButton_5->setObjectName("toolButton_5");

        gridLayout->addWidget(toolButton_5, 1, 1, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(InformationWind);
        label->setObjectName("label");
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label->setWordWrap(true);

        verticalLayout->addWidget(label);


        gridLayout->addLayout(verticalLayout, 0, 0, 2, 1);


        retranslateUi(InformationWind);

        QMetaObject::connectSlotsByName(InformationWind);
    } // setupUi

    void retranslateUi(QDialog *InformationWind)
    {
        InformationWind->setWindowTitle(QCoreApplication::translate("InformationWind", "Dialog", nullptr));
        toolButton_5->setText(QCoreApplication::translate("InformationWind", "OK", nullptr));
        label->setText(QCoreApplication::translate("InformationWind", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt; color:#aa00ff;\">Bloom Baze is your perfect app for flower and plant lovers! </span></p><p align=\"center\"><span style=\" font-size:10pt; color:#aa00ff;\">Explore the rich world of flora with our user-friendly and intuitive interface.</span></p><p align=\"center\"><img src=\":/img/purple_flower_icon_transparent.ico\"/></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class InformationWind: public Ui_InformationWind {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFORMATIONWIND_H
