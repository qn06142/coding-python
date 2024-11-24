#include <iostream>
using namespace std;

long long solve(long long n) {
    long long left = 1, right = 1000000;  
    long long result = 0;

    while (left <= right) {
        long long mid = left + (right - left) / 2;
        long long product = mid * (mid - 1) * (mid + 1);

        if (product <= n) {
            result = product; 
            left = mid + 1;   
        } else {
            right = mid - 1;  
        }
    }

    return result;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        cout << solve(n) << endl;
    }
    return 0;
}