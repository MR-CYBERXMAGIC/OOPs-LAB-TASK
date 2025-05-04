#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int main() {

    ofstream writeInFile("large_log.txt");
    if(!writeInFile) {
        cerr << "File onpening failed";
        return 0;
    }

    writeInFile << "This is first line\n";
    writeInFile << "This is second line\n";
    writeInFile << "This is third line\n";
    
    writeInFile.close();

    ifstream readFromFile("large_log.txt", ios::binary);
    if(!readFromFile) {
        cerr << "File onpening failed";
        return 0;
    }

    char ch[11];
    readFromFile.read(ch, 10);
    ch[10] = '\0';
    cout << "First 10 character: " << ch << endl;
    streampos pos1 = readFromFile.tellg();
    cout << "get pointer position: " << pos1 << endl;

    string line;
    getline(readFromFile , line);
    cout << "next line: " << line << endl;
    streampos pos2 = readFromFile.tellg();
    cout << "get pointer position: " << pos2 << endl;


    string line2;
    getline(readFromFile , line2);
    cout << "next line: " << line2 << endl;
    streampos pos3 = readFromFile.tellg();
    cout << "get pointer position: " << pos3 << endl;

    readFromFile.close();
}