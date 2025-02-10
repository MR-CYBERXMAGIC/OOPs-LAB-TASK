#include <iostream>
using namespace std;

int main() {
    int rows, cols;

    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    int** matrix = new int*[rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
    }

    // Input Matrix Elements
    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Element [" << i + 1 << "][" << j + 1 << "]: ";
            cin>>matrix[i][j];
        }
    }

    int** transpose = new int*[cols];
    for (int i = 0; i < cols; i++) {
        transpose[i] = new int[rows];
    }

    //calculating transpose
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            *(*(transpose + j) + i) = *(*(matrix + i) + j);
        }
    }

    // Display Original Matrix
    cout << "\nOriginal Matrix:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << *(*(matrix + i) + j) << " ";
        }
        cout << endl;
    }

    // Display Transposed Matrix
    cout << "\nTransposed Matrix:" << endl;
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            cout << *(*(transpose + i) + j) << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    for (int i = 0; i < cols; i++) {
        delete[] transpose[i];
    }
    delete[] transpose;

    return 0;
}
