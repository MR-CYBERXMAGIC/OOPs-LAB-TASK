#include <iostream>
#include <string>
using namespace std;

class TourGuide {
    private:
        string name;
        int experience;
        string specialization;
    public:
        //Constructor
        TourGuide(string name, int experience, string specialization) {
            this-> name = name;
            this-> experience = experience;
            this-> specialization = specialization;
        }  

        void display() const {
            cout << " Tour Guide: " << name << endl;
            cout << " Experience: " << experience << " years"<< endl; 
            cout << " Specialization: " << specialization << endl;
        }


};

class TravelAgency {
    private:
        string name;
        int guideCount;
        TourGuide **tourGuide;
        int index;

    public:
        TravelAgency(string name, int guideCount) {
            this-> name = name;
            this-> guideCount = guideCount;
            index = 0;
            this-> tourGuide = new TourGuide*[guideCount];
            for (int i = 0; i < guideCount; i++) {
                tourGuide[i] = NULL;
            }
        }

        void assignTourGuide (TourGuide *guide) {
            if (index < guideCount) {
                tourGuide[index] = guide;
                index++;
                cout << "Tour Guide assigned successfully!" << endl;
            } else {
                cout << "No more guides available!" << endl;
            }
        }

        void displayGuide() {
            cout << "Travel Agency: " << name << endl;
            for (int i = 0; i < guideCount; i++) {
                if (tourGuide[i] != NULL) {
                    tourGuide[i]->display();
                    cout << endl;
                }
            }
        }

        ~TravelAgency() {
            for (int i = 0; i < guideCount; i++) {
                delete tourGuide[i];
            }
            delete[] tourGuide;
        }
        

};

int main() {
    TourGuide guide1("Raza", 2 , "Videography");
    TourGuide guide2("Ali", 3, "Photography");
    TourGuide guide3("Hassan", 4, "Videography");
    TourGuide guide4("Ahmed", 5, "Photography");

    TravelAgency agency("ABC Agency", 4);
    agency.assignTourGuide(&guide1);
    agency.assignTourGuide(&guide2);
    agency.assignTourGuide(&guide3);
    agency.assignTourGuide(&guide4);

    agency.displayGuide();
    return 0;
}