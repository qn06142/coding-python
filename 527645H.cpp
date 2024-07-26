#include <iostream>
using namespace std;

// Function to count trailing zeros in factorial of x
long long countTrailingZeros(long long x) {
    long long count = 0;
    while (x >= 5) {
        x /= 5;
        count += x;
    }
    return count;
}

int main() {
    long long n;
    cin >> n;

    long long low = 0;
    long long high = 5 * n;
    long long result = high;

    while (low <= high) {
        long long mid = (low + high) / 2;
        if (countTrailingZeros(mid) >= n) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << result << endl;
    return 0;
}
