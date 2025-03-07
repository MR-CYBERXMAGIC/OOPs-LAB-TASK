#include <iostream>
#include <string>
using namespace std;

class Account {
    private:
        int accountNumber;
        float balance;
    public:
    Account(int n, float b) : accountNumber(n) , balance(b) {}
    void displayDetails() {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
    }
};

class SavingsAccount : public Account {
    private:
        float interestRate;
    public:
    SavingsAccount(int n, float b, float i) : Account(n, b), interestRate(i) {}
    void displayDetails() {
        Account:: displayDetails();
        cout << "Interest Rate: " << interestRate << endl;
    }
};

class CurrentAccount : public Account {
    private:
        float overdraftLimit;
    public:
        CurrentAccount(int n, float b, float o) : Account(n, b), overdraftLimit(o) {}
        void displayDetails() {
            Account::displayDetails();
            cout << "Overdraft Limit: " << overdraftLimit << endl;
        }
};

int main() {
    SavingsAccount sa(12345, 10000.0, 0.05);
    CurrentAccount ca(67890, 5000.0, 10000.0);
    
    cout << "Savings Account Details:" << endl;
    sa.displayDetails();
    
    cout << "\nCurrent Account Details:" << endl;
    ca.displayDetails();
    return 0;
    
}