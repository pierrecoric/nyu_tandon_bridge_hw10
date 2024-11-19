//pc3656
//Programs that slice a sentence into words.
//2024/11/18

#include <iostream>
#include <string>
using namespace std;

string* createWordsArray(string sentence, int& outWordsArrSize);
string * extendArray(string * &old, int oldSize, int newSize);
void printWordArray(string* str, int size);
bool isAlpha(char c);

int main() {
    string input;
    string * out;
    int sizeWordArray(0);

    //Prompts the user for inputs.
    cout << "Please enter a sentence." << endl;
    getline(cin, input);

    //Populates the array of words.
    out = createWordsArray(input, sizeWordArray);
    cout << endl;

    //Prints the array of words. 
    printWordArray(out, sizeWordArray);
    
    //Frees the memory and set out to null.
    delete [] out;
    out = NULL;
    //Exits the program.
    return 0;
}

//Function that slices a string into words and store them into an array.
string* createWordsArray(string sentence, int& outWordsArrSize){
    //Initialize the size of the array to 1.
    int currentSize(1);
    //Declare and initialize the array.
    string* wordArray;
    wordArray = new string[currentSize];

    //Variables to keep track of the words.
    bool newWord = false;
    string word = "";
    
    //Iterates over the sentence.
    for(int c = 0; c < sentence.length(); c++) {
        //If an alphabetical character is encountered.
        if(isAlpha(sentence[c])) {
            if(!newWord) {
                newWord = true;
            }
            word += sentence[c];
        }
        //If a word is finished
        else if(sentence[c] == ' ') {
            //If the array needs to be extended, double the size of the array.
            if(outWordsArrSize == currentSize) {
                currentSize *= 2;
                wordArray = extendArray(wordArray, outWordsArrSize, currentSize);
            }
            //Append the word to the array and increment the size
            wordArray[outWordsArrSize] = word;
            outWordsArrSize ++;
            word = "";
            newWord = false;            
        }
    }
    //Logic to add the last word if there is one
    if(newWord) {
         if(outWordsArrSize == currentSize) {
                //Only increment by one to store the last word if needed.
                currentSize ++;
                wordArray = extendArray(wordArray, outWordsArrSize, currentSize);
            }
            wordArray[outWordsArrSize] = word;
            outWordsArrSize ++;
    }
    return wordArray;
}

//Function that returns true if the input is alphabetical.
bool isAlpha(char c) {
    if(int(c) >= int('A') && int(c) <= int('Z')) {
        return true;
    }
    else if(int(c) >= int('a') && int(c) <= int('z')) {
        return true;
    }
    else return false;
}

//Function that prints out the content of an array of strings.
void printWordArray(string* str, int size) {
    string wordSpelling(" word");
    if(size > 1) {
        wordSpelling += 's';
    }
    cout << "The array contains " << size << wordSpelling << ":" << endl;
    for(int i = 0; i < size; i++) {
        cout << i + 1 << ":\t" << *(str + i) << endl;
    }
}

//Function that extends an array given a new size.
string * extendArray(string * &old, int oldSize, int newSize) {
    string *tempStr;
    tempStr = new string[newSize];
    for (int i = 0; i < oldSize; i++) {
        tempStr[i] = old[i];
    }
    delete[] old;
    old = tempStr;
    return old;
}