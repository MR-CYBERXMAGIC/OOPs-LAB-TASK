#include <iostream>
using namespace std;

class Book {
    private:
    string title;
    float price;
    int stock;

    public:

    // Constuctor 
    Book() {
        title = "Unknown";
        price = 0.0;
        stock = 30;
    }

    // Parameterized Constructor
    Book(string title, float price, int stock) {
        this-> title = title;
        this-> price = price;
        this->stock = (stock < 0) ? 0 : stock;
    }

    // update details function
    void updateDetails() {
        cout << "Enter the title of the book: ";
        getline(cin,title);
        cout << "Enter the price of the book: ";
        cin >> price;
        cout << "Enter the stock of the book: ";
        cin >> stock;
    }

    // Apply discount function
    void applyDiscount(int quantity) {
        if ( quantity > 10) {
            cout << "Discount applied: 10% off for " << quantity << " books." << endl;
            cout << "New price: " << price * 0.9 << "per book" << endl;
        } else if (quantity > 5) {
            cout << "Discount applied: 5% off for " << quantity << " books." << endl;
            cout << "New price: " << price * 0.95 << "per book" << endl;
        } else {
            cout << "No discount applied." << endl;
        }
    }

    // Purchase simulation function
    void purchase(int quantity) {
        if (quantity > stock) {
            cout << "Not enough stock available! Maximum available: " << stock << " units." << endl;
            return;
        }

        applyDiscount(quantity);
        stock -= quantity;
        cout << quantity << " book(s) purchased successfully." << endl;
        
        // Low-stock warning
        if (stock < 5) {
            cout << "Warning: Low stock! Only " << stock << " units left." << endl;
        }
    }

    
    // Display details function
    void display() {
        cout << "Title: " << title  << endl; 
        cout << "Price: $" << price << endl; 
        cout << "Stock: " << stock << " units" << endl << endl;
    }
};


int main() {
    Book myBook;
    myBook.display();

    myBook.updateDetails();
    myBook.display();
    
    myBook.purchase(6);
    myBook.purchase(3);
    myBook.purchase(2); 
    
    return 0;
}