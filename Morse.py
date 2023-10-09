# Author: Cyran Kyle
# Date: October 9, 2023
# Description: Morse code to Word and Word to Morse code translator in different languages.
# GitHub: https://github.com/cyran-kyle

# Morse code dictionary
morse_code_dict = {
    'A': '.-', 'B': '-...', 'C': '-.-.', 'D': '-..', 'E': '.', 'F': '..-.', 'G': '--.', 'H': '....',
    'I': '..', 'J': '.---', 'K': '-.-', 'L': '.-..', 'M': '--', 'N': '-.', 'O': '---', 'P': '.--.',
    'Q': '--.-', 'R': '.-.', 'S': '...', 'T': '-', 'U': '..-', 'V': '...-', 'W': '.--', 'X': '-..-',
    'Y': '-.--', 'Z': '--..',
    '1': '.----', '2': '..---', '3': '...--', '4': '....-', '5': '.....', '6': '-....', '7': '--...',
    '8': '---..', '9': '----.', '0': '-----', ' ': ' '  # Space between words
}

# Function to convert a string to Morse code
def string_to_morse_code(input_str):
    morse_result = []
    
    for char in input_str.upper():
        if char in morse_code_dict:
            morse_result.append(morse_code_dict[char])

    return ' '.join(morse_result)

# Function to convert Morse code to a normal sentence
def morse_code_to_string(morse_code):
    morse_code = morse_code.split(' ')
    result = ''
    
    for code in morse_code:
        for char, morse in morse_code_dict.items():
            if morse == code:
                result += char
                break
    
    return result

# Main program
while True:
    print("Choose an option:")
    print("1. Translate Morse code to normal words")
    print("2. Translate a normal sentence to Morse code")
    print("3. Exit")
    
    choice = input("Enter your choice (1/2/3): ")
    
    if choice == '1':
        morse_input = input("Enter Morse code to translate: ")
        normal_output = morse_code_to_string(morse_input)
        print("Translated: " + normal_output)
    elif choice == '2':
        user_input = input("Enter a sentence to convert to Morse code: ")
        morse_output = string_to_morse_code(user_input)
        print("Morse code: " + morse_output)
    elif choice == '3':
        print("Program exited.")
        break
    else:
        print("Invalid choice. Please select 1, 2, or 3.")
