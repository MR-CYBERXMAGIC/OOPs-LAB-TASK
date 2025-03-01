#include<iostream>
#include<string>
using namespace std;

class Professor {
    private:
        string name;
        string department;
    public:
        //Constructor
        Professor () {
            cout << "Enter professor name: ";
            cin.ignore();
            getline(cin,name);
            cout << "Enter professor department: ";
            getline(cin,department);
        }

        void display () const {
            cout << "Professor Name: " << name << endl;
            cout << "Professor Department: " << department << endl;
        }
};

class University {
    private:
        string name;
        Professor *professors;
        int professorCount;
    public:
        //Constructor
        University () {
            cout << "Enter university name: ";
            getline(cin,name);
            cout << "Enter total number of processors: ";
            cin >> professorCount;
            cin.ignore();
            professors = new Professor[professorCount];
        }

        void display () const {
            cout << "University name : " << name << endl;
            for (int i = 0; i < professorCount; i++) {
                professors[i].display();
            }    
        }

        ~University () {
            delete[] professors;
        }

};

int main() {
    University uni;
    uni.display();
    return 0;
}