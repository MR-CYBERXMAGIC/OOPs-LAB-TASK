#include <iostream>
#include <string>
using namespace std;

class manageEvent {
private:
    string event1Participant[5] = {""}, event2Participant[5] = {""};
    int event1ParticipantNum = 0, event2ParticipantNum = 0;

public:
    
    //Task 1: Register event Participants
    void registerEventParticipant(int eventNumber) { 
        //Event validator
        if (eventNumber < 1 || eventNumber > 2) { 
            cout << "Invalid event number. Please enter 1 or 2." << endl;
            cin >> eventNumber;
            cin.ignore();
            registerEventParticipant(eventNumber);
            return;
        }

        string name;
        //Event 1 Registration
        if (eventNumber == 1) {
            cout << "Enter participant name for Event 1" << endl;
            for(int i = 0; i < 5; i++) {
                cout << "Participant " << i + 1 << " name: ";
                getline(cin,name);

                if(name == "") break; 

                event1Participant[i] = name;
                event1ParticipantNum++;
            }
        }
        
        //Event 2 Registration
        if (eventNumber == 2) {
            cout << "\nEnter participant name for Event 2" << endl;
            for(int i = 0; i < 5; i++) {
                cout << "Participant " << i + 1 << " name: ";
                getline(cin,name);

                if(name == "") break; 
                
                event2Participant[i] = name;
                event2ParticipantNum++;
            }
        }
    }

    //Task 2: Attendance Checker
    void attendanceChecker() {
        string name;
        cout<<"\nAttendance checker\nEnter name: ";
        cin>> name;
        cin.ignore();
        int found = 0;
        // Checking in Event 1 
        for(int i = 0; i < event1ParticipantNum; i++) {
            if(name == event1Participant[i]) {
                cout << "Participant " << name << " is attending Event 1." << endl;
                found = 1;
                break;
            }
        }

        // Checking in Event 2
        for(int i = 0; i < event2ParticipantNum; i++) {
            if(name == event2Participant[i]) {
                cout << "Participant " << name << " is attending Event 2." << endl;
                found = 1;
                break;
            }       
        }

        if(!found) {
            cout<<"Participant "<<name<<" is not attending any event."<<endl;
        }

        return;
    }

    //Task 3: Calculate Donations
    void calculateDonations() {
        cout << "\nTotal donations = " << 10 * (event1ParticipantNum + event2ParticipantNum) << endl;
        return;
    }

    //Task 4: Display Event Details
    void displayEventDetails() {
        
        // Event 1: details
        cout << "\nEvent 1 Details:" << endl;
        cout << "Number of participants: " << event1ParticipantNum << endl;
        cout << "Participants: ";
        if (event1ParticipantNum == 0) cout << "None";
        for(int i = event1ParticipantNum - 1; i >= 0; i--) { 
            cout << event1Participant[i] << " ";
        }
        cout << endl;
        // Event 2: details
        cout << "\nEvent 2 Details:" << endl;
        cout << "Number of participants: " << event2ParticipantNum << endl;
        cout << "Participants: ";
        if (event2ParticipantNum == 0) cout << "None";
        for(int i = event2ParticipantNum - 1; i >= 0; i--) { 
            cout << event2Participant[i] << " ";
        }
        cout << endl;
    }

    //Task 5: Event popularity bar chart
    void eventPopularityBarChart() {
        cout<<"Event Popularity bar chart\n" << endl;
        cout<<"Event 1: ";
        for(int i = 1; i <= event1ParticipantNum; i++) {
            cout<< "* ";
        }
        cout<<"\nEvent 2: ";   
        for(int i = 1; i <= event2ParticipantNum; i++) {
            cout<< "* ";
        }
        cout<< endl;
    }
};

int main() {

    manageEvent Event;
    
    //Event.registerEventParticipant(0) //for testing wrong input
    Event.registerEventParticipant(1);
    Event.registerEventParticipant(2);
    
    Event.attendanceChecker();

    Event.calculateDonations();

    Event.displayEventDetails();

    Event.eventPopularityBarChart();
    
}