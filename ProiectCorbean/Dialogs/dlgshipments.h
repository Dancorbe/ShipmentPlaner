#ifndef DLGSHIPMENTS_H
#define DLGSHIPMENTS_H

#include <QDialog>
#include <QStandardItemModel>
#include <QString>
#include <QMessageBox>
#include <QDate>

#include "../dbmanager.h"

namespace Ui {
class DlgShipments;
}

class DlgShipments : public QDialog
{
    Q_OBJECT

public:
    explicit DlgShipments(QWidget *parent = nullptr);
    ~DlgShipments();

    QString getProductName(QString product_id);
private slots:
    void on_btnClose_clicked();

    void on_treeView_expanded(const QModelIndex &index);

    void on_treeView_collapsed(const QModelIndex &index);

private:
    Ui::DlgShipments *ui;


    QStandardItemModel * _model;
    void init();
    void setHeaders();

    QString getClientName(QString client_id);
    void fillModel(QList<QStringList> shpContent);
};

#endif // DLGSHIPMENTS_H
