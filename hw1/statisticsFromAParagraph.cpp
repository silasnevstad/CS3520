/* CS3520 - Silas Nevstad
   1/22/2023
   This program takes a paragraph from the user as input, as well as a word length. It then
   calculates several statistics about the paragraph, including the number of total words,
   vowels, consonants, words starting with vowels, and the number of words that use certain
   punctuation marks (! . , ; " ' ? $). It also calculates the number of words that have a length
   greater than the user provided length, and the number of words shorter than a random value
   between (6-10). It then displays these statistics for the user to see.
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    string paragraph;
    int total_words = 0, vowels = 0, consonants = 0, exclamation = 0, period = 0, comma = 0, semicolon = 0, quotation = 0, apostrophe = 0, question = 0, dollar = 0, vowel_start = 0,
    word_length, long_words = 0, short_words = 0;
    char current_char;
    int current_word_length = 0;
    bool word_start = true;
    int rand_word_length;

    // get paragraph from user
    cout << "Enter a paragraph: " << endl;
    getline(cin, paragraph);
    srand(time(0));
    rand_word_length = rand() % (10 - 6 + 1) + 6; // random word length between 6 and 10

    // get word length from user
    cout << "Enter a word length: ";
    cin >> word_length;

    // display the paragraph
    cout << "The paragraph: " << endl << paragraph << endl;

    cout << "Random word length: " << rand_word_length << endl;

    // calculate statistics
    for (unsigned int i = 0; i < paragraph.length(); i++) {
        current_char = paragraph[i];

        // check if current character is a letter
        if (isalpha(current_char)) {
            current_word_length++;
            
            // check if current character is a vowel
            if (current_char == 'a' || current_char == 'e' || current_char == 'i' || current_char == 'o' || current_char == 'u' || current_char == 'A' || current_char == 'E' || current_char == 'I' || current_char == 'O' || current_char == 'U') {
                vowels++;
                if (word_start) { // check if this is the first letter of the word
                    vowel_start++;
                    word_start = false;
                }
            }
            else { // if current character is not a vowel, it must be a consonant
                consonants++;
                word_start = false;
            }
        }
        // check if current character is a punctuation mark
        else if (current_char == '!') {
            exclamation++;
        }
        else if (current_char == '.') {
            period++;
        }
        else if (current_char == ',') {
            comma++;
        }
        else if (current_char == ';') {
            semicolon++;
        } else if (current_char == '"') {
            quotation++;
        }
        else if (current_char == '\'') {
            apostrophe++;
        }
        else if (current_char == '?') {
            question++;
        }
        else if (current_char == '$') {
            dollar++;
        }
            // check if current character is a space (indicating the end of a word)
        if (current_char == ' ' || current_char == '\0') {
            total_words++;
            if (current_word_length > word_length) long_words++;
            if (current_word_length < rand_word_length) short_words++;
            current_word_length = 0;
            word_start = true;
        }
    }

    // add one to total_words to account for the last word in the paragraph
    total_words++;

    // display statistics
    cout << "Statistics: " << endl;
    cout << "Total words: " << total_words << endl;
    cout << "Vowels: " << vowels << endl;
    cout << "Consonants: " << consonants << endl;
    cout << "Words starting with vowels : " << vowel_start << endl;
    cout << "Words with exclamation marks: " << exclamation << endl;
    cout << "Words with periods: " << period << endl;
    cout << "Words with commas: " << comma << endl;
    cout << "Words with semicolons: " << semicolon << endl;
    cout << "Words with quotation marks: " << quotation << endl;
    cout << "Words with apostrophes: " << apostrophe << endl;
    cout << "Words with question marks: " << question << endl;
    cout << "Words with dollar signs: " << dollar << endl;
    cout << "Number of words with length greater than " << word_length << ": " << long_words << endl;
    cout << "Number of words with length less than " << rand_word_length << ": " << short_words << endl;

    return 0;
}
