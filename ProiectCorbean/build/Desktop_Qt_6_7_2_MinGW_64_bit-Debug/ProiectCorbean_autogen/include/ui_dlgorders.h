/********************************************************************************
** Form generated from reading UI file 'dlgorders.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGORDERS_H
#define UI_DLGORDERS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_DlgOrders
{
public:
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QTableView *tblOrders;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnGenerate;
    QPushButton *btnClose;

    void setupUi(QDialog *DlgOrders)
    {
        if (DlgOrders->objectName().isEmpty())
            DlgOrders->setObjectName("DlgOrders");
        DlgOrders->resize(890, 483);
        gridLayout_3 = new QGridLayout(DlgOrders);
        gridLayout_3->setObjectName("gridLayout_3");
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName("gridLayout_2");
        groupBox = new QGroupBox(DlgOrders);
        groupBox->setObjectName("groupBox");
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName("gridLayout");
        tblOrders = new QTableView(groupBox);
        tblOrders->setObjectName("tblOrders");

        gridLayout->addWidget(tblOrders, 0, 0, 1, 1);


        gridLayout_2->addWidget(groupBox, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        btnGenerate = new QPushButton(DlgOrders);
        btnGenerate->setObjectName("btnGenerate");

        horizontalLayout->addWidget(btnGenerate);

        btnClose = new QPushButton(DlgOrders);
        btnClose->setObjectName("btnClose");

        horizontalLayout->addWidget(btnClose);


        gridLayout_2->addLayout(horizontalLayout, 1, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 0, 0, 1, 1);


        retranslateUi(DlgOrders);

        QMetaObject::connectSlotsByName(DlgOrders);
    } // setupUi

    void retranslateUi(QDialog *DlgOrders)
    {
        DlgOrders->setWindowTitle(QCoreApplication::translate("DlgOrders", "Dialog", nullptr));
        groupBox->setTitle(QCoreApplication::translate("DlgOrders", "Found Orders", nullptr));
        btnGenerate->setText(QCoreApplication::translate("DlgOrders", "Generate Shipments", nullptr));
        btnClose->setText(QCoreApplication::translate("DlgOrders", "Close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DlgOrders: public Ui_DlgOrders {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGORDERS_H
