// Morse code dictionary
const morseCode = {
    'A': '.-', 'B': '-...', 'C': '-.-.', 'D': '-..', 'E': '.', 'F': '..-.', 'G': '--.', 'H': '....',
    'I': '..', 'J': '.---', 'K': '-.-', 'L': '.-..', 'M': '--', 'N': '-.', 'O': '---', 'P': '.--.',
    'Q': '--.-', 'R': '.-.', 'S': '...', 'T': '-', 'U': '..-', 'V': '...-', 'W': '.--', 'X': '-..-',
    'Y': '-.--', 'Z': '--..',
    '1': '.----', '2': '..---', '3': '...--', '4': '....-', '5': '.....', '6': '-....', '7': '--...',
    '8': '---..', '9': '----.', '0': '-----', ' ': ' '  // Space between words
};

// Function to convert a string to Morse code
function stringToMorseCode(inputStr) {
    const morseResult = [];

    for (const char of inputStr.toUpperCase()) {
        if (morseCode.hasOwnProperty(char)) {
            morseResult.push(morseCode[char]);
        }
    }

    return morseResult.join(' ');
}

// Function to convert Morse code to a normal sentence
function morseCodeToString(morseCodeStr) {
    const morseArray = morseCodeStr.split(' ');
    let result = '';

    for (const code of morseArray) {
        for (const [char, morse] of Object.entries(morseCode)) {
            if (morse === code) {
                result += char;
                break;
            }
        }
    }

    return result;
}

// Main program
while (true) {
    const choice = prompt("Choose an option:\n1. Translate Morse code to normal words\n2. Translate a normal sentence to Morse code\n3. Exit\n");

    switch (choice) {
        case '1':
            const morseInput = prompt("Enter Morse code to translate:");
            const normalOutput = morseCodeToString(morseInput);
            alert("Translated: " + normalOutput);
            break;
        case '2':
            const userInput = prompt("Enter a sentence to convert to Morse code:");
            const morseOutput = stringToMorseCode(userInput);
            alert("Morse code: " + morseOutput);
            break;
        case '3':
            alert("Program exited.");
            return;
        default:
            alert("Invalid choice. Please select 1, 2, or 3.");
    }
}
