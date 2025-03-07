#include <iostream>
#include <string>
using namespace std;

class Person {
    private:
        string name;
        int age;
    public:
        Person(string n, int a): name(n), age(a) {}

        void diplayPersonDetails(){
            cout << "Name: " << name << endl;
            cout << "Age: " << age << endl;
        }
};

class Teacher : public Person {
    private:
        string subject; 
    public:
        Teacher(string n, int a, string s): Person(n, a), subject(s) {}
        void diplayTeacherDetails() {
            diplayPersonDetails();
            cout << "Subject: " << subject << endl;
        }
};

class Researcher : public Teacher {
    private:
        string researchArea;
    public:
        Researcher(string n, int a, string s, string ra): Teacher(n, a, s), researchArea (ra) {}
        void diplayResearcherDetails() {
            diplayTeacherDetails();
            cout << "Research Area: " << researchArea << endl;
        }
};

class Professor : public Researcher {
    private:
        int publications;
    public:
        Professor(string n, int a, string s, string ra, int p): Researcher(n , a, s, ra), publications(p) {} 
        void diplayProfessorDetails() {
            diplayResearcherDetails();
            cout << "Publications: " << publications << endl;
        }
};

int main() {
    Professor p("Shahid Asraf" , 40, "Mathematics", "Machine Learning", 20);
    p.diplayProfessorDetails();
    return 0;
}