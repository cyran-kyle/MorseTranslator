// Author: Cyran Kyle
// Date: October 9, 2023
// Description: Morse code to Word and Word to Morse code translator in different languages.
// GitHub: https://github.com/cyran-kyle
// Morse code dictionary

import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class MorseCodeTranslator {

    // Morse code dictionary
    private static final Map<Character, String> morseCode = new HashMap<>();

    static {
        morseCode.put('A', ".-");
        morseCode.put('B', "-...");
        morseCode.put('C', "-.-.");
        morseCode.put('D', "-..");
        morseCode.put('E', ".");
        morseCode.put('F', "..-.");
        morseCode.put('G', "--.");
        morseCode.put('H', "....");
        morseCode.put('I', "..");
        morseCode.put('J', ".---");
        morseCode.put('K', "-.-");
        morseCode.put('L', ".-..");
        morseCode.put('M', "--");
        morseCode.put('N', "-.");
        morseCode.put('O', "---");
        morseCode.put('P', ".--.");
        morseCode.put('Q', "--.-");
        morseCode.put('R', ".-.");
        morseCode.put('S', "...");
        morseCode.put('T', "-");
        morseCode.put('U', "..-");
        morseCode.put('V', "...-");
        morseCode.put('W', ".--");
        morseCode.put('X', "-..-");
        morseCode.put('Y', "-.--");
        morseCode.put('Z', "--..");
        morseCode.put('1', ".----");
        morseCode.put('2', "..---");
        morseCode.put('3', "...--");
        morseCode.put('4', "....-");
        morseCode.put('5', ".....");
        morseCode.put('6', "-....");
        morseCode.put('7', "--...");
        morseCode.put('8', "---..");
        morseCode.put('9', "----.");
        morseCode.put('0', "-----");
        morseCode.put(' ', " ");  // Space between words
    }

    // Function to convert a string to Morse code
    private static String stringToMorseCode(String inputStr) {
        StringBuilder morseResult = new StringBuilder();

        for (char character : inputStr.toUpperCase().toCharArray()) {
            if (morseCode.containsKey(character)) {
                morseResult.append(morseCode.get(character)).append(" ");
            }
        }

        return morseResult.toString();
    }

    // Function to convert Morse code to a normal sentence
    private static String morseCodeToString(String morseCodeStr) {
        StringBuilder result = new StringBuilder();
        String[] morseArray = morseCodeStr.split(" ");

        for (String code : morseArray) {
            for (Map.Entry<Character, String> entry : morseCode.entrySet()) {
                if (entry.getValue().equals(code)) {
                    result.append(entry.getKey());
                    break;
                }
            }
        }

        return result.toString();
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        while (true) {
            System.out.println("Choose an option:");
            System.out.println("1. Translate Morse code to normal words");
            System.out.println("2. Translate a normal sentence to Morse code");
            System.out.println("3. Exit");

            String choice = scanner.nextLine();

            switch (choice) {
                case "1":
                    System.out.print("Enter Morse code to translate: ");
                    String morseInput = scanner.nextLine();
                    String normalOutput = morseCodeToString(morseInput);
                    System.out.println("Translated: " + normalOutput);
                    break;
                case "2":
                    System.out.print("Enter a sentence to convert to Morse code: ");
                    String userInput = scanner.nextLine();
                    String morseOutput = stringToMorseCode(userInput);
                    System.out.println("Morse code: " + morseOutput);
                    break;
                case "3":
                    System.out.println("Program exited.");
                    scanner.close();
                    return;
                default:
                    System.out.println("Invalid choice. Please select 1, 2, or 3.");
            }
        }
    }
}
