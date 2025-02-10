#include <iostream>
#include <string>
using namespace std;

struct Product {
    int productID;
    string name;
    int quantity;
    double price;
};

void addProduct(Product *&inventory, int &size) {
    Product *newInventory = new Product[size + 1];
    for (int i = 0; i < size; i++) {
        newInventory[i] = inventory[i];
    }
    
    cout << "Enter Product ID: ";
    cin >> newInventory[size].productID;
    cout << "Enter Product Name: ";
    cin.ignore();
    getline(cin, newInventory[size].name);
    cout << "Enter Quantity: ";
    cin >> newInventory[size].quantity;
    cout << "Enter Price: ";
    cin >> newInventory[size].price;
    
    delete[] inventory;
    inventory = newInventory;
    size++;
}

void removeProduct(Product *&inventory, int &size, int productID) {
    int index = -1;
    for (int i = 0; i < size; i++) {
        if (inventory[i].productID == productID) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        cout << "Product not found!" << endl;
        return;
    }
    
    Product *newInventory = new Product[size - 1];
    for (int i = 0, j = 0; i < size; i++) {
        if (i != index) {
            newInventory[j++] = inventory[i];
        }
    }
    delete[] inventory;
    inventory = newInventory;
    size--;
    cout << "Product removed successfully!" << endl;
}

void updateProduct(Product *inventory, int size, int productID) {
    for (int i = 0; i < size; i++) {
        if (inventory[i].productID == productID) {
            cout << "Enter new name: ";
            cin.ignore();
            getline(cin, inventory[i].name);
            cout << "Enter new quantity: ";
            cin >> inventory[i].quantity;
            cout << "Enter new price: ";
            cin >> inventory[i].price;
            cout << "Product updated successfully!" << endl;
            return;
        }
    }
    cout << "Product not found!" << endl;
}

void displayInventory(Product *inventory, int size) {
    if (size == 0) {
        cout << "Inventory is empty!" << endl;
        return;
    }
    cout << "\nInventory List:" << endl;
    cout << "------------------------------------------" << endl;
    cout << "ID\tName\t	Quantity\tPrice" << endl;
    cout << "------------------------------------------" << endl;
    for (int i = 0; i < size; i++) {
        cout << inventory[i].productID << "\t" << inventory[i].name << "\t\t"
             << inventory[i].quantity << "\t\t$" << inventory[i].price << "" << endl;
    }
    cout << "------------------------------------------" << endl;
}

double calculateTotalValue(Product *inventory, int size) {
    double totalValue = 0;
    for (int i = 0; i < size; i++) {
        totalValue += inventory[i].price * inventory[i].quantity;
    }
    return totalValue;
}

int main() {
    Product *inventory = nullptr;
    int size = 0;
    int choice, productID;
    
    do {
        cout << "\nInventory Management System" << endl;
        cout << "1. Add Product\n2. Remove Product\n3. Update Product" << endl;
        cout << "4. Display Inventory\n5. Calculate Total Value\n6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addProduct(inventory, size);
                break;
            case 2:
                cout << "Enter Product ID to remove: ";
                cin >> productID;
                removeProduct(inventory, size, productID);
                break;
            case 3:
                cout << "Enter Product ID to update: ";
                cin >> productID;
                updateProduct(inventory, size, productID);
                break;
            case 4:
                displayInventory(inventory, size);
                break;
            case 5:
                cout << "Total Inventory Value: $" << calculateTotalValue(inventory, size) << endl;
                break;
            case 6:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 6);
    
    delete[] inventory;
    return 0;
}
