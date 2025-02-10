#include <iostream>
using namespace std;

struct Student {
    string name;
    int rollNumber;
    float *marks = new float[5];
} typedef Student;

Student findTopper(Student* students, int n) {
    int topIndex = 0;
    float highestMarks = 0, sum = 0;

    for (int i = 0; i < n; i++) {
        sum = 0;
        for (int j = 0; j < 5; j++) {
            sum += students[i].marks[j]; 
        }
        if (sum > highestMarks) {
            highestMarks = sum;
            topIndex = i;
        }
    }
    return students[topIndex];
}

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    Student* students = new Student[n];

    // Input student data
    for (int i = 0; i < n; i++) {
        cout << "\nEnter Student " << i + 1 << " Name: ";
        cin >> students[i].name;
        cout << "Enter Roll Number: ";
        cin >> students[i].rollNumber;
        for(int j = 0; j < 5; j++) {
            cout<<"Enter student " << i + 1 << " Subject Marks " << j + 1<<" : ";
            cin >> students[i].marks[j];
        }
    }

    // Highest marks student
    Student topper = findTopper(students, n);

    cout << "\n****** Student with Highest Marks ******\n";
    cout << "Name: " << topper.name << endl;
    cout << "Roll Number: " << topper.rollNumber << endl;
    cout << "Marks: ";
    for (int j = 0; j < 5; j++) {
        cout << topper.marks[j] << " ";
    }
    cout << endl;

    for (int i = 0; i < n; i++) {
        delete[] students[i].marks; 
    }
    delete[] students;

    return 0;
}
