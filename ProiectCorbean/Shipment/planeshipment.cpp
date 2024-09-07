#include "planeshipment.h"
#include <QDebug>

PlaneShipment::PlaneShipment(int orderId)
    : Shipment(orderId, "Plane") {
    qDebug()<<"Plane shipment with id :: "<< orderId;

    calculateDate();
    insertShipment();
}

void PlaneShipment::calculateDate() {
    shDate = QDate::currentDate().addDays(3);
}

void PlaneShipment::insertShipment()
{
    QString sqlq= "INSERT INTO [dbo].[Shipments] (order_id, shipment_date, ship_type) VALUES ("+QString::number(orderId)+", '"+shDate.toString("dd-MM-yyyy")+"', 'Plane')";
    DBManager::instance().exec(sqlq);
}
