#include<iostream>
using namespace std;

int main() {
    int row1, col1,row2,col2;
    
    // Dimensions Input
    cout<<"Enter number of rows for matrix1 ";
    cin>>row1;
    
    cout<<"Enter number of cols for matrix1 ";
    cin>>col1;
    
    cout<<"Enter number of rows for matrix2 ";
    cin>>row2;
    
    cout<<"Enter number of cols for matrix2 ";
    cin>>col2;

    //Memory allocation
    int **matrix1 = new int*[row1];
    for(int i = 0; i < row1; i++) {
        matrix1[i] = new int[col1];
    }

    int **matrix2 = new int*[row2];
    for(int i = 0; i < row2; i++) {
        matrix2[i] = new int[col2];
    }

    //Input values
    cout<<"Enter value of matrix 1"<<endl;
    for(int i = 0; i < row1; i++) {
        for(int j = 0;j < col1; j++) {
            cout<<"["<< i + 1 << "]["<< j + 1 << "]=";
            cin>>matrix1[i][j];
        }
    }
    cout<<endl;

    cout<<"Enter value of matrix 2"<<endl;
    for(int i = 0; i < row2; i++) {
        for(int j = 0;j < col2; j++) {
            cout<<"["<< i + 1 << "]["<< j + 1 << "]=";
            cin>>matrix2[i][j];
        }
    }
    cout<<endl;

    //Matix Addition
    if(row1 == row2 && col1 == col2) {
        cout<<"Addition of two matrix"<<endl;
        for(int i = 0; i < row1; i++) {
            for(int j = 0;j < col1; j++) {
                cout<<matrix1[i][j] + matrix2[i][j] << " ";
            }
            cout<<endl;
        }
    } else {
        cout<<"Matrix Addition is not possible"<<endl;
    }
    cout<<endl;
    
    //Matix Subtraction
    if(row1 == row2 && col1 == col2) {
        cout<<"Subtraction of two matrix"<<endl;
        for(int i = 0; i < row1; i++) {
            for(int j = 0;j < col1; j++) {
                cout<<matrix1[i][j] - matrix2[i][j] << " ";
            }
            cout<<endl;
        }
    } else {
        cout<<"Matrix Subtraction is not possible"<<endl;
    }
    cout<<endl;
    
    //Matix Multiplication
    if(col1 == row2 ) {
        cout<<"Multiplication of two matrix"<<endl;

        int** result = new int*[row1];
        for (int i = 0; i < row1; i++) {
            result[i] = new int[col2]();  
        }

        for(int i = 0; i < row1; i++) {
            for(int j = 0;j < col2; j++) {
                for(int k = 0; k < col1; k++) {
                    result[i][j] += matrix1[i][k] * matrix2[k][j];
                }
            }
        }
        for(int i = 0; i < row1; i++) {
            for(int j = 0;j < col2; j++) {
                cout<<result[i][j]<<" ";
            }
            cout<<endl;
        }
         
        for (int i = 0; i < row1; i++) {
            delete[] result[i];
        }
        delete[] result;

    } else {
        cout<<"Matrix Multiplication is not possible"<<endl;
    }
    cout<<endl;

    //Free memory
    for (int i = 0; i < row1; i++) {
            delete[] matrix1[i];
    }
    delete[] matrix1;

    for (int i = 0; i < row2; i++) {
            delete[] matrix2[i];
    }
    delete[] matrix2;

    return 0;

}