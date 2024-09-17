#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

bool canAchieveAverage(const vector<int>& a, int n, int k, long double avg) {
    vector<long double> prefix(n + 1, 0);  
    for (int i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] + (a[i] - avg);  
    }

    long double min_prefix = 0;
    for (int i = k; i <= n; i++) {
        if (prefix[i] - min_prefix >= 0) {
            return true;
        }
        min_prefix = min(min_prefix, prefix[i - k + 1]);
    }

    return false;
}

long double findLargestAverage(const vector<int>& a, int n, int k) {
    long double low = -1e9, high = 1e9;  
    long double epsilon = 1e-8; 

    while (high - low > epsilon) {
        long double mid = (low + high) / 2;
        if (canAchieveAverage(a, n, k, mid)) {
            low = mid;  
        } else {
            high = mid;  
        }
    }

    return low;  
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << fixed << setprecision(5) << findLargestAverage(a, n, k) << endl;

    return 0;
}