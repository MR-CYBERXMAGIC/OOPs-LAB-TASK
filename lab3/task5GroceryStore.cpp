#include <iostream>
#include <string>
using namespace std;

class GroceryStore {
private:
    string* items;
    float* prices;
    int capacity;

public:
    GroceryStore() {
        capacity = 0;
        items = new string[capacity];
        prices = new float[capacity];
    }

    void resize() {
        string* newItems = new string[capacity + 1];  
        float* newPrices = new float[capacity + 1];

        for (int i = 0; i < capacity; i++) {
            newItems[i] = items[i];
            newPrices[i] = prices[i];
        }

        delete[] items;
        delete[] prices;

        items = newItems;
        prices = newPrices;
        capacity++;
    }

    void addItem() {
        string item;
        float price;
        cout << "\nEnter item name: ";
        cin >> item;
        cout << "Enter price: ";
        cin >> price;
        resize();
        items[capacity - 1] = item;
        prices[capacity - 1] = price;
        cout << "\nItem added successfully!" << endl;
    }

    void updatePrice() {
        string item;
        float price;
        cout << "\nEnter item name to update price: ";
        cin >> item;
        cout << "Enter new price: ";
        cin >> price;
        for (int i = 0; i < capacity; i++) {
            if (items[i] == item) {
                prices[i] = price;
                cout << "\nPrice updated successfully!" << endl;
                return;
            }
        }
        cout << "\nItem not found!" << endl;
    }

    void viewInventory() {
        cout << "\n Inventory List:\n";
        cout << "---------------------------" << endl;
        for (int i = 0; i < capacity; i++) {
            cout << items[i] << " - $" << prices[i] << endl;
        }
        cout << "---------------------------" << endl;
    }

    void generateReport() {
        int num;
        float total = 0.0;
        cout << "\n Enter number of items to purchase: ";
        cin >> num;
        for (int i = 0; i < num; i++) {
            string item;
            cout << "Enter item name: ";
            cin >> item;
            int j = 0;
            for (; j < capacity; j++) {
                if (items[j] == item) {
                    total += prices[j];
                    cout << "dded: " << item << " - $" << prices[j] << endl;
                    break;
                }
            }
            if (j == capacity) {
                cout << "Item not found! Try again." << endl;
                i--; 
            }
        }
        cout << "\n Total Amount: $" << total << endl;
    }

    ~GroceryStore() {
        delete[] items;
        delete[] prices;
    }
};

int main() {
    GroceryStore store;

    store.addItem();
    store.addItem();
    store.viewInventory();
    store.updatePrice();
    store.generateReport();

    return 0;
}
