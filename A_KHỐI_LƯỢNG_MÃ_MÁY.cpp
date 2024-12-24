#include <iostream>
#include <vector>
using namespace std;
const int MOD = 1000000007;

long long mod_exp(long long base, long long exp, int mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

void solve() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    vector<long long> results;
    
    for (int i = 0; i < t; ++i) {
        long long n;
        cin >> n;
        
        long long power_of_two = mod_exp(2, n - 1, MOD);
        
        long long result = (n * power_of_two) % MOD;
        results.push_back(result);
    }
    
    for (const auto& res : results) {
        cout << res << "\n";
    }
}

int main() {
    solve();
    return 0;
}

