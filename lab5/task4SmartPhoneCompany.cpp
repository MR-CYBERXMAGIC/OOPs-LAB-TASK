#include<iostream>
#include<string>
using namespace std;

class Battery {
    private:
        string batteryType;
        int batteryCapacity;
    public:
    // Constructor
    Battery(string type = "Non Removeable", int capacity = 5000) {
        batteryType = type;
        batteryCapacity = capacity;
    }

    void display() const {
        cout << "Battery Type: " << batteryType << endl;
        cout << "Battery Capacity: " << batteryCapacity << "mAh" << endl;
    }
};
class SmartPhone {
    private:
        string phoneModel;
        Battery battery; // Composition 
    public:
    // Constructor
    SmartPhone(string model, string type, int capacity) {
        phoneModel = model;
        battery = Battery(type, capacity);
    }

    void display() const {
        cout << "Smartphone Model: " << phoneModel << endl;
        battery.display();
    }
};




int main() {
    
    SmartPhone phone("Galaxy S24", "Non Removeable", 5000);
    phone.display();
    return 0;
}