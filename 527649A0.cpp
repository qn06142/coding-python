#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;
#define int long long
const int MAX_DIGITS = 17;

vector<vector<vector<int>>> dp;

bool isPalindrome(const string& s) {
    int n = s.size();
    for (int i = 0; i < n / 2; ++i)
        if (s[i] != s[n - 1 - i])
            return false;
    return true;
}

string toString(long long num) {
    return to_string(num);
}

int countPalindromes(const string& num, int pos, int tight, int odd, string& formed) {
    if (pos == num.size()) {
        return isPalindrome(formed);
    }

    if (dp[pos][tight][odd] != -1)
        return dp[pos][tight][odd];

    int limit = tight ? num[pos] - '0' : 9;
    int result = 0;

    for (int digit = 0; digit <= limit; ++digit) {
        formed.push_back(digit + '0');
        result += countPalindromes(num, pos + 1, tight && (digit == limit), odd ^ 1, formed);
        formed.pop_back();
    }

    return dp[pos][tight][odd] = result;
}

int countPalindromicInRange(long long x) {
    if (x < 0) return 0;
    string num = toString(x);
    string formed;
    dp = vector<vector<vector<int>>>(MAX_DIGITS, vector<vector<int>>(2, vector<int>(2, -1)));
    return countPalindromes(num, 0, 1, 0, formed);
}

signed main() {
    long long a, b;
    cin >> a >> b;

    int result = countPalindromicInRange(b) - countPalindromicInRange(a - 1);
    cout << result << endl;

    return 0;
}
