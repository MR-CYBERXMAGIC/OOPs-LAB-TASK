#include <iostream>
#include <iomanip> 
using namespace std;

struct Students {
    string name;
    int rollnumber;
    float *marks = new float[5];
} typedef Students;

char grade(float avg) {
    if (avg >= 80.0) return 'A';
    if (avg >= 70.0) return 'B';
    if (avg >= 60.0) return 'C';
    if (avg >= 50.0) return 'D';
    return 'F';
}

void report(const Students& student, float avg, char grade) {
    cout << "\n*************************************************\n";
    cout << "              STUDENT REPORT CARD                \n";
    cout << "*************************************************\n";
    cout << " Name      : " << student.name << endl;
    cout << " Roll No.  : " << student.rollnumber << endl;
    cout << "-------------------------------------------------\n";
    cout << " Subject Marks: \n";
    for (int i = 0; i < 5; i++) {
        cout << "  - Subject " << i + 1 << " : " << student.marks[i] << endl;
    }
    cout << "-------------------------------------------------\n";
    cout << " Average Marks: " << avg << endl;
    cout << " Grade        : " << grade << endl;
    cout << "*************************************************\n\n";
}

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid number of students!\n";
        return 0;
    }

    Students *students = new Students[n];
    float *avg = new float[n];
    char *grades = new char[n];

    // Data Entry
    for (int i = 0; i < n; i++) {
        cout << "\n================== Entering Data for Student " << i + 1 << " ==================\n";
        cout << "Enter Name: ";
        cin.ignore();  
        getline(cin, students[i].name);
        cout << "Enter Roll Number: ";
        cin >> students[i].rollnumber;

        for (int j = 0; j < 5; j++) {
            cout << "Enter Marks for Subject " << j + 1 << ": ";
            cin >> students[i].marks[j];
        }
    }

    // Calculating Average and Assigning Grades
    for (int i = 0; i < n; i++) {
        float sum = 0;
        for (int j = 0; j < 5; j++) {
            sum += students[i].marks[j];
        }
        avg[i] = sum / 5.0;
        grades[i] = grade(avg[i]);
    }

    // Printing Student Reports
    for (int i = 0; i < n; i++) {
        report(students[i], avg[i], grades[i]);
    }

    for (int i = 0; i < n; i++) {
        delete[] students[i].marks;  
    }
    delete[] students;
    delete[] avg;
    delete[] grades;

    return 0;
}
