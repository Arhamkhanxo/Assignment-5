#include "employee.h"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

void inputEmployees(vector<Employee>& employees) {
    int n;
    cout << "Enter number of employees: ";
    cin >> n;

    while (n <= 0) {
        cout << "Please enter a positive number: ";
        cin >> n;
    }

    for (int i = 0; i < n; i++) {
        Employee e;

        cout << "\n--- Employee " << (i + 1) << " ---" << endl;
        cout << "Enter Employee ID: ";
        cin >> e.id;

        cout << "Enter Employee Name: ";
        cin.ignore();
        getline(cin, e.name);

        cout << "Enter Monthly Salary: ";
        cin >> e.monthlySalary;

        while (e.monthlySalary < 0) {
            cout << "Salary cannot be negative. Enter again: ";
            cin >> e.monthlySalary;
        }

        employees.push_back(e);
    }

    cout << "\n" << n << " employee(s) added successfully!\n";
}

double calculateYearlySalary(double monthlySalary) {
    return monthlySalary * 12;
}

void saveHighSalaryEmployees(const vector<Employee>& employees, double threshold) {
    ofstream file("high_salary.txt");

    if (!file) {
        cout << "Error: File could not be opened for writing." << endl;
        return;
    }

    int count = 0;

    for (int i = 0; i < employees.size(); i++) {
        double yearlySalary = calculateYearlySalary(employees[i].monthlySalary);

        if (yearlySalary > threshold) {
            file << employees[i].id << " "
                 << employees[i].name << " "
                 << yearlySalary << endl;
            count++;
        }
    }

    file.close();

    if (count > 0) {
        cout << "\nSuccess! " << count << " employee(s) with yearly salary above "
             << threshold << " saved to high_salary.txt\n";
    } else {
        cout << "\nNo employees found with yearly salary above " << threshold << endl;
    }
}

void readAndDisplayHighSalaryEmployees() {
    ifstream file("high_salary.txt");

    if (!file) {
        cout << "Error: File could not be opened for reading." << endl;
        cout << "Make sure high_salary.txt exists in the current directory." << endl;
        return;
    }

    int id;
    string name;
    double yearlySalary;

    cout << "\n========================================" << endl;
    cout << "  Employees with High Yearly Salary" << endl;
    cout << "========================================" << endl;

    bool hasData = false;

    while (file >> id) {
        file.ignore();
        getline(file, name, ' ');
        file >> yearlySalary;
        file.ignore();

        cout << "ID: " << id
             << " | Name: " << name
             << " | Yearly Salary: Rs " << fixed << setprecision(2) << yearlySalary << endl;

        hasData = true;
    }

    if (!hasData) {
        cout << "No records found in the file." << endl;
    }

    cout << "========================================" << endl;

    file.close();
}
