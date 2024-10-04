// Learning C++
// Strings examples, in C and C++

#include <iostream>
#include <cstring>
#include <string>

using namespace std;

template <typename T, typename F>
T* applyFunctionToElements(const T* input, size_t size, F func) {
    T* output = new T[size];
    for (size_t i = 0; i < size; ++i) {
        output[i] = func(input[i]);
    }
    return output;
}

int toUpper(char a){
    return toupper(a);
}
int toLower(char a){
    return tolower(a);
}
// return length
int findLength(char* str) {
    return strlen(str);
}

int findLength(string str) {
    return str.length();
}

// concat string
char* concatString(char* str1, char* str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int totalLen = len1 + len2 + 1;

    char* result = new char[totalLen];

    strcpy(result, str1);
    strcat(result, str2);

    return result;
}

string concatString(string str1, string str2)
{
    return str1+str2;
}

// find pos of a char
int findCharPos(char* str, char ch) {
    int pos = 0;

    while (str[pos] != '\0') {
        if (str[pos] == ch) {
            return pos+1;
        }
        pos++;
    }

    return -1; // Character not found
}

int findCharPos(string str, char ch) {
    int pos = 0;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == ch) {
            return i+1;
        }
    }
    return pos;
}

// to upper case
char *toUpperCase(char *str) {
    return applyFunctionToElements(str,findLength(str),toUpper);
}

string toUpperCase(string str) {
    for (int i = 0; i < str.length(); i++) {
        str[i] = toupper(str[i]);
    }
    return str;
}

// to lower case
char *toLowerCase(char *str) {    
    return applyFunctionToElements(str,findLength(str),toLower);
}

string toLowerCase(string str) {
    for (int i = 0; i < str.length(); i++) {
        str[i] = tolower(str[i]);
    }
    return str;
}

int main() {
    const size_t LENGHT1 = 32;

    // your name
    char cStr[LENGHT1] = "Stefano";

    // your home town
    string stdStr = "Torino";

    cout << cStr << endl;
    cout << stdStr << endl;

    cout << "LENGTH" << endl;
    cout << cStr << " length: " << findLength(cStr) << endl;
    cout << stdStr << " length: " << findLength(stdStr) << endl;

    cout << "CONCAT" << endl;
    cout << cStr << " concat with Hi: " << concatString(cStr, "Hi!!!") << endl;
    cout << stdStr << " concat with Hi: " << concatString(stdStr, "Hi!!!") << endl;
    cout << cStr << endl;

    cout << "POS" << endl;
    cout << cStr << " position of a: " << findCharPos(cStr, 'a') << endl;
    cout << stdStr << " position of o: " << findCharPos(stdStr, 'o') << endl;

    cout << "TO UPPER CASE" << endl;
    cout << cStr << " to upper case: " << toUpperCase(cStr) << endl;
    cout << stdStr << " to upper case: " << toUpperCase(stdStr) << endl;

    cout << endl << endl;

    return(0);
}