#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {

    ofstream writeInFile("data_records.txt");
    if(!writeInFile) {
        cerr << "File opening failed";
        return 0;
    }

    writeInFile << "Record 1\nRecord 2\nRecord 3\nRecord 4\nRecord 5\n";
    writeInFile.close();

    ifstream readFromFile("data_records.txt",ios ::binary);
    if(!readFromFile) {
        cerr << "File opening failed";
        return 0;
    }

    readFromFile.seekg(20, ios::beg);
    string thirdRecord;
    getline(readFromFile, thirdRecord);

    cout << "Third Record: " << thirdRecord << endl;
    readFromFile.close();
}