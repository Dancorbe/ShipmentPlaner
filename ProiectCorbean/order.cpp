#include "Order.h"

Order* Order::s_instance = nullptr;

Order& Order::instance() {
    if (!s_instance) {
        s_instance = new Order();
    }
    return *s_instance;
}

Order::Order() {}

Order::~Order() {
    qDeleteAll(subOrdersList);
}

QList<SubOrder*> Order::subOrders() const {
    return subOrdersList;
}

void Order::addSubOrder(SubOrder* subOrder) {
    subOrdersList.append(subOrder);
}

void Order::removeSubOrder(SubOrder* subOrder) {
    subOrdersList.removeAll(subOrder);
}
