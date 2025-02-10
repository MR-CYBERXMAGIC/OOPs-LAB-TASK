#include <iostream>
#include <string>
using namespace std;

struct Book {
    int bookID;
    string title;
    string author;
    bool isAvailable;
};

void addBook(Book*& books, int& count) {
    Book* temp = new Book[count + 1];  

    for (int i = 0; i < count; i++) {
        temp[i] = books[i];
    }

    cout << "\nEnter Book ID: ";
    cin >> temp[count].bookID;
    cin.ignore(); 
    cout << "Enter Title: ";
    getline(cin, temp[count].title);
    cout << "Enter Author: ";
    getline(cin, temp[count].author);
    temp[count].isAvailable = true; 

    count++;
    delete[] books;  
    books = temp;    
}

void removeBook(Book*& books, int& count, int bookID) {
    int index = -1;
    for (int i = 0; i < count; i++) {
        if (books[i].bookID == bookID) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        cout << "Book not found!\n";
        return;
    }

    Book* temp = new Book[count - 1]; 
    for (int i = 0, j = 0; i < count; i++) {
        if (i != index) {
            temp[j++] = books[i]; 
        }
    }

    count--;
    delete[] books;
    books = temp;
    cout << "Book removed successfully!\n";
}

void searchBook(Book* books, int count, int bookID) {
    for (int i = 0; i < count; i++) {
        if (books[i].bookID == bookID) {
            cout << "\nBook Found:\n";
            cout << "ID: " << books[i].bookID << "\nTitle: " << books[i].title;
            cout << "\nAuthor: " << books[i].author;
            cout << "\nAvailable: " << (books[i].isAvailable ? "Yes" : "No") << endl;
            return;
        }
    }
    cout << "Book not found!\n";
}

void displayBooks(Book* books, int count) {
    if (count == 0) {
        cout << "No books available!\n";
        return;
    }

    cout << "\nAvailable Books:\n";
    for (int i = 0; i < count; i++) {
        cout << "ID: " << books[i].bookID << " | Title: " << books[i].title;
        cout << " | Author: " << books[i].author;
        cout << " | Available: " << (books[i].isAvailable ? "Yes" : "No") << endl;
    }
}

int main() {
    Book* books = nullptr;  
    int count = 0;
    int choice, bookID;

    do {
        cout << "\nLibrary Management System\n";
        cout << "1. Add Book\n2. Remove Book\n3. Search Book\n4. Display Books\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addBook(books, count);
                break;
            case 2:
                cout << "Enter Book ID to remove: ";
                cin >> bookID;
                removeBook(books, count, bookID);
                break;
            case 3:
                cout << "Enter Book ID to search: ";
                cin >> bookID;
                searchBook(books, count, bookID);
                break;
            case 4:
                displayBooks(books, count);
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 5);

    delete[] books;
    return 0;
}
