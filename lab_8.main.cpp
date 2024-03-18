#include <iostream>
#include <fstream>
using namespace std;
const int N = 20;
const int M = 20;

void array110();
void duplicateMultiples(int arr[], int& size);

void matrix21();
double calculateAverage(int matrix[M][N], int rowCount, int colCount);

void sort2();
void binaryInsertionSort(double arr[], int n);
void readArrayFromFile(double arr[], int& n, const string& filename);
void printArray(double arr[], int n);

int main () { // menu
    int task_num;  // diclaration
    do {
        cout << " Task number (0 - exit):  ";
        cin >> task_num;
        if (!cin) {
            cout << " Ups!" << endl; continue;
            // error notification
        }
        switch (task_num) {
            case 1 : array110(); break; // task 1
            case 2 : matrix21(); break; // task 2
            case 3 : sort2(); break; // task 3
            case 0 : cout << " The program is over!" << endl; break;
            default : cout << " Wrong task number!" << endl;
            // output for incorrect numbers
        }
    } while (task_num != 0); // end the program
    return 0;
}
// task 1
void array110(){
    cout << " *** Task 1 Array 110 *** " << endl;
    const int max_size = 20; // maximum array size
    int arr[max_size];
    int size = 0;
    // entering data from a file
    ifstream filein("array_in110.txt");
    if (!filein.is_open()) {
        cout << "Unable to open the input file." << endl;
        return;
    }
    // read array size
    filein >> size;
    // reading array elements
    for (int i = 0; i < size; ++i) {
        filein >> arr[i];
    }
    filein.close();
    // duplication of multiples of two elements
    duplicateMultiples(arr, size);
    // outputting results to a file
    ofstream fileout("array_out110.txt");
    if (!fileout.is_open()) {
        cout << "Unable to open the output file." << endl;
        return;
    }
    // writing a modified array
    for (int i = 0; i < size; ++i) {
        fileout << arr[i] << " ";
    }
    fileout.close();
    cout << " Result in the file array_out110.txt " << endl;
    return;
}
// function for duplicating multiples of two elements
void duplicateMultiples(int arr[], int& size) {
    int newSize = size; // New array size
    for (int i = 0; i < size; ++i) {
        if (arr[i] % 2 == 0) {
            // increase the array size and insert a duplicate of it
            for (int j = newSize - 1; j > i; j--) {
                arr[j + 1] = arr[j];
            }
            arr[i + 1] = arr[i]; // inserting a duplicate
            ++newSize; // increase the array size
            ++i; // skip the element just inserted
        }
    }
    size = newSize; // updating the array size
}
// task 2
void matrix21() {
    cout << " *** Task 2 Matrix 21 *** " << endl;
    // opening a file for reading
    ifstream file;
    file.open("matr_21.txt");
    // checking whether the file was successfully opened
    if (!file.is_open()) {
        cout << "File could not be opened for reading." << endl;
        return;
    }
    // reading data from a file
    int rowCount, colCount;
    file >> rowCount >> colCount;
    // creating and reading a two-dimensional array
    int matrix[M][N];
    cout << "Matrix read from file:" << endl;
    for (int i = 0; i < rowCount; ++i) {
        for (int j = 0; j < colCount; ++j) {
            file >> matrix[i][j];
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    file.close();
    // function call to calculate the arithmetic mean of odd columns
    calculateAverage(matrix, rowCount, colCount);
    return;
}

// function for finding the arithmetic mean of column elements of a matrix
double calculateAverage(int matrix[M][N], int rowCount, int colCount) {
    double sum = 0.0;
    int count = 0;
    for (int j = 0; j < colCount; j += 2) {
        sum = 0;
        count = 0;
        for (int i = 0; i < rowCount; i++) {
            sum += matrix[i][j];
            count++;
        }
        double avg = sum / count;
        cout << "Average of column " << j+1 << ": " << avg << endl;
    }
    return 0.0; 
}
// task 3
void sort2() {
    cout << " *** Task 3 Sort 2 *** " << endl;
    const int SIZE = 10;
    double arr[SIZE];
    int n;
    // reading an array from a file
    readArrayFromFile(arr, n, "sort.txt");
    // outputting the array
    cout << "Original array:" << endl;
    printArray(arr, n);
    // sort by binary insertion method
    binaryInsertionSort(arr, n);
    // outputting a sorted array
    cout << "Sorted array:" << endl;
    printArray(arr, n);
    return;
}
// binary search for a place to insert
void binaryInsertionSort(double arr[], int n) {
    for (int i = 1; i < n; ++i) {
        double key = arr[i];
        int left = 0;
        int right = i - 1;
        // binary search for a place to insert
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] > key)
                left = mid + 1;
            else
                right = mid - 1;
        }
        // move items to make room for insertion
        for (int j = i - 1; j >= left; --j) {
            arr[j + 1] = arr[j];
        }
        // insert an item into the found location
        arr[left] = key;
    }
}
// opening a file for reading
void readArrayFromFile(double arr[], int& n, const string& filename) {
    ifstream file(filename);
    if (file.is_open()) {
        file >> n;
        for (int i = 0; i < n; ++i) {
            file >> arr[i];
        }
        file.close();
    } else {
        cout << "Unable to open file: " << filename << endl;
    }
}
// function for displaying an array on the screen
void printArray(double arr[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
