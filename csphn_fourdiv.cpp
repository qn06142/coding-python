#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_D = 1000000;
vector<int> dp(MAX_D + 1, 0);

int main() {
    vector<int> candidates;

    // Generate candidate numbers
    for (int p = 1; p <= MAX_D; ++p) {
        for (int q = p; q <= MAX_D / p; ++q) {
            candidates.push_back(p * q);
            if (p * q > MAX_D / p) break;
            for (int r = q; r <= MAX_D / (p * q); ++r) {
                candidates.push_back(p * q * r);
            }
        }
    }

    // Sort and remove duplicates
    sort(candidates.begin(), candidates.end());
    candidates.erase(unique(candidates.begin(), candidates.end()), candidates.end());

    // Precompute the smallest n for each d
    for (int n : candidates) {
        vector<int> divisors;
        for (int i = 1; i * i <= n; ++i) {
            if (n % i == 0) {
                divisors.push_back(i);
                if (i != n / i) divisors.push_back(n / i);
            }
        }
        sort(divisors.begin(), divisors.end());
        if (divisors.size() >= 4) {
            for (size_t i = 0; i < divisors.size(); ++i) {
                for (size_t j = i + 1; j < divisors.size(); ++j) {
                    int diff = divisors[j] - divisors[i];
                    if (diff <= MAX_D) {
                        if (dp[diff] == 0) dp[diff] = n;
                    }
                }
            }
        }
    }

    int T;
    cin >> T;
    while (T--) {
        int d;
        cin >> d;
        cout << dp[d] << endl;
    }

    return 0;
}
