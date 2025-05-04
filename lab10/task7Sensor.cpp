#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ofstream writeInFile("sensor_log.txt");
    if (!writeInFile) {
        cerr << "File popening failed";
        exit(1);
    }

    writeInFile << "Sensor1: 3ka1\n";
    streampos pos1 = writeInFile.tellp();
    cout << "After first write, put pointer is at: " << pos1 << " bytes" <<endl;

    writeInFile << "Sensor2: 4lb2\n";
    streampos pos2 = writeInFile.tellp();
    cout << "After second write, put pointer is at: " << pos2 << " bytes" <<endl;

    writeInFile << "Sensor2: 4lb2\n";
    streampos pos3 = writeInFile.tellp();
    cout << "After third write, put pointer is at: " << pos3 << " bytes" <<endl;
    
    writeInFile.close();
    return 0;
}