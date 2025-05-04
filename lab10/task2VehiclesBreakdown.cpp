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
            cout << "Name: " << name << endl;
            cout << "Year: " << year << endl;
            cout << "Extra Data: " << extraData << endl;
            cout << "Certification: " << certification << endl;
            cout << endl;
        }

        in.close();
    }
    catch(runtime_error e) {
        cerr << e.what() << endl;
    }
}