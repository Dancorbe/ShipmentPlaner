#include "trainshipment.h"
#include <QDebug>

TrainShipment::TrainShipment(int orderId)
    : Shipment(orderId, "Train") {

    qDebug()<<"Train shipment with id :: "<< orderId;


    calculateDate();
insertShipment();
}

void TrainShipment::calculateDate() {
   // QDate nowD= QDate::currentDate();
    shDate = QDate::currentDate().addDays(1);
}

void TrainShipment::insertShipment()
{
    QString sqlq= "INSERT INTO [dbo].[Shipments] (order_id, shipment_date, ship_type) VALUES ("+QString::number(orderId)+", '"+shDate.toString("dd-MM-yyyy")+"', 'Train')";
    DBManager::instance().exec(sqlq);
}
