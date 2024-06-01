/********************************************************************************
** Form generated from reading UI file 'compflow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMPFLOW_H
#define UI_COMPFLOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CompFlow
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;

    void setupUi(QWidget *CompFlow)
    {
        if (CompFlow->objectName().isEmpty())
            CompFlow->setObjectName("CompFlow");
        CompFlow->resize(452, 364);
        gridLayout_2 = new QGridLayout(CompFlow);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");

        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);


        retranslateUi(CompFlow);

        QMetaObject::connectSlotsByName(CompFlow);
    } // setupUi

    void retranslateUi(QWidget *CompFlow)
    {
        CompFlow->setWindowTitle(QCoreApplication::translate("CompFlow", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CompFlow: public Ui_CompFlow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMPFLOW_H
