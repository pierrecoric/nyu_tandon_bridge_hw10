//pc3656
//
//11/21/2024

#include <iostream>
#include <vector>
using namespace std;

void main1();
void main2();
void extendArray(int* &old, int oldSize, int newSize);
void printResults1(int* arr, int size, int target, bool exists);


int main() {
    main1();
    return 0;
}


//Version that does not use vector.
void main1() {
    int n(0), count(0), currentSize(1);
    //Dynamic array to store the user inputs.
    int* inputs;
    inputs = new int [currentSize];
    //Prompt.
    cout << "Please enter a sequence of positive integersm each in a separate line." << endl
         << "End your input by typing -1." << endl;
    while(n != -1) {
        cin >> n;
        //Check if there is room in the array to append n.
        if(count == currentSize) {
            currentSize *= 2;
            extendArray(inputs, count, currentSize);
        }
        //Append n to the array of inputs.
        inputs[count] = n;
        count ++;
    }
    int target(0), indicesCount(0);
    bool exists = false;
    currentSize = 1;
    //Array of indices where the target is found.
    int* indices;
    indices = new int[currentSize];
    cout << "Please enter a positive number you want to search." << endl;
    cin >> target;
    for(int i = 0; i < count; i ++) {
        if(inputs[i] == target) {
            if(!exists) {
                exists = true;
            }
            if(indicesCount == currentSize) {
                currentSize *= 2;
                extendArray(indices, indicesCount, currentSize);
            }
            indices[indicesCount] = i + 1;
            indicesCount ++;
        }
    }
    printResults1(indices, indicesCount, target, exists);
}

void main2() {

};

void extendArray(int* &old, int oldSize, int newSize) {
    int *temp;
    temp = new int[newSize];
    for(int i = 0; i < oldSize; i++) {
        temp[i] = old[i];
    }
    delete [] old;
    old = temp;
}

void printResults1(int* arr, int size, int target, bool exists) {
    if(exists) {
        cout << target << " shows in lines ";
        for(int i = 0; i < size; i ++) {
            if(i < size - 1) {
                cout << arr[i] << ", ";
            }
            else cout << arr[i] << '.' << endl;
        }
    } else cout << target << " not found in the given sequence." << endl;
}