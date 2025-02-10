#include<iostream>
#include<climits>
using namespace std;

int main() {
    int n;

    cout << "Enter the size of array: ";
    cin >> n;

    int* arr = new int[n];

    for(int i = 0; i < n; i++) {
        cout << "Enter element " << i + 1 << " : ";
        cin >> arr[i]; 
    }

    int sum = 0, min = INT_MAX;
    float avg;

    for(int i = 0; i < n; i++) {
        sum += arr[i];
        if(arr[i] < min) {
            min = arr[i];
        }
    }

    avg = float(sum) / float(n);  

    cout << "Sum : " << sum << endl;
    cout << "Average : " << avg << endl;
    cout << "Minimum : " << min << endl;

    delete[] arr;  
    
    return 0;
}
