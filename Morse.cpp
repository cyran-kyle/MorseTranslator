#include <iostream>
#include <map>
#include <string>
#include <sstream>

using namespace std;
// Author: Cyran Kyle
// Date: October 9, 2023
// Description: Morse code to Word and Word to Morse code translator in different languages.
// GitHub: https://github.com/cyran-kyle
// Morse code dictionary
map<char, string> morseCode = {
    {'A', ".-"}, {'B', "-..."}, {'C', "-.-."}, {'D', "-.."}, {'E', "."}, {'F', "..-."}, {'G', "--."},
    {'H', "...."}, {'I', ".."}, {'J', ".---"}, {'K', "-.-"}, {'L', ".-.."}, {'M', "--"}, {'N', "-."},
    {'O', "---"}, {'P', ".--."}, {'Q', "--.-"}, {'R', ".-."}, {'S', "..."}, {'T', "-"}, {'U', "..-"},
    {'V', "...-"}, {'W', ".--"}, {'X', "-..-"}, {'Y', "-.--"}, {'Z', "--.."},
    {'1', ".----"}, {'2', "..---"}, {'3', "...--"}, {'4', "....-"}, {'5', "....."}, {'6', "-...."},
    {'7', "--..."}, {'8', "---.."}, {'9', "----."}, {'0', "-----"}, {' ', " "}  // Space between words
};

// Function to convert a string to Morse code
string stringToMorseCode(const string& inputStr) {
    stringstream morseResult;

    for (char c : inputStr) {
        if (morseCode.find(toupper(c)) != morseCode.end()) {
            morseResult << morseCode[toupper(c)] << " ";
        }
    }

    return morseResult.str();
}

// Function to convert Morse code to a normal sentence
string morseCodeToString(const string& morseCodeStr) {
    istringstream iss(morseCodeStr);
    string token, result;

    while (getline(iss, token, ' ')) {
        for (const auto& pair : morseCode) {
            if (pair.second == token) {
                result += pair.first;
                break;
            }
        }
    }

    return result;
}

int main() {
    while (true) {
        cout << "Choose an option:" << endl;
        cout << "1. Translate Morse code to normal words" << endl;
        cout << "2. Translate a normal sentence to Morse code" << endl;
        cout << "3. Exit" << endl;

        char choice;
        cin >> choice;

        cin.ignore(); // Consume the newline character

        switch (choice) {
            case '1': {
                cout << "Enter Morse code to translate: ";
                string morseInput;
                getline(cin, morseInput);
                string normalOutput = morseCodeToString(morseInput);
                cout << "Translated: " << normalOutput << endl;
                break;
            }
            case '2': {
                cout << "Enter a sentence to convert to Morse code: ";
                string userInput;
                getline(cin, userInput);
                string morseOutput = stringToMorseCode(userInput);
                cout << "Morse code: " << morseOutput << endl;
                break;
            }
            case '3':
                cout << "Program exited." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please select 1, 2, or 3." << endl;
        }
    }

    return 0;
}
