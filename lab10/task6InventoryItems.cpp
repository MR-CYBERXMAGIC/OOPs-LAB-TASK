#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

class InventoryItem {
    public:
        int itemID;
        char itemName[20];
};

int main() {

    // writing to file
    InventoryItem item1 = {101 , "Lacimolala"};
    ofstream writeInFile("inventory.dat" , ios :: binary);
    writeInFile.write((char*)&item1, sizeof(item1));
    writeInFile.close();

    //Reading from file
    InventoryItem item2;
    ifstream readFromFile("inventory.dat" , ios :: binary);
    readFromFile.read((char*)&item2, sizeof(item2));
    readFromFile.close();

    cout << "Item ID: " << item2.itemID << endl;
    cout << "Item Name: " << item2.itemName << endl;

    return 0;
}
