#include <bits/stdc++.h>
using namespace std;

// Function to count numbers with exactly n digits divisible by 2^X
#define int long long
long long bruteForce(int n, int X) {
    int modVal = 1LL << X; // 2^X
    long long count = 0;

    // Generate all n-digit numbers
    long long start = pow(10, n - 1); // Smallest n-digit number
    long long end = pow(10, n) - 1;  // Largest n-digit number

    for (long long num = start; num <= end; ++num) {
        if (num % modVal == 0) {
            ++count; // Increment count if divisible by 2^X
        }
    }

    return count;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    int T;
    cin >> T;
    while (T--) {
        int n, X;
        cin >> n >> X;
        cout << bruteForce(n, X) << "\n";
    }

    return 0;
}
