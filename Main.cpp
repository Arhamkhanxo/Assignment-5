#include "employee.h"
#include "order.h"
#include <iostream>

using namespace std;

int main() {
    int choice;

    do {
        cout << "\nMain Menu\n";
        cout << "1. Employee Management\n";
        cout << "2. Order Management\n";
        cout << "3. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        if (choice == 1) {
            vector<Employee> employees;
            double limit;

            inputEmployees(employees);

            cout << "Enter yearly salary limit: ";
            cin >> limit;

            saveHighSalaryEmployees(employees, limit);
            displayHighSalaryEmployees();
        }
        else if (choice == 2) {
            vector<Order> orders;
            const double LIMIT = 5000;

            inputOrders(orders);
            savePriorityOrders(orders, LIMIT);
            displayPriorityOrders();
        }
        else if (choice == 3) {
            cout << "Exiting program...\n";
        }
        else {
            cout << "Invalid option.\n";
        }

    } while (choice != 3);

    return 0;
}
