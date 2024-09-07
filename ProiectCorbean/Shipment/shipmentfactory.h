#ifndef SHIPMENTFACTORY_H
#define SHIPMENTFACTORY_H

#include "shipment.h"

class ShipmentFactory {
public:
    static Shipment* createShipment(const QString& type, int orderId);
};

#endif // SHIPMENTFACTORY_H
