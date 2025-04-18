#include<iostream>
#include "Book.h"
#define nl (cout << endl)
using namespace std;

int main()
{
    Book B("Unknown", "Anonymous", "XXX-XXXXXX");
    nl;
    cout << "Book Title: " << B.getTitle() << endl;
    cout << "Author: " << B.getAuthor() << endl;
    cout << "ISBN: " << B.getISBN() << endl;
    nl;

    return 0;
}