#include <iostream>
#include <string>
using namespace std;

class Car {
    private:
        static int uniqueID; 
        int registrationNumber;
        string model;
        string owner;

    public:
        Car () {
            registrationNumber = uniqueID++;
            cout << "Enter owner name";
            getline(cin,owner);
            cout << "Enter model name";
            getline(cin,model);
        }

        void setModel () {
            cout << "Enter model name";
            getline(cin,model);
        }

        void setOwner () {
            cout << "Enter owner name";
            getline(cin,owner);
        }


        Car (Car &car) {
            registrationNumber = car.registrationNumber;
            model = car.model;
            cout << "Enter new owner name";
            cin.ignore();
            getline(cin,owner);
        }

        void display () {
            cout << "Registration Number :" << registrationNumber << endl;
            cout << "Model : " << model << endl;
            cout << "Owner : " << owner << endl;
        }
};

int Car::uniqueID = 1;

int main() {
    Car car1;
    car1.display();

    Car car2 = car1;
    car2.display();

}