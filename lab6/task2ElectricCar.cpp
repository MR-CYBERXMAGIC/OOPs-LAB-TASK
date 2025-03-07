#include <iostream>
using namespace std;

class Vehical{
    private:
        string brand;
        int speed;
    public:
        Vehical(string b, int s) : brand(b) , speed(s) {} 
        void displayVehicalDetails() {
            cout << "Brand: " << brand << endl;
            cout << "Speed: " << speed << endl;
        }
};

class Car : Vehical {
    private:
        int seats;
    public:
        Car (string b, int s, int seat) : Vehical(b, s), seats(seat) {}
        void displayCarDetails() {
            displayVehicalDetails();
            cout << "Seats: " << seats << endl;  
        }
};

class ElectricCar : Car {
    private:
        int batteryLife;
    public: 
        ElectricCar( string b, int s, int seat, int bl) : Car(b, s, seat), batteryLife(bl) {}
        void displayElectricCarDetails() {
            displayCarDetails();
            cout << "Battery Life: " << batteryLife << endl;
        }
};



int main() {
    ElectricCar EV("Tesla", 200, 4 , 160);
    EV.displayElectricCarDetails();
}