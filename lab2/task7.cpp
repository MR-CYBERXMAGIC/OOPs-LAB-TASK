#include <iostream>
using namespace std;

// Function to swap two integers using pointers
void swap(int *a, int *b) {
    int temp = *b;
    *b = *a;
    *a = temp;
}

// Function to reverse an array using pointers
void reverseArray(int *array, int size) {
    int i = 0, j = size - 1;

    while (i < j) {
        swap(&array[i++], &array[j--]);
    }
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int *array = new int[n];

    for (int i = 0; i < n; i++) {
        cout << "Enter number " << i + 1 << " : ";
        cin >> array[i];
    }

    cout << "\nEntered array:  [ ";
    for (int i = 0; i < n; i++) {
        cout << array[i] << " ";
    }
    cout << "]\n";

    // Reverse array
    reverseArray(array, n);

    cout << "Reversed array: [ ";
    for (int i = 0; i < n; i++) {
        cout << array[i] << " ";
    }
    cout << "]\n";

    delete[] array;

    return 0;
}
