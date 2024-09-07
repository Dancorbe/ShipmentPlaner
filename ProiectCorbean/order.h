#ifndef ORDER_H
#define ORDER_H

#include <QList>
#include "SubOrder.h"

class Order {
public:
    static Order& instance();

    QList<SubOrder*> subOrders() const;
    void addSubOrder(SubOrder* subOrder);
    void removeSubOrder(SubOrder* subOrder);

private:
    Order();
    ~Order();

    Order(const Order&) = delete;
    Order& operator=(const Order&) = delete;

    static Order* s_instance;
    QString continent;
    QList<SubOrder*> subOrdersList;
};

#endif // ORDER_H
