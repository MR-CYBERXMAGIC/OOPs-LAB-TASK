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

            string type, ID, name, yearStr, extraData, certification;

            getline(ss, type, ',');
            getline(ss, ID, ',');
            getline(ss, name, ',');
            getline(ss, yearStr, ',');
            getline(ss, extraData, ',');
            getline(ss, certification, ',');

            cout << "Type: " << type << endl;
            cout << "ID: " << ID << endl ;
            cout << "Name: " << name << endl;
            cout << "Year: " << yearStr << endl;
            cout << "Extra Data: " << extraData << endl;
            cout << "Certification: " << certification << endl;
            cout << endl;

            int yearInt;
            try {
                yearInt = stoi(yearStr);
            }
            catch (const invalid_argument e) {
                cerr << "Invalid year format in line: " << line << "\n";
                continue;
            } catch (const out_of_range e) {
                cerr << "Year value out of range in line: " << line << "\n";
                continue;
            }

        }
        in.close();
    }
    catch(runtime_error e) {
        cerr << e.what() << endl;
    }
}