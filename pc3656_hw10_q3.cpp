//pc3656
//Finding a number in an array.
//11/21/2024

#include <iostream>
#include <vector>
using namespace std;

void main1();
void main2();
void extendArray(int* &old, int oldSize, int newSize);
void printResults1(int* arr, int size, int target, bool exists);
void printResults2(vector<int> arr, int target, bool exists);

int main() {
    cout << "Main 1" << endl << endl;
    main1();
    cout << endl 
         << "------------------------------" << endl 
         << "Main 2" 
         << endl << endl;
    main2();
    return 0;
}

//Solution that does not use vector.
void main1() {
    int n(0), count(0), currentSize(1);
    int* inputs;
    inputs = new int [currentSize];

    //Prompt.
    cout << "Please enter a sequence of positive integersm each in a separate line." << endl
         << "End your input by typing -1." << endl;

    //Listen for inputs while -1 has not been entered.
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

    //Reset currentSize.
    currentSize = 1;
    //Array to store the indices where the target is found.
    int* indices;
    indices = new int[currentSize];

    int target(0), indicesCount(0);
    bool exists = false;

    //Prompt.
    cout << "Please enter a positive number you want to search." << endl;
    cin >> target;

    //Iterate over the array of inputs.
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

    //Output the results.
    printResults1(indices, indicesCount, target, exists);

    //Free the memory.
    delete [] indices;
    delete [] inputs;
    inputs = NULL;
    indices = NULL;
}

//Solution that uses vector.
void main2() {
    vector<int> inputs;
    int n;

    //Prompt.
    cout << "Please enter a sequence of positive integersm each in a separate line." << endl
         << "End your input by typing -1." << endl;

    //Listen for inputs.
    while(n != -1) {
        cin >> n;
        //Append to the array
        inputs.push_back(n);
    }

    vector<int> indices;
    int target;
    bool exists = false;

    //Prompt.
    cout << "Please enter a positive number you want to search." << endl;
    cin >> target;

    //Iterate over the inputs and append the indices.
    for(int i = 0; i < inputs.size(); i++) {
        if(inputs[i] == target) {
            if(!exists) {
                exists = true;
            }
            indices.push_back(i + 1);
        }
    }

    //Output the results.
    printResults2(indices, target, exists);
};

//Function to extend a dynamic array.
void extendArray(int* &old, int oldSize, int newSize) {
    int *temp;
    temp = new int[newSize];
    for(int i = 0; i < oldSize; i++) {
        temp[i] = old[i];
    }
    delete [] old;
    old = temp;
}

//Prints the results from a dynamic array.
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

//Prints the results from a vector.
void printResults2(vector<int>arr, int target, bool exists) {
    if(exists) {
        cout << target << " shows in lines ";
        for(int i = 0; i < arr.size(); i ++) {
            if(i < arr.size() - 1) {
                cout << arr[i] << ", ";
            }
            else cout << arr[i] << '.' << endl;
        }
    } else cout << target << " not found in the given sequence." << endl;
}