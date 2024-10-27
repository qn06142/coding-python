#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

const int MOD = 1e9 + 7;

int dp[100005][2][10][2];
string L, R;

// Helper function to perform digit DP with your suggested adjustment
int digitDP(int pos, int tight, int lastdig, int inc, const string &num) {
    if (pos == num.size()) {
        return 1; // Reached end of digits, this is a valid "Girl Number"
    }
    if (dp[pos][tight][lastdig + 1][inc] != -1) {
        return dp[pos][tight][lastdig + 1][inc];
    }

    int limit = tight ? (num[pos] - '0') : 9;
    int result = 0;

    if (inc == 1) {
        // Increasing part, digits must be less than lastdig
        for (int d = 0; d <= limit && d < lastdig; d++) {
            result = (result + digitDP(pos + 1, tight && (d == limit), d, 0, num)) % MOD;
        }
    } else {
        // Decreasing part, digits must be greater than lastdig
        for (int d = (lastdig + 1); d <= limit; d++) {
            result = (result + digitDP(pos + 1, tight && (d == limit), d, 1, num)) % MOD;
        }
    }

    return dp[pos][tight][lastdig + 1][inc] = result;
}

// Function to count "Girl Numbers" up to a given number as a string
int countGirlNumbers(const string &num) {
    memset(dp, -1, sizeof(dp));
    int result = 0;
    // Try starting with both increasing (1) and decreasing (0) for valid start
    for (int d = 1; d <= (num[0] - '0'); d++) {
        result = (result + digitDP(1, d == (num[0] - '0'), d, 1, num)) % MOD;
        result = (result + digitDP(1, d == (num[0] - '0'), d, 0, num)) % MOD;
    }
    return result;
}

// Function to find the difference between counts from L to R
int countInRange(string L, string R) {
    int countR = countGirlNumbers(R);
    
    // Decrement L to find count up to L-1
    int i = L.size() - 1;
    while (i >= 0 && L[i] == '0') {
        L[i] = '9';
        i--;
    }
    if (i >= 0) L[i]--;

    int countL = (L[0] == '0') ? 0 : countGirlNumbers(L);
    return (countR - countL + MOD) % MOD;
}

int main() {
    string tmp;
    cin >> tmp >> tmp;
    cin >> L >> R;
    cout << countInRange(L, R) << endl;
    return 0;
}
