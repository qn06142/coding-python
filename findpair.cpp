#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to calculate gcd of two numbers
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

// Function to count pairs (a, b) with a + b <= mid and a * b divisible by k
long long countPairs(int n, int k, int mid) {
    long long count = 0;
    for (int a = 1; a <= n; ++a) {
        int maxB = min(n, mid - a);
        if (maxB <= 0) break;
        int k_gcd_a = k / gcd(k, a);
        count += (maxB / k_gcd_a);
    }
    return count;
}

// Main function to find the v-th pair
pair<int, int> findVthPair(int n, int k, int v) {
    int left = 2, right = 2 * n;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (countPairs(n, k, mid) < v)
            left = mid + 1;
        else
            right = mid;
    }

    // Now left is the sum of the v-th pair
    int sum = left;
    v -= countPairs(n, k, sum - 1);

    // Find the exact pair
    for (int a = 1; a <= n; ++a) {
        int maxB = min(n, sum - a);
        if (maxB <= 0) break;
        int k_gcd_a = k / gcd(k, a);
        if (maxB % k_gcd_a == 0) {
            if (--v == 0)
                return {a, maxB};
        }
    }
    return {-1, -1}; // In case no pair is found
}

int main() {
    int n, k, v;
    cin >> n >> k >> v;

    pair<int, int> result = findVthPair(n, k, v);
    cout << result.first << " " << result.second << endl;

    return 0;
}
