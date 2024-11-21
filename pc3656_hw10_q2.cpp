//pc3656
//2024/11/19
//Finding missing elements in an array.

#include <iostream>
using namespace std;

int* findMissing(int arr[], int n, int& resArrSize);
void extendArray(int * &old, int oldSize, int newSize);
void printArray(int* arr, int size);

int main() {
    int size(6), outSize(0);
    int arr [size] = {3, 1, 3, 0, 6, 4};
    int * result = findMissing(arr, size, outSize);
    printArray(result, outSize);
    //Exits the program
    return 0;   
}

int* findMissing(int arr[], int n, int& resArrSize) {
    bool * exists;
    exists = new bool[n + 1];
    resArrSize = 0;
    int * out;
    int currentSize = 1;
    out = new int[currentSize];

    //Initializes the boolean values to false;
    for(int i = 0; i < n + 1; i ++) {
        exists[i] = false;
    }
    //Switches the existing elements to true.
    for(int i = 0; i < n; i++) {
        exists[arr[i]] = true;
    }
    //Appends the indice of the true elements to the result array.
    for(int i = 0; i < n+1; i ++) {
        if(exists[i] == false) {
            //If the physical size is exeeded.
            if(resArrSize == currentSize) {
                currentSize *= 2;
                extendArray(out, resArrSize, currentSize);
            }
            out[resArrSize] = i;
            resArrSize ++;
        }
    }
    return out;
} 

//Function that extends an array given a new size.
void extendArray(int * &old, int oldSize, int newSize) {
    int *temp;
    temp = new int[newSize];
    for (int i = 0; i < oldSize; i++) {
        temp[i] = old[i];
    }
    delete[] old;
    old = temp;
}

//Function that prints out the content of an array of integers.
void printArray(int* arr, int size) {
    cout << "Size of the array: " << size << endl;
    if(size > 0) {
        cout << "content of the array: [";
        for(int i = 0; i < size; i++) {
            if(i < size - 1) {
                cout << *(arr + i) << ", ";
            }
            else cout << *(arr + i) << "]" << endl;
        }
    }
}