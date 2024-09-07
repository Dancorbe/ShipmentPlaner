#ifndef TRAINSHPMENT_H
#define TRAINSHPMENT_H

#include "shipment.h"
#include<QDate>
#include "../dbmanager.h"

class TrainShipment : public Shipment {
public:
    TrainShipment(int orderId);

    void calculateDate() override;

private:

    QDate shDate;

    void insertShipment();
};

#endif // TRAINSHPMENT_H
