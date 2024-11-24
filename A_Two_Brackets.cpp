#include <iostream>
#include <string>
using namespace std;

int countRBS(string s) {
    int openRound = 0, openSquare = 0;
    int validPairs = 0;

    for (char c : s) {
        if (c == '(') {
            openRound++;
        } else if (c == ')') {
            if (openRound > 0) {
                validPairs++;
                openRound--;
            }
        } else if (c == '[') {
            openSquare++;
        } else if (c == ']') {
            if (openSquare > 0) {
                validPairs++;
                openSquare--;
            }
        }
    }

    return validPairs;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        cout << countRBS(s) << endl;
    }
    return 0;
}
