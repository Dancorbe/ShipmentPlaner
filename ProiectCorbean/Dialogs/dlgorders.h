#ifndef DLGORDERS_H
#define DLGORDERS_H

#include <QDialog>
#include <QStandardItemModel>
#include <QString>
#include <QStringList>
#include <QMessageBox>
#include "../order.h"
#include "../dbmanager.h"
#include "../Shipment/shipment.h"
#include "../Shipment/shipmentfactory.h"


namespace Ui {
class DlgOrders;
}

class DlgOrders : public QDialog
{
    Q_OBJECT

public:
    explicit DlgOrders(QWidget *parent = nullptr);
    ~DlgOrders();

private slots:
    void on_btnClose_clicked();

    void on_btnGenerate_clicked();

private:
    Ui::DlgOrders *ui;
    QStandardItemModel * _model;

    void displayOrders();
    QList<QStandardItem *> getEmptyrows();
    QString getProdcutName(QString productId);
    void setHeaders();
    QString getClientId(QString clientName);

};

#endif // DLGORDERS_H
