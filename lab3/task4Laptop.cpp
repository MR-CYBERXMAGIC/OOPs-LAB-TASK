#include <iostream>
using namespace std;

class Laptop {
    private:
        string brand;
        string model;
        string processor;
        int ram;
        int storage;
        bool isOn;
    
    public:

        // Constructor
        Laptop() {
            cout << "Enter brand name: ";
            cin >> brand;
            cout << "Enter model name: ";
            cin >> model;
            cout << "Enter processor name: ";
            cin >> processor;
            cout << "Enter RAM: ";
            cin >> ram;
            cout << "Enter storage: ";
            cin >> storage;
            isOn = false;
        }

        // Turn on the laptop
        void turnOn() {
            if (!isOn) {
                isOn = true;
                cout << "Laptop is now ON.\n";
            } else {
                cout << "Laptop is already ON.\n";
            }
        }

        // Turn off the laptop
        void turnOff() {
            if (isOn) {
                isOn = false;
                cout << "Laptop is now OFF.\n";
            } else {
                cout << "Laptop is already OFF.\n";
            }
        }


        // Run a program
        void runProgram() {
            string program;
            cout << "Enter the name of the program to run: ";
            cin >> program;
            if (isOn) {
                cout << "Running " << program << endl;
            } else {
                cout << "Laptop is OFF. Please turn it ON first." << endl;

            }
        }

        // Display laptop specifications
        void showSpecs() {
            cout << "\nLaptop Specifications:" << endl;
            cout << "Brand: " << brand << endl; 
            cout << "Model: " << model << endl;
            cout << "Processor: " << processor << endl;
            cout << "RAM: " << ram << "GB" << endl;
            cout << "Storage: " << storage << "GB" << endl;
        }

        // Compare two laptops
        void compareLaptops(Laptop l2) {
            cout << "\n--- Laptop Comparison ---\n";
            cout << "Brand: " << brand << " vs " << l2.brand << endl;
            cout << "Model: " << model << " vs " << l2.model << endl;
            cout << "Processor: " << processor << " vs " << l2.processor << endl;
            cout << "RAM: " << ram << "GB vs " << l2.ram << "GB" << endl;
            cout << "Storage: " << storage << "GB vs " << l2.storage << "GB" << endl;
        }


};

int main() {
    Laptop laptop1 , laptop2;

    laptop1.showSpecs();
    laptop2.showSpecs();
    laptop1.compareLaptops(laptop2);

    laptop1.runProgram();
    laptop1.turnOn();
    laptop1.runProgram();
    return 0;

}