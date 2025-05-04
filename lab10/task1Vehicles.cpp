#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept> 
using namespace std;

int main() {

    try {
        ifstream in("vehicles.txt");
        if(!in.is_open()) {
            throw runtime_error("Error: file opening failed");
        }

        string line;
        while(getline(in , line)) {
            if(line.empty() || line[0] == '#') continue;
            cout << line << endl;
        }

        in.close();
    }
    catch(runtime_error e) {
        cerr << e.what() << endl;
    }
}