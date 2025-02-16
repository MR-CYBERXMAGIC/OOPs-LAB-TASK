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

    // Copy Constructor for deep copy
    Book(const Book &book) {
        title = book.title;
        price = book.price;
        stock = book.stock;
    }

    // Destructor
    ~Book() {
        cout << "Book object destroyed: " << title << endl;
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

    Book myBook("C++ Programming", 50.0, 10);
    myBook.display();

    // Copying the book object
    Book copiedBook = myBook;
    cout << "Copied book details:" << endl;
    copiedBook.display();

    // Modify original and check if copy remains unchanged
    myBook.updateDetails();
    cout << "Original book after update:" << endl;
    myBook.display();
    cout << "Copied book remains unchanged:" << endl;
    copiedBook.display();

}