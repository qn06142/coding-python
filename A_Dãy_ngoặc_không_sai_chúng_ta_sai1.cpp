#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

// Check if the sequence is valid parentheses
bool isValid(const string &s) {
    int balance = 0;
    for (char c : s) {
        if (c == '(') balance++;
        else balance--;
        if (balance < 0) return false; // invalid
    }
    return balance == 0;
}

// Check if the sequence is "beautiful"
bool isBeautiful(const string &s) {
    int n = s.size();
    for (int i = 0; i < n; ++i) {
        char rotatedChar = (s[n - i - 1] == '(') ? ')' : '(';
        if (s[i] != rotatedChar) return false;
    }
    return true;
}

int main() {
    int n;
    string s;
    cin >> n >> s;
    
    long long result = 0;

    // Iterate through all subsequences using bitmasking
    int totalSubsequences = (1 << n); // 2^n subsequences
    for (int mask = 1; mask < totalSubsequences; ++mask) {
        string sub;
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                sub += s[i];
            }
        }
        if (isValid(sub) && isBeautiful(sub)) {
            result = (result + 1) % MOD;
        }
    }
    
    // Output the result
    cout << result << endl;
    return 0;
}
