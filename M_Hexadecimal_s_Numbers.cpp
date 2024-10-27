#include <iostream>
#include <cstring>
using namespace std;

const int MAX_DIGITS = 20;
long long dp[MAX_DIGITS][2];
string num;

long long digitDP(int pos, bool tight) {
    if (pos == num.size()) return 1; 

    if (dp[pos][tight] != -1) return dp[pos][tight]; 

    int limit = tight ? num[pos] - '0' : 1; 
    long long res = 0;

    for (int dig = 0; dig <= limit; ++dig) {
        if (dig == 0 || dig == 1) { 
            res += digitDP(pos + 1, tight && (dig == limit)); 
        }
    }

    return dp[pos][tight] = res; 
}

long long solve(long long n) {
    num = to_string(n); 
    memset(dp, -1, sizeof(dp)); 
    return digitDP(0, 1); 
}

int main() {
    long long n;
    cin >> n;
    cout << solve(n) - 1 << endl;
    return 0;
}