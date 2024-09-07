#ifndef PLANESHIPMENT_H
#define PLANESHIPMENT_H

#include "shipment.h"
#include <QDate>
#include "../dbmanager.h"

class PlaneShipment : public Shipment {
public:
    PlaneShipment(int orderId);

    void calculateDate() override;

private :
    QDate shDate;
    void insertShipment();
};

#endif // PLANESHIPMENT_H
