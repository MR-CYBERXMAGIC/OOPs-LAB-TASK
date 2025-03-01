#include<iostream>
#include <string>
using namespace std;

class Product {
    private:
        static int unique;
        int productId;
        string productName;
        float price;
    public:
        //Constructor
        Product(string productName, float price) {
            productId = unique++;
            this->productName = productName;
            this->price = price;
        }

        void display() const {
            cout << "id: " << productId << endl;
            cout << "name: " << productName << endl;
            cout << "price: " << price << endl;
        }
        string getProductName() const {
            return productName;
        }

        float getPrice() const {
            return price;
        }
};

int Product::unique = 0;

class Inventory{
    private:
        Product** products;
        int capacity;
        int count;
    public:
        //Constructor
        Inventory(int capacity) {
            this->capacity = capacity;
            products = new Product*[capacity];
            for(int i = 0; i < capacity; i++) {
                products[i] = nullptr;
            }
            count = 0;
        }

        void addProduct(string name, float price) {
            if (count < capacity) {
                products[count] = new Product(name, price);
                count++;
                cout << "Product added successfully!"<<endl;
            } else {
                cout << "Inventory is full!"<<endl;
            }
        }

        void sortByPrice() {
            for (int i = 0; i < count - 1; i++) {
                for (int j = 0; j < count - i - 1; j++) {
                    if (products[j]->getPrice() > products[j + 1]->getPrice()) {
                        swap(products[j], products[j + 1]);
                    }
                }
            }
            cout << "Products sorted by price!"<< endl;
        }

        void searchByName(string name) {
            bool found = false;
            for (int i = 0; i < count; i++) {
                if (products[i]->getProductName() == name ) {
                    products[i]->display();
                    found = true;
                }
            }
            if (!found) {
                cout << "Product not found!"<<endl;
            }
        }

        void displayAll() {
            if (count == 0) {
                cout << "No products in inventory."<<endl;
                return;
            }
            cout << "Product List:"<<endl;
            for (int i = 0; i < count; i++) {
                products[i]->display();
            }
        }

        ~Inventory() {
            for (int i = 0; i < count; i++) {
                delete products[i];
            }
            delete[] products;
        }

};


int main() {
    
    Inventory inventory(5);

    inventory.addProduct("Laptop", 999.99);
    inventory.addProduct("Smartphone", 499.99);
    inventory.addProduct("Headphones", 79.99);
    inventory.addProduct("Monitor", 199.99);
    inventory.addProduct("Keyboard", 49.99);

    cout << "\nBefore Sorting:\n";
    inventory.displayAll();

    inventory.sortByPrice();

    cout << "\nAfter Sorting:\n";
    inventory.displayAll();

    inventory.searchByName("Laptop");

    return 0;
}