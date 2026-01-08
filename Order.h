#ifndef ORDER_H
#define ORDER_H

#include <string>
#include <vector>

using namespace std;

struct Order {
    int orderID;
    string customerName;
    int items;
    double price;
};

void inputOrders(vector<Order>& orders);
double calculateTotal(int items, double price);
void savePriorityOrders(const vector<Order>& orders, double threshold);
void displayPriorityOrders();

#endif
