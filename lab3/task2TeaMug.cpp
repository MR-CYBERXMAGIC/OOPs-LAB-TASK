#include <iostream>
using namespace std;

class TeaMug {
    private:
        string brand;
        string color;
        int capacity;
        int currentFillLevel;

    public:
        // Constructor
        TeaMug(string brand, string color, int capacity, int currentFillLevel) { 
            this->brand = brand;
            this->color = color;
            this->capacity = capacity;
            this->currentFillLevel = currentFillLevel;
        }

        // Empty checker
        void check() {
            if (currentFillLevel) {
                cout << "The mug is filled with " << currentFillLevel << " ml of liquid." << endl;
            } else {
                cout << "The mug is empty." << endl;
            }
        }

        // Refilling function
        void refill() {
            if (currentFillLevel < capacity) {
                currentFillLevel  = capacity;
                cout << "Mug is now full." << endl;
            } else {
                cout << "The mug is already full." << endl;
            }
        }

        // sip function
        void sipTea() {
            if (currentFillLevel > 0) { 
                cout << "You have take s sip of tea from the mug." << endl;
                currentFillLevel--;  
            } else {
                char choice;
                cout << "The mug is empty. Do you want to fill it?(y/n)";
                cin >> choice;
                if (choice == 'y' || choice == 'Y') {
                    refill();
                } else {
                    cout << "Cannot Drink more tea!" << endl << endl;
                }
            }
        }
};

int main() {

    TeaMug mug1("Tapal", "green", 500, 0);
    mug1.check();
    mug1.sipTea();
    mug1.check();
    return 0;

}