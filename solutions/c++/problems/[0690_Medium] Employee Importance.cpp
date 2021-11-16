#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    Employee *getEmployee(vector<Employee *> employees, int id) {
        for (Employee *employee: employees) {
            if (employee->id == id) {
                return employee;
            }
        }
        return employees[id];
    }

    int getImportance(vector<Employee *> employees, int id) {
        Employee *curr = getEmployee(employees, id);
        int totalImportance = curr->importance;
        for (int subordinate: curr->subordinates) {
            totalImportance += getImportance(employees, subordinate);
        }
        return totalImportance;
    }
};