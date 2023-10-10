#include <iostream>
#include <map>
#include <string>

using namespace std;

// Author: Cyran Kyle
// Date: October 9, 2023
// Description: Morse code to Word and Word to Morse code translator in different languages.
// GitHub: https://github.com/cyran-kyle

// Morse code dictionary
map<char, string> morseCode = {
    {'A', ".-"}, {'B', "-..."}, {'C', "-.-."}, {'D', "-.."}, {'E', "."}, {'F', "..-."}, {'G', "--."}, {'H', "...."},
    {'I', ".."}, {'J', ".---"}, {'K', "-.-"}, {'L', ".-.."}, {'M', "--"}, {'N', "-."}, {'O', "---"}, {'P', ".--."},
    {'Q', "--.-"}, {'R', ".-."}, {'S', "..."}, {'T', "-"}, {'U', "..-"}, {'V', "...-"}, {'W', ".--"}, {'X', "-..-"},
    {'Y', "-.--"}, {'Z', "--.."},
    {'1', ".----"}, {'2', "..---"}, {'3', "...--"}, {'4', "....-"}, {'5', "....."}, {'6', "-...."}, {'7', "--..."},
    {'8', "---.."}, {'9', "----."}, {'0', "-----"}, {' ', " "}  // Space between words
};

// Function to convert a string to Morse code
string stringToMorseCode(const string& input) {
    string morseResult = "";

    for (char ch : input) {
        if (morseCode.find(toupper(ch)) != morseCode.end()) {
            morseResult += morseCode[toupper(ch)] + " ";
        } else {
            // Handle characters not in the Morse code dictionary (ignore them)
        }
    }

    return morseResult;
}

// Function to convert Morse code to a normal sentence
string morseCodeToString(const string& morseCode) {
    string result = "";
    istringstream iss(morseCode);
    string code;
    
    while (iss >> code) {
        for (const auto& pair : morseCode) {
            if (pair.second == code) {
                result += pair.first;
                break;
            }
        }
    }

    return result;
}

int main() {
    cout << "Author: Cyran Kyle" << endl;
    cout << "Date: October 9, 2023" << endl;
    cout << "Description: Morse code to Word and Word to Morse code translator in different languages." << endl;
    cout << "GitHub: https://github.com/cyran-kyle" << endl << endl;

    while (true) {
        cout << "Choose an option:" << endl;
        cout << "1. Translate Morse code to normal words" << endl;
        cout << "2. Translate a normal sentence to Morse code" << endl;
        cout << "3. Exit" << endl;

        int choice;
        cin >> choice;
        cin.ignore();  // Consume the newline character

        if (choice == 1) {
            cout << "Enter Morse code to translate: ";
            string morseInput;
            getline(cin, morseInput);
            string normalOutput = morseCodeToString(morseInput);
            cout << "Translated: " << normalOutput << endl;
        } else if (choice == 2) {
            cout << "Enter a sentence to convert to Morse code: ";
            string userInput;
            getline(cin, userInput);
            string morseOutput = stringToMorseCode(userInput);
            cout << "Morse code: " << morseOutput << endl;
        } else if (choice == 3) {
            cout << "Program exited." << endl;
            break;
        } else {
            cout << "Invalid choice. Please select 1, 2, or 3." << endl;
        }
    }

    return 0;
}
