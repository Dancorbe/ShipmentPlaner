#ifndef SUBORDER_H
#define SUBORDER_H

#include <QString>
#include <QStringList>
#include <QDate>

class SubOrder {
public:
    SubOrder();








//============================================get+set=========================================
    QString getOrderId() const;
    void setOrderId(const QString &newOrderId);

    QString getClientId() const;
    void setClientId(const QString &newClientId);


    QStringList getProductId() const;
    void setProductId(const QStringList &newProductId);



    bool getConfirmed() const;
    void setConfirmed(bool newConfirmed);

    QString getAddress() const;
    void setAddress(const QString &newAddress);

    QString getClientName() const;
    void setClientName(const QString &newClientName);

    QString getContinent() const;
    void setContinent(const QString &newContinent);

    QDate getDate() const;
    void setDate(const QDate &newDate);

    QStringList getProductName() const;
    void setProductName(const QStringList &newProductName);

    void insetName(QString name);

private:
    QString orderId;
    QString clientId;
    QString clientName;
    QDate date;
    QStringList productId;
    QStringList productName;
    bool confirmed;
    QString address;
    QString continent;
};

#endif // SUBORDER_H
