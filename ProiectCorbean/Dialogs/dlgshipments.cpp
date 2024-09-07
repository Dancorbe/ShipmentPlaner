#include "dlgshipments.h"
#include "ui_dlgshipments.h"

DlgShipments::DlgShipments(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DlgShipments)
{
    ui->setupUi(this);

    init();
}

DlgShipments::~DlgShipments()
{
    delete ui;
}

void DlgShipments::init()
{
    _model= new QStandardItemModel();
    QStringList parentHeaders;
    parentHeaders << "Name" << "Date";


    QStringList childHeaders;
    childHeaders << "Order ID"
                 << "Product ID"
                 << "Product Name"
                 << "Client Name"
                 << "Client Id"
                 << "Date"
                 << "Continent"
                 << "Status";


    QSqlQueryModel * qmodel= DBManager::instance().execQuery("select * from dbo.Shipments");

    QList<QStringList> shpContent;
    for (int i = 0; i < qmodel->rowCount(); ++i) {
        QStringList rowData;


        for (int j = 0; j < qmodel->columnCount(); ++j) {
            QModelIndex index = qmodel->index(i, j);
            QVariant data = qmodel->data(index);
            rowData << data.toString();
        }

        // qDebug()<<"++++++++++++++++++++++++++++++++++AICI++++++++++++++++++++++++++";
         qDebug()<<rowData;
        shpContent.append(rowData);
    }






    _model->setColumnCount(5);


fillModel(shpContent);



    ui->treeView->resizeColumnToContents(0);
    ui->treeView->resizeColumnToContents(1);
    ui->treeView->resizeColumnToContents(2);
    ui->treeView->resizeColumnToContents(3);
    ui->treeView->resizeColumnToContents(4);



//start insert

    // QStandardItem * parent1col1 = new QStandardItem("id parinte");


    // QStandardItem * parent1col2 = new QStandardItem("data");


    // QList<QStandardItem*> colParinti;
    //         colParinti.append(parent1col1);
    // colParinti.append(parent1col2);


    // QStandardItem * copil1 = new QStandardItem("Copil1");
    // QStandardItem * copil2 = new QStandardItem("Copil2");

    // parent1col1->appendRow(copil1);
    // parent1col1->appendRow(copil2);


   // _model->appendRow(colParinti);


    ui->treeView->setModel(_model);

}





//=======================================================================Other Methods===============================================================


void DlgShipments::setHeaders()
{
    QStringList parentHeaders;
    parentHeaders << "Name" << "Date";


    _model->setHorizontalHeaderLabels(parentHeaders);
    _model->setColumnCount(2);
}

void DlgShipments::on_btnClose_clicked()
{
    this->close();
}

QString DlgShipments::getClientName(QString client_id){
 return DBManager::instance().selectSingle("select distinct name from Clients where id ="+client_id).toString();
}

QString DlgShipments::getProductName(QString product_id){
    return DBManager::instance().selectSingle("select distinct name from Products where id ="+product_id).toString();
}

void DlgShipments::on_treeView_expanded(const QModelIndex &index)
{
    ui->treeView->resizeColumnToContents(0);
    ui->treeView->resizeColumnToContents(1);
    ui->treeView->resizeColumnToContents(2);
     ui->treeView->resizeColumnToContents(3);
     ui->treeView->resizeColumnToContents(4);
}


void DlgShipments::on_treeView_collapsed(const QModelIndex &index)
{
    ui->treeView->resizeColumnToContents(0);
    ui->treeView->resizeColumnToContents(1);
    ui->treeView->resizeColumnToContents(2);
    ui->treeView->resizeColumnToContents(3);
    ui->treeView->resizeColumnToContents(4);
}

void DlgShipments::fillModel(QList<QStringList> shpContent){

    QSqlQueryModel * qmodel;
    for (int i = 0; i < shpContent.count(); ++i) {
        // qDebug()<<"%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%";
        // qDebug()<<shpContent.at(i);
        QList<QStandardItem*> colParinti;
        QStandardItem *parentCol1= new QStandardItem("Shipment no.:"+shpContent.at(i).at(0));
        QStandardItem *parentCol2= new QStandardItem("Shipment date:"+shpContent.at(i).at(2));
        QStandardItem *parentCol3 = new QStandardItem("Shipment type: "+shpContent.at(i).last());

        colParinti.append(parentCol1);
        colParinti.append(parentCol2);
        colParinti.append(parentCol3);






        qmodel= DBManager::instance().execQuery("select * from dbo.Orders where order_id =" + shpContent.at(i).at(1));

        for (int i = 0; i < qmodel->rowCount(); ++i) {
            QStringList rowData;


            for (int j = 0; j < qmodel->columnCount(); ++j) {
                QModelIndex index = qmodel->index(i, j);
                QVariant data = qmodel->data(index);
                rowData << data.toString();
            }
            qDebug()<<"++++++++++++++++++++++++++++++++++Row data for shipment++++++++++++++++++++++++++";

            qDebug()<<rowData;


            QStandardItem * childcol1= new QStandardItem(rowData.at(0));
            QStandardItem * childcol2= new QStandardItem(getClientName(rowData.at(1)));
            QStandardItem * childcol3 = new QStandardItem(rowData.at(2));
            QStandardItem * childcol4 = new QStandardItem(getProductName(rowData.at(3)));

            QString aux= "Confirmed";
            if(rowData.at(4).toInt()==0){
                aux = "Invalid";
            }
            QStandardItem * childcol5 = new QStandardItem(aux);

            QList<QStandardItem*> colCopii;
            colCopii.append(childcol1);
            colCopii.append(childcol2);
            colCopii.append(childcol3);
            colCopii.append(childcol4);
            colCopii.append(childcol5);


            parentCol1->appendRow(colCopii);

        }




        _model->appendRow(colParinti);
    }

}
