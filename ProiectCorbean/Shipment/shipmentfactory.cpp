#include "shipmentfactory.h"
#include "planeshipment.h"
#include "trainshipment.h"

Shipment* ShipmentFactory::createShipment(const QString& type, int orderId) {
    if (type == "Plane") {
        return new PlaneShipment(orderId);
    } else if (type == "Train") {
        return new TrainShipment(orderId);
    } else {
        return nullptr;
    }
}
