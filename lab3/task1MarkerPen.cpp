#include <iostream>
using namespace std;

class MarkerPen {
    private:
        string brand;
        string color;
        int inkLevel;
        bool refillability;

    public:
        // Constructor
        MarkerPen(string brand, string color, int inkLevel, bool refillability) { 
            this->brand = brand;
            this->color = color;
            this->inkLevel = inkLevel;
            this->refillability = refillability;
        }

        // Refill function 
        void refill() {
            if (refillability) {
                cout << "Refilling the pen..." << endl << endl;
                inkLevel = 100;
            } else {
                cout << "This pen is not refillable." << endl << endl;
            }
        }
    
        // Write function 
        void write() {
            if (inkLevel > 0) {
                cout << "Writing..." << endl;
                inkLevel--;
            } else {
                cout << "Out of ink!" << endl;
                char choice;
                cout << "Do you want to refill? (y/n): ";
                cin >> choice;
                if (choice == 'y' || choice == 'Y') {
                    refill();
                } else {
                    cout << "Cannot write! Change the pen!" << endl << endl;
                }
            }
        }

        // Status Function
        void status() {
            cout << "Brand: " << brand << endl;
            cout << "Color: " << color << endl;
            cout << "Ink Level: " << inkLevel << "%" << endl;
            cout << "Refillable: " << (refillability ? "Yes" : "No") << endl << endl;
        }
};

int main() {

    MarkerPen pen1("Parker", "Blue", 1, true);

    pen1.status();

    pen1.write();
    pen1.write(); 

    pen1.status();

    return 0;
}
