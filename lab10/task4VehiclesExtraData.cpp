#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdexcept> 
using namespace std;

int main() {

    try {
        ifstream in("vehicles.txt");
        if(!in.is_open()) {
            throw runtime_error("Error: file opening failed");
        }

        string line;
        while(getline(in , line)) {
            if(line.empty() || line[0] == '#') continue;
            istringstream ss(line);

            string type, ID, name, year, extraData, certification;

            getline(ss, type, ',');
            getline(ss, ID, ',');
            getline(ss, name, ',');
            getline(ss, year, ',');
            getline(ss, extraData, ',');
            getline(ss, certification, ',');

            cout << "Type: " << type << endl;
            cout << "ID: " << ID << endl ;
            try {
                size_t colonPosition = extraData.find(':');
                if (colonPosition == string::npos) {
                    throw runtime_error("Colon is missing");
                }

                string valueStr = extraData.substr(colonPosition + 1);
                try {
                    if(type == "AutonomousCar") {
                        int SoftwareVersion = stoi(valueStr);
                        cout << "Software Version: " << SoftwareVersion << endl;
                    } else if (type == "ElectricVehicle") {
                        int batteryCapacity = stoi(valueStr);
                        cout << "Battery Capacity: " << batteryCapacity << endl;
                    } 
                }
                catch (const invalid_argument e) {
                    cerr << "Invalid data format: " << line << endl;
                    continue;
                } catch (const out_of_range e) {
                    cerr << "Data value out of range: " << line << endl;
                    continue;
                }
                
            } 
            catch(runtime_error e) {
                cerr << e.what() << endl;
            }
            cout << "Name: " << name << endl;
            cout << "Year: " << year << endl;
            if(type == "HybridTruck")  cout << "Extra Data: " << extraData << endl;
            cout << "Certification: " << certification << endl;
            cout << endl;
        }

        in.close();
    }
    catch(runtime_error e) {
        cerr << e.what() << endl;
    }
}