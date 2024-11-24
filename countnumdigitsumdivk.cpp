#include<bits/stdc++.h>
using namespace std;

const int MAX_DIGITS = 20;

long long dp[MAX_DIGITS][2][100][100];

void getDigits(long long x, vector<int>& digits) {
    digits.clear();
    while (x > 0) {
        digits.push_back(x % 10);
        x /= 10;
    }
    if (digits.empty()) {
        digits.push_back(0);
    }
    reverse(digits.begin(), digits.end());
}

long long countNumbers(int pos, bool tight, int sumMod, int numMod, int k, const vector<int>& digits) {
    if (pos == digits.size()) {
        return (sumMod == 0 && numMod == 0) ? 1 : 0;
    }
    if (dp[pos][tight][sumMod][numMod] != -1) {
        return dp[pos][tight][sumMod][numMod];
    }
    long long result = 0;
    int limit = tight ? digits[pos] : 9;
    for (int d = 0; d <= limit; ++d) {
        result += countNumbers(pos + 1, tight && (d == limit), (sumMod + d) % k, (numMod * 10 + d) % k, k, digits);
    }
    return dp[pos][tight][sumMod][numMod] = result;
}

long long countUpTo(long long x, int k) {
    if (x == 0) {
        return 0;
    }
    vector<int> digits;
    getDigits(x, digits);
    memset(dp, -1, sizeof(dp));
    return countNumbers(0, true, 0, 0, k, digits) - 1;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long a, b;
        int k;
        cin >> a >> b >> k;
        if (k >= 100) {
            cout << "0\n";
            continue;
        }
        long long result = countUpTo(b, k) - countUpTo(a - 1, k);
        cout << result << "\n";
    }
    return 0;
}