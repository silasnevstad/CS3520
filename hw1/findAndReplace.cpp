#include <iostream>
#include <string>
using namespace std;

int main() {
    string paragraph, search_word, replace_word;
    int search_word_count = 0, current_word_start = 0;
    unsigned int i;

    // get paragraph from user
    cout << "Enter a paragraph: " << endl;
    getline(cin, paragraph);

    // get word to search for from user
    cout << "Enter a word to search for: ";
    cin >> search_word;

    // search for word in paragraph
    for (i = 0; i < paragraph.length(); i++) {
        if (paragraph[i] == ' ' || paragraph[i] == '\0') {
            if (paragraph.substr(current_word_start, i - current_word_start) == search_word) {
                search_word_count++;
                cout << "Word found at index " << current_word_start << endl;
            }
            current_word_start = i + 1;
        }
    }

    // check last word in paragraph
    if (paragraph.substr(current_word_start, i - current_word_start) == search_word) {
        search_word_count++;
        cout << "Word found at index " << current_word_start << endl;
    }

    // print number of times word was found in paragraph
    cout << "The word \"" << search_word << "\" was found " << search_word_count << " time(s) in the paragraph." << endl;
    cout << "Enter a new word to replace: ";
    cin >> replace_word;
    int pos = 0;
    while ((pos = paragraph.find(search_word, pos)) != string::npos) {
        paragraph.replace(pos, search_word.length(), replace_word);
        pos += replace_word.length();
    }
    cout << "The new paragraph is: " << endl << paragraph;
    return 0;
}