#include "order.h"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

void inputOrders(vector<Order>& orders) {
    int count;
    cout << "How many orders? ";
    cin >> count;

    while (count <= 0) {
        cout << "Enter a valid number: ";
        cin >> count;
    }

    for (int i = 0; i < count; i++) {
        Order ord;

        cout << "\nOrder " << i + 1 << endl;
        cout << "Order ID: ";
        cin >> ord.orderID;

        cin.ignore();
        cout << "Customer Name: ";
        getline(cin, ord.customerName);

        cout << "Number of Items: ";
        cin >> ord.items;

        cout << "Price per Item: ";
        cin >> ord.price;

        orders.push_back(ord);
    }
}

double calculateTotal(int items, double price) {
    return items * price;
}

void savePriorityOrders(const vector<Order>& orders, double threshold) {
    ofstream file("priority_orders.txt");

    if (!file) {
        cout << "File error.\n";
        return;
    }

    int saved = 0;

    for (int i = 0; i < orders.size(); i++) {
        double total = calculateTotal(orders[i].items, orders[i].price);

        if (total > threshold) {
            file << orders[i].orderID << " "
                 << orders[i].customerName << " "
                 << total << endl;
            saved++;
        }
    }

    file.close();
    cout << saved << " priority order(s) saved.\n";
}

void displayPriorityOrders() {
    ifstream file("priority_orders.txt");

    if (!file) {
        cout << "No priority orders file found.\n";
        return;
    }

    int id;
    string name;
    double total;

    cout << "\nPriority Orders:\n";

    while (file >> id >> name >> total) {
        cout << "Order ID: " << id
             << ", Customer: " << name
             << ", Total: Rs "
             << fixed << setprecision(2) << total << endl;
    }

    file.close();
}
