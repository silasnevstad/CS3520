#include <iostream>
#include <fstream>
#include <map>
#include <string>

using namespace std;

const int numKeywords = 30;
string keywords[numKeywords] = {"update", "verify", "confirm", "password", "account", "secure", "bank", "paypal", "ebay", "amazon", "fedex", "irs", "ssa", "unsecured", "alert", "security", "login", "sign", "important", "validate", "verification", "online", "transaction", "access", "center", "customer", "service", "support", "compromised", "urgent"};
int pointValues[numKeywords] = {2, 2, 2, 4, 2, 2, 3, 3, 2, 2, 2, 4, 4, 3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 1, 3, 3};
map<string, int> keywordCounts;

int main() {
    string fileName;
    cout << "Enter the name of the file to scan: ";
    cin >> fileName;

    ifstream inputFile(fileName);
    if (inputFile.fail()) {
        cout << "Error opening file " << fileName << endl;
        return 1;
    }

    string line;
    while (getline(inputFile, line)) { // loop through each line
        for (int i = 0; i < numKeywords; i++) { // loop through each keyword
            int pos = -1; // start at -1 so that the first call to find() will start at 0
            do {
                pos = line.find(keywords[i], pos + 1); // find the next occurrence of the keyword
                if (pos != -1) { 
                    keywordCounts[keywords[i]]++; // increment the count for the keyword if it was found
                }
            } while (pos != -1); // keep looping until the keyword is not found
        }
    }

    int totalPoints = 0;
    for (int i = 0; i < numKeywords; i++) { // loop through each keyword
        int count = keywordCounts[keywords[i]];
        if (count > 0) { // only print the keyword if it was found
            cout << keywords[i] << ": " << count << " occurrences, " << count * pointValues[i] << " points" << endl;
            totalPoints += count * pointValues[i];
        }
    }

    cout << "Total points: " << totalPoints << endl;
    return 0;
}