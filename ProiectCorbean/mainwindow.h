#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPixmap>
#include <QString>
#include <QMessageBox>
#include <QFileDialog>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQueryModel>
#include <QFileDialog>
#include <QDate>


#include "dbmanager.h"
#include "order.h"
#include "suborder.h"
#include "Dialogs/dlgorders.h"
#include "Dialogs/dlgshipments.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionImport_orders_triggered();

    void on_actionView_Orders_triggered();



private:
    bool init();


    void processOrders(QList<QStringList>docLines);
    QString parseContinent(QString country);


    //=====================================================================params=================================================
    Ui::MainWindow *ui;

    QList<QPair<QString,QString>> _CCDep;
    QPair<QString,QString> _lcPair;


};
#endif // MAINWINDOW_H
