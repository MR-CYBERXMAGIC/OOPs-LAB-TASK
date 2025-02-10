#include <iostream>
#include <iomanip> 
using namespace std;

struct employees {
    int employeeID;
    string name;
    string department;
    int salary;
} typedef employees;

void displayEmployees(employees* emps, int size) {
    if (size == 0) {
        cout << "\nNo employees available to display.\n";
        return;
    }

    cout << "\n============================================================\n";
    cout << setw(10) << "ID" << setw(20) << "Name" << setw(20) << "Department" << setw(10) << "Salary" << endl;
    cout << "------------------------------------------------------------\n";

    for (int i = 0; i < size; i++) {
        cout << setw(10) << emps[i].employeeID
             << setw(20) << emps[i].name
             << setw(20) << emps[i].department
             << setw(10) << emps[i].salary << endl;
    }
    cout << "============================================================\n";
}

void searchEmployee(employees* emps, int size) {
    if (size == 0) {
        cout << "\nNo employees available to search.\n";
        return;
    }

    int id;
    cout << "\nEnter the Employee ID to search: ";
    cin >> id;

    bool found = false;
    for (int i = 0; i < size; i++) {
        if (emps[i].employeeID == id) {
            cout << "\n==================== Employee Found ====================\n";
            cout << "ID: " << emps[i].employeeID << "\nName: " << emps[i].name
                 << "\nDepartment: " << emps[i].department << "\nSalary: " << emps[i].salary;
            cout << "\n=======================================================\n";
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "\n Employee with ID " << id << " not found!\n";
    }
}

int main() {
    int n;
    cout << "Enter total number of employees: ";
    cin >> n;

    if (n <= 0) {
        cout << "\nInvalid number of employees!\n";
        return 0;
    }

    employees* emps = new employees[n];

    cout << "\nEnter Employee Details:\n";
    for (int i = 0; i < n; i++) {
        cout << "\n---------------- Employee " << i + 1 << " ----------------\n";
        cout << "Enter Employee ID: ";
        cin >> emps[i].employeeID;
        cout << "Enter Name: ";
        cin.ignore();  
        getline(cin, emps[i].name);
        cout << "Enter Department: ";
        getline(cin, emps[i].department);
        cout << "Enter Salary: ";
        cin >> emps[i].salary;
    }

    int choice;
    do {
        cout << "\n==================== Employee Management System ====================\n";
        cout << "1. Search Employee\n2. Display All Employees\n3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                searchEmployee(emps, n);
                break;
            case 2:
                displayEmployees(emps, n);
                break;
            case 3:
                cout << "\nExiting... Thank you!\n";
                break;
            default:
                cout << "\nInvalid choice! Please try again.\n";
        }
    } while (choice != 3);

    delete[] emps; 
    return 0;
}
