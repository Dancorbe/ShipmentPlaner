/********************************************************************************
** Form generated from reading UI file 'dlgshipments.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGSHIPMENTS_H
#define UI_DLGSHIPMENTS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DlgShipments
{
public:
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QTreeView *treeView;
    QPushButton *btnClose;

    void setupUi(QDialog *DlgShipments)
    {
        if (DlgShipments->objectName().isEmpty())
            DlgShipments->setObjectName("DlgShipments");
        DlgShipments->resize(783, 535);
        gridLayout_2 = new QGridLayout(DlgShipments);
        gridLayout_2->setObjectName("gridLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        groupBox = new QGroupBox(DlgShipments);
        groupBox->setObjectName("groupBox");
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName("gridLayout");
        treeView = new QTreeView(groupBox);
        treeView->setObjectName("treeView");

        gridLayout->addWidget(treeView, 0, 0, 1, 1);


        verticalLayout->addWidget(groupBox);

        btnClose = new QPushButton(DlgShipments);
        btnClose->setObjectName("btnClose");

        verticalLayout->addWidget(btnClose);


        gridLayout_2->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(DlgShipments);

        QMetaObject::connectSlotsByName(DlgShipments);
    } // setupUi

    void retranslateUi(QDialog *DlgShipments)
    {
        DlgShipments->setWindowTitle(QCoreApplication::translate("DlgShipments", "Dialog", nullptr));
        groupBox->setTitle(QCoreApplication::translate("DlgShipments", "Shipments", nullptr));
        btnClose->setText(QCoreApplication::translate("DlgShipments", "Close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DlgShipments: public Ui_DlgShipments {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGSHIPMENTS_H
