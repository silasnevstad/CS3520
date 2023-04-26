#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

struct WordInfo {
    string word;
    int count;
    int length;
};

bool compareByLength(const WordInfo& a, const WordInfo& b) {
    return a.length > b.length;
}

bool compareByCount(const WordInfo& a, const WordInfo& b) {
    return a.count > b.count;
}

void processFile(string filename, map<string, int>& wordFreq) {
    ifstream infile(filename);
    string word;
    while (infile >> word) { // for each word in the file
        // Convert word to lowercase
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        // Remove punctuation
        word.erase(remove_if(word.begin(), word.end(), ::ispunct), word.end());
        // Increment frequency count of the word
        wordFreq[word]++;
    }
}

int vowelCounter(map<string, int>& wordFreq) {
    int count = 0;
    for (auto const& it : wordFreq) { // for each word in the map
        string word = it.first;
        int freq = it.second;
        if (word.length() > 0 && (word[0] == 'a' || word[0] == 'e' || word[0] == 'i' || word[0] == 'o' || word[0] == 'u')) { // if word starts with a vowel
            count += freq;
        }
    }
    return count;
}

void writeStatistics(string filename, map<string, int>& wordFreq, char sortType, char wordType, int maxLength) {
    ofstream outfile(filename);
    int totalWords = 0;
    for (auto const& it : wordFreq) { // add up all the frequencies
        totalWords += it.second;
    }
    outfile << "There are " << totalWords << " words in total." << endl;

    int vowelWords = 0;
    vector<WordInfo> wordInfoVec;
    for (auto const& it : wordFreq) { // for each word in the map
        string word = it.first;
        int freq = it.second;
        WordInfo wordInfo;
        wordInfo.word = word;
        wordInfo.count = freq;
        wordInfo.length = word.length();
        if (wordInfo.length <= maxLength) { // if word is short enough
            if ((word[0] == 'a' || word[0] == 'e' || word[0] == 'i' || word[0] == 'o' || word[0] == 'u')) { // if word starts with a vowel
                vowelWords += freq;
                if (wordType == 'v') {
                    wordInfoVec.push_back(wordInfo);
                }
            } else if (wordType == 'c') { // if word starts with a consonant
                wordInfoVec.push_back(wordInfo);
            }
        }
    }
    outfile << "There are " << vowelWords << " words that start with a vowel." << endl;

    // Sort the vector based on sortType
    if (sortType == 'c') {
        sort(wordInfoVec.begin(), wordInfoVec.end(), compareByCount);
    } else if (sortType == 'l') {
        sort(wordInfoVec.begin(), wordInfoVec.end(), compareByLength);
    }

    // Write sorted WordInfo vector
    vector<string> distinctWords;
    int distinctCount = 0;
    for (auto const& wordInfo : wordInfoVec) {
        distinctCount++;
        if (find(distinctWords.begin(), distinctWords.end(), wordInfo.word) == distinctWords.end()) {
            distinctWords.push_back(wordInfo.word);
            outfile << wordInfo.word << " {Word Length: " << wordInfo.length << "}: " << wordInfo.count << endl;
        }
    }
    outfile << "There are " << distinctCount << " distinct words with length " << maxLength << " or less" << endl;

    outfile.close();
}


int main() {
    string filename = "small.txt";
    map<string, int> wordFreq;
    processFile(filename, wordFreq);
    writeStatistics("statistics.txt", wordFreq, 'c', 'c', 5);
    return 0;
}
