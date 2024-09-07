#ifndef SHIPMENT_H
#define SHIPMENT_H

#include <QString>

class Shipment {
public:
    Shipment(int orderId, const QString& shipmentType);
    virtual ~Shipment() = default;

    int getOrderId() const;
    QString getShipmentType() const;


    virtual void calculateDate() = 0;
 int orderId;
protected:
    void setShipmentDetails(const QString& type);

private:

    QString shipmentType;
};

#endif // SHIPMENT_H
