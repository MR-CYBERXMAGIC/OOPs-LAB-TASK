#include<iostream>
#include<string>
using namespace std;

class Patient {
    private:
        static int uniqueID;
        int patientID;
        string name;
        int testCount;
        string *test;

    public: 

        Patient() {
            patientID = uniqueID++;
            cout << "Enter patient name: ";
            cin >> name;
            cout << "Enter number of tests: ";
            cin >> testCount;
            cin.ignore(); 
            test = new string[testCount];
            for (int i = 0; i < testCount; i++) {
                cout << "Enter test "<< i + 1<<" : ";
                getline(cin, test[i]);
            }
        }

        Patient (Patient &name) {
            this->patientID = name.patientID;
            this->name = name.name;
            cout << "Enter number of tests: ";
            cin >> testCount;
            test = new string[testCount];
            cin.ignore();
            for (int i = 0; i < testCount; i++) {
                cout << "Enter test "<< i + 1<<" : ";
                getline(cin, test[i]);
            }
        }

        ~Patient() {
            delete[] test;
        }

        void display() {
            cout << "Patient ID: " << patientID << endl;
            cout << "Name: " << name << endl;
            cout << "Test Count: " << testCount << endl;
            for (int i = 0; i < testCount; i++) {
                cout << "Test " << i + 1 << ": " << test[i] << endl;
            }
        }
}; 

int Patient::uniqueID = 1;

int main() {
    cout << "Creating Patient Record" << endl;
    Patient patient1;
    patient1.display();

    cout << "\nCreating a Copy of the Patient Record" << endl;
    Patient patient2 = patient1; 
    patient2.display();
}