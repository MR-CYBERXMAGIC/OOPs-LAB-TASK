#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {

    ofstream writeInFile("config.txt");
    if (!writeInFile) {
        std::cerr << "Error opening file.\n";
        return 1;
    }

    writeInFile << "AAAAABBBBBCCCCC";
    writeInFile.close();

    fstream file("config.txt", ios::in | ios:: out);
    if (!file) {
        std::cerr << "Error opening file.\n";
        return 1;
    }

    file.seekp(5);
    file << "XXXXX";
    file.close();

    ifstream readFromFile("config.txt");
    if (!readFromFile) {
        std::cerr << "Error opening file.\n";
        return 1;
    }
    
    string line;
    getline(readFromFile, line);
    cout << line;
    readFromFile.close();
}