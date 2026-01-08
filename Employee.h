#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
#include <vector>
using namespace std;
struct Employee {
    int id;
    string name;
    double monthlySalary;
};
void inputEmployees(vector<Employee>& employees);
double calculateYearlySalary(double monthlySalary);
void saveHighSalaryEmployees(const vector<Employee>& employees, double threshold);
void readAndDisplayHighSalaryEmployees();
#endif
