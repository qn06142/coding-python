#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast,fast-math,unroll-loops")
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long m, n;
    cin >> m >> n;
    long long res = 0;

    for (int q = 1; q < n; q++) {
        long long base = n + q;
        for (long long k = 1;; k++) {
            long long p = k * base - m;
            if (p <= 0) continue;  // p must be positive
            if (p >= m) break;     // p must be less than m
            res++;
        }
    }

    cout << res << "\n";
    return 0;
}
