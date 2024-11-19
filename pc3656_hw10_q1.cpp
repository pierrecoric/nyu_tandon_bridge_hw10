//pc3656
//Programs that slice a sentence into words.

#include <iostream>
#include <string>
using namespace std;

string* createWordsArray(string sentence, int& outWordsArrSize);
bool isAlpha(char c);

int main() {
    cout << isAlpha('1') << endl << isAlpha('Z') << endl;
    //Exit the program.
    return 0;
}


//Must returns a pointer to an array of string.
//Updates the array size to be equal to the amount of strings.
string* createWordsArray(string sentence, int& outWordsArrSize){
    
}

bool isAlpha(char c) {
    if(int(c) >= int('A') && int(c) <= int('Z')) {
        return true;
    }
    else if(int(c) >= int('Z') && int(c) <= int('z')) {
        return true;
    }
    else return false;
}

