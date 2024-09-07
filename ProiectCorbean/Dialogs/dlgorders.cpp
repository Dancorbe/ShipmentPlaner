#include "dlgorders.h"
#include "ui_dlgorders.h"

DlgOrders::DlgOrders(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DlgOrders)
{
    ui->setupUi(this);


    if(Order::instance().subOrders().isEmpty()){
        QMessageBox::critical(this,"ERROR","Error, didn't recieve data");
        this->close();
    }
    _model = new QStandardItemModel();
    displayOrders();

}

DlgOrders::~DlgOrders()
{
    delete ui;
}



//=======================================================================BUTTONS===============================================================
void DlgOrders::on_btnClose_clicked()
{
    this->close();
}


void DlgOrders::on_btnGenerate_clicked()
{
    QStringList orderIds;

    QList< QPair<QString,QString>>idContinentList;
    for (int i = 0; i < Order::instance().subOrders().count(); ++i) {
        if(!orderIds.contains(Order::instance().subOrders().at(i)->getOrderId())){//daca nu contine
            orderIds.append(Order::instance().subOrders().at(i)->getOrderId());

            QPair<QString,QString>pairIDContinent;
            pairIDContinent.first= Order::instance().subOrders().at(i)->getOrderId();
            pairIDContinent.second = Order::instance().subOrders().at(i)->getContinent();
            idContinentList.append(pairIDContinent);
        }




    }


    for (int i = 0; i < idContinentList.count(); ++i) {
          QString aux =idContinentList.at(i).first ;
        if(idContinentList.at(i).second=="EU"){
            Shipment* trainShipment = ShipmentFactory::createShipment("Train",aux.toInt());


        }else {
            Shipment* planeShipment = ShipmentFactory::createShipment("Plane",aux.toInt());

        }



       // QString sqlq= "INSERT INTO [dbo].[Shipments] (order_id, shipment_date, shipment_type) VALUES ("+idContinentList.at(i).first+", 'GETDATE()', '"+transport+"')";
       // DBManager::instance().exec(sqlq);
    }




}





//===================================================================OTHER METHODS ============================================================
void DlgOrders::displayOrders()
{
setHeaders();

    for (int i = 0; i < Order::instance().subOrders().count(); ++i) {

        for (int j = 0; j < Order::instance().subOrders().at(i)->getProductId().count(); ++j) {

            QList<QStandardItem*>tblRow;
            tblRow.append(new QStandardItem(Order::instance().subOrders().at(i)->getOrderId()));

            //product name+id
            tblRow.append(new QStandardItem(Order::instance().subOrders().at(i)->getProductId().at(j)));
            tblRow.append(new QStandardItem(getProdcutName(Order::instance().subOrders().at(i)->getProductId().at(j))));
            Order::instance().subOrders().at(i)->insetName(getProdcutName(Order::instance().subOrders().at(i)->getProductId().at(j)));// am uitat sa introduc in lista...

            tblRow.append(new QStandardItem(Order::instance().subOrders().at(i)->getClientName()));
            tblRow.append(new QStandardItem(getClientId(Order::instance().subOrders().at(i)->getClientName())));
            Order::instance().subOrders().at(i)->setClientId(Order::instance().subOrders().at(i)->getClientName());


            tblRow.append(new QStandardItem(Order::instance().subOrders().at(i)->getDate().toString("dd.MM.yyyy")));
           // qDebug()<<Order::instance().subOrders().at(i)->getDate().toString("dd-MM-yyyy");
            tblRow.append(new QStandardItem(Order::instance().subOrders().at(i)->getContinent()));


            if(Order::instance().subOrders().at(i)->getConfirmed()){

               tblRow.append(new QStandardItem("TRUE"));
            }
            else {
                tblRow.append(new QStandardItem("FALSE"));

            }





            QString sqlq=  "INSERT INTO [dbo].[Orders] ([order_id], [client_id], [order_date], [product_id], [confirmed]) VALUES ("+
                           Order::instance().subOrders().at(i)->getOrderId()+", "+
                           getClientId(Order::instance().subOrders().at(i)->getClientName())+", '"+
                          Order::instance().subOrders().at(i)->getDate().toString("yyyy-MM-dd") +"', "+
                           Order::instance().subOrders().at(i)->getProductId().at(j)+", 1)";

            qDebug()<<"=>>>>>>>>>>>"<<sqlq;


            DBManager::instance().exec(sqlq);


            _model->appendRow(tblRow);

        }

     _model->appendRow(getEmptyrows());

    }

    ui->tblOrders->setModel(_model);

}


QList<QStandardItem*> DlgOrders::getEmptyrows(){
    QList<QStandardItem*> itmList;
    for (int i = 0; i < Order::instance().subOrders().at(0)->getProductId().count(); ++i) {
        itmList.append(new QStandardItem(QString("-")));

    }

    return itmList;

}


void DlgOrders::setHeaders(){
    QStringList headers;
    headers << "Order ID"
            << "Product ID"
            << "Product Name"
            << "Client Name"
            << "Client Id"
            << "Date"
            << "Continent"
            << "Status";

    _model->setHorizontalHeaderLabels(headers);
}



//=======================================================================DB METHODS===============================================================


QString DlgOrders::getProdcutName(QString productId){

    return DBManager::instance().selectSingle("select name from products where id ="+productId).toString();
}

QString DlgOrders::getClientId(QString clientName){

    return DBManager::instance().selectSingle("select id from clients where name ='"+clientName+"'").toString();

}


