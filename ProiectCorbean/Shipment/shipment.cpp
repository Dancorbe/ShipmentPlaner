#include "shipment.h"

Shipment::Shipment(int orderId, const QString& shipmentType)
    : orderId(orderId), shipmentType(shipmentType) {}

int Shipment::getOrderId() const {
    return orderId;
}

QString Shipment::getShipmentType() const {
    return shipmentType;
}

void Shipment::setShipmentDetails(const QString& type) {
    shipmentType = type;
}
