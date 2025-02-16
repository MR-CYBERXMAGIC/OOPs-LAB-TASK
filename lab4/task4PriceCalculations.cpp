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
        this->title = title;
        this->price = price;
        this->stock = (stock < 0) ? 0 : stock;
    }

    // Copy Constructor for deep copy
    Book(const Book &b) {
        title = b.title;
        price = b.price;
        stock = b.stock;
    }

    // Destructor
    ~Book() {
        cout << "Book object destroyed: " << title << endl;
    }

    // Function to update book details
    void updateDetails() {
        cout << "Enter the title of the book: ";
        cin >> this->title;
        cout << "Enter the price of the book: ";
        cin >> this->price;
        cout << "Enter the stock of the book: ";
        cin >> this->stock;
    }

    // Price calculation based on discount and bulk purchase
    float calculatePrice(int quantity) const {
        if (quantity > 10) {
            return this->price * 0.90; 
        } else if (quantity > 5) {
            return this->price * 0.95; 
        }
        return this->price;
    }

    // Function to simulate book purchases
    void purchase(int quantity) {
        if (quantity > this->stock) {
            cout << "Not enough stock available! Maximum available: " << stock << " units." << endl;
            return;
        }

        float discountedPrice = calculatePrice(quantity);
        cout << "Discounted price: $" << discountedPrice << " per book" << endl;
        stock -= quantity;
        cout << quantity << " book(s) purchased successfully." << endl;
        
        // Low-stock warning
        if (stock < 5) {
            cout << "Warning: Low stock! Only " << stock << " units left." << endl;
        }
    }

    // Function to display book details
    void display() const {
        cout << "Title: " << title << endl;
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
