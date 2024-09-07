#include "SubOrder.h"

SubOrder::SubOrder()
    : confirmed(false) {}














//====================================================GETTER +SETTER===============================================================

QString SubOrder::getOrderId() const
{
    return orderId;
}

void SubOrder::setOrderId(const QString &newOrderId)
{
    this->orderId=newOrderId;
}
QString SubOrder::getClientId() const
{
    return clientId;
}

void SubOrder::setClientId(const QString &newClientId)
{
    clientId = newClientId;
}


QStringList SubOrder::getProductId() const
{
    return productId;
}

void SubOrder::setProductId(const QStringList &newProductId)
{
    productId = newProductId;
}



bool SubOrder::getConfirmed() const
{
    return confirmed;
}

void SubOrder::setConfirmed(bool newConfirmed)
{
    confirmed = newConfirmed;
}

QString SubOrder::getAddress() const
{
    return address;
}

void SubOrder::setAddress(const QString &newAddress)
{
    address = newAddress;
}

QString SubOrder::getClientName() const
{
    return clientName;
}

void SubOrder::setClientName(const QString &newClientName)
{
    clientName = newClientName;
}

QString SubOrder::getContinent() const
{
    return continent;
}

void SubOrder::setContinent(const QString &newContinent)
{
    continent = newContinent;
}

QDate SubOrder::getDate() const
{
    return date;
}

void SubOrder::setDate(const QDate &newDate)
{
    date = newDate;
}

QStringList SubOrder::getProductName() const
{
    return productName;
}

void SubOrder::setProductName(const QStringList &newProductName)
{
    productName = newProductName;
}

void SubOrder::insetName(QString name)
{
    this->productName.append(name);
}

