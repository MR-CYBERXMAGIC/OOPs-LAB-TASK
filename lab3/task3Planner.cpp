#include <iostream>
using namespace std;

class Planner {
    private:
        const int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};  
        string** tasks;  

        bool checker(int month , int day) {
            if(month < 1 || month > 12 ) {
                return false;
            } else {
                if(day < 1 || day > months[month - 1]) {
                    return false;
                } else {
                    return true;
                }
            }
        }

    
    public:

        // Constructor
        Planner() {
            tasks = new string*[12];
            for (int i = 0; i < 12; i++) {
                tasks[i] = new string[months[i]];
            }

            for( int i = 0; i < 12; i++) { 
                for(int j = 0; j < months[i]; j++) {
                    tasks[i][j] = "No task";
                }
            }
        }

        // add/update task
        void addTask() {
            int month, day;
            cout << "Enter the month (1-12): ";
            cin >> month;
            cout << "Enter the day (1-" << months[month-1] << " ): ";
            cin >> day;
            if(!(checker(month, day))) {
                cout << "Invalid date. Please enter a valid date." << endl; 
                addTask();
            }
            cout << "Enter the task: ";
            cin.ignore();
            getline(cin, tasks[month-1][day-1]);

        }

        // Display tasks
        void displayTasks() {
            cout << "----------------Task to do----------------" << endl;
            for (int i = 0; i < 12; i++) {
                int print = 1;
                for (int j = 0; j < months[i]; j++) { 
                    if(tasks[i][j] != "No task") {
                    if(print == 1) { 
                        cout << "Month: " << i + 1 << endl;
                        print = 0;
                    }
                    cout << "Day: " << j + 1 << " - " << tasks[i][j] << endl;
                }
            }
            if (print == 0) {
                cout << endl;
            }
            }
        }

        // Remove tasks
        void removeTask() {
            int month, day;
            cout << "Enter the month (1-12): ";
            cin >> month;
            cout << "Enter the day (1-" << months[month-1] << "  ): ";
            cin >> day;
            if(!(checker(month, day))) {
                cout << "Invalid date. Please enter a valid date." << endl; 
                removeTask();
            }
            tasks[month-1][day-1] = "No task";
            cout << "Task removed successfully." << endl;
        }
        
        // Destructor
        ~Planner() {
            for (int i = 0; i < 12; i++) {
                delete[] tasks[i];
            }
            delete[] tasks;
        }
     
    };
    
    int main() {
        Planner planner;
        
        int choice;
        while (true) { 
            cout << "1. Add/update task" << endl;
            cout << "2. Display tasks" << endl;
            cout << "3. Remove task" << endl;
            cout << "4. Exit" << endl;
            cin >> choice;
            switch (choice) {
            case 1:
                planner.addTask();
                break;
            case 2:
                planner.displayTasks();
                break;
            case 3:
                planner.removeTask();
                break;
            case 4:
                return 0;
            }
        }
    }
    