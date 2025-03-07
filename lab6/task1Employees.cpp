#include<iostream>
#include<string>
using namespace std;

class Employee{
    private:
        string name;
        float salary;
    public:
        Employee(string n , float s) : name(n), salary(s) {}
        void displayDetails() {
            cout << "Name: " << name << endl;
            cout << "Salary: " << salary << endl;
        }
};

class Manager : Employee {
    private:
        float bonus;
    public:
        Manager(string n , float s , float b) : Employee(n,s), bonus(b) {}
        void managerDisplayDetails() {
            displayDetails();
            cout<< "Bonus" << bonus << endl;
        }
}; 


int main() {

    Manager m("a", 1.3, 1.4);
    m.managerDisplayDetails();

}
