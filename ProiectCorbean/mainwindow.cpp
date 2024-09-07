#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
     ui->setupUi(this);

    if(!init()){
         QMessageBox::critical(this,"ERROR","Initialisation error!");
        return;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::init()
{

    QPixmap pixmap("C:\\Users\\danco\\Documents\\ProiectCorbean\\res\\logo.png");
    ui->lblLogo->setPixmap(pixmap);

    QSqlQueryModel * model= DBManager::instance().execQuery("select * from CCDependency");

    for (int i = 0; i < model->rowCount(); ++i) {
        QStringList rowData;


        for (int j = 0; j < model->columnCount(); ++j) {
            QModelIndex index = model->index(i, j);
            QVariant data = model->data(index);
            rowData << data.toString();

            if(j==0){
                _lcPair.first=data.toString();
            }
            else {
                _lcPair.second=data.toString();

            }

        }
        _CCDep.append(_lcPair);
        // qDebug() << rowData.join(", ");



    }

    if(_CCDep.isEmpty()){
        return false;
    }


    return true;

    // for (int i = 0; i < _CCDep.count(); ++i) {
    //     qDebug()<<"Country :: "<<_CCDep.at(i).first << " || Continent :: "<<_CCDep.at(i).second;
    // }


    // QSqlQueryModel *model= DBManager::instance().execQuery("select * from products");


    // if (model == nullptr) {
    //     qDebug() << "Failed to fetch data.";
    //     return false;
    // }
    // for (int i = 0; i < model->rowCount(); ++i) {
    //     QStringList rowData;
    //     for (int j = 0; j < model->columnCount(); ++j) {
    //         QModelIndex index = model->index(i, j);
    //         QVariant data = model->data(index);
    //         rowData << data.toString();
    //     }
    //    // qDebug() << rowData.join(", ");
    // }

}





//=======================================================================Actions=============================================================

void MainWindow::on_actionImport_orders_triggered()
{

    QList<QStringList> fileData;

    QString filePath = QFileDialog::getOpenFileName(this,
                                                    "Open Order",QString(),"CSV files (*.csv)");

    QFile file(filePath);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Cannot open file:" << filePath;
        return;
    }

    QTextStream in(&file);
    bool firstLine = true;

    while (!in.atEnd()) {
        QString line = in.readLine();

        if (firstLine) {
            firstLine = false;
            continue;
        }

        QStringList lineData = line.split('\t');

fileData.append(lineData);




        }


        //test

        for (int i = 0; i < fileData.count(); ++i) {
            qDebug()<<fileData.at(i);
        }


        processOrders(fileData);


        // QList<QPair<QString,QString>> landCountry;
        //
        // lcPair.first="germany";
        // lcPair.second="Europe";

        // landCountry.append(lcPair);
}



void MainWindow::on_actionView_Orders_triggered()
{
    DlgShipments *dlg = new DlgShipments();

    dlg->exec();
}

//==============================================================================OTHER METHODS ===============================================

void MainWindow::processOrders(QList<QStringList> docLines)
{

    for (int i = 0; i < docLines.count(); ++i) {

        SubOrder *order = new SubOrder();


        order->setOrderId(docLines.at(i).at(0));

        QStringList productList = docLines.at(i).at(1).split(';');

        order->setProductId(productList);

        order->setDate(QDate::fromString(docLines.at(i).at(2),"dd.MM.yyyy"));


        if(docLines.at(i).at(3)=="TRUE"){
        order->setConfirmed("TRUE");
        }
        else {
            order->setConfirmed("FALSE");

        }

        order->setClientName(docLines.at(i).at(5));


        order->setContinent(parseContinent(docLines.at(i).at(6)));

        Order::instance().addSubOrder(order);
    }

    DlgOrders *dlg = new DlgOrders();
    dlg->exec();

}


QString MainWindow::parseContinent(QString country){

    for (int i = 0; i < _CCDep.count(); ++i) {
        if(_CCDep.at(i).first == country){
            // qDebug()<<"COUNTRY IN :: "<< country;
            // qDebug()<<"Continent :: "<< _CCDep.at(i).second;

            return _CCDep.at(i).second;
        }
    }
    return QString();

}




