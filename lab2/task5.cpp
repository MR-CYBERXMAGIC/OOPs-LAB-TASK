#include <iostream>
#include <string.h>
using namespace std;

int main() {

    string *str1 = new string; 
    string *str2 = new string; 
    string *str = new string; 

    cout << "Enter string 1: ";
    getline(cin, *str1);
    cout << "Enter string 2: ";
    getline(cin, *str2);
    

    // String Concatenation
    *str = *str1 + *str2;
    cout << "String concatenation: " << *str << endl;
    
    // String Comparison
    if (*str1 < *str2) {
        cout << *str1 << " is lexicographically smaller than " << *str2 << endl; 
    } else if (*str1 > *str2) {
        cout << *str1 << " is lexicographically greater than " << *str2 << endl; 
    } else {
        cout << *str1 << " is lexicographically equal to " << *str2 << endl; 
    }

    // String length
    cout << "String 1 length: " << str1->length() << endl;
    cout << "String 2 length: " << str2->length() << endl;
    cout << "Concatenated string length: " << str->length() << endl;

    delete str1;
    delete str2;
    delete str;

    return 0;
}
