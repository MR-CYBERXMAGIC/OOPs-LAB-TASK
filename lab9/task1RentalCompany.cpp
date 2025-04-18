#include<iostream>
#include<string>

using namespace std;

class Vehicle {
protected:
    string modelName;
    double rentalRate;

public:
    Vehicle(string modelName, double rentalRate) : modelName(modelName), rentalRate(rentalRate) {}
    virtual double getDailyRate() = 0;
    virtual void displayDetails() = 0;
};

class Car : public Vehicle {
public:
    Car(string modelName, double rentalRate) : Vehicle(modelName, rentalRate) {}
    double getDailyRate() override{
        return rentalRate;
    }
    void displayDetails() override {
        cout << "Car Model Name: " << modelName << endl;
        cout << "Car Rental Rate: " << rentalRate << "$" << endl;
    }
};

class Bike : public Vehicle {
public:
    Bike(string modelName, double rentalRate) : Vehicle(modelName, rentalRate) {}
    double getDailyRate() override {
        return rentalRate;
    }
    void displayDetails() override {
        cout << "Bike Model Name: " << modelName << endl;
        cout << "Bike Rental Rate: " << rentalRate << "$" << endl;
    }
};

int main(){
    Car C("Carolla",15);
    Bike B("YBR",8);
    cout << endl;
    C.displayDetails();
    cout << endl;
    B.displayDetails();
    cout << endl;
    return 0;
}