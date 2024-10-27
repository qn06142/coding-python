#include <iostream>
#include <vector>
#include <deque>
#include <iomanip>

using namespace std;

bool canAchieveAverage(const vector<int>& a, int n, int l, int r, long double avg) {
    vector<long double> prefix(n + 1, 0);  
    for (int i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] + (a[i] - avg);  
    }

    deque<int> dq;  
    for (int i = l; i <= n; i++) {
        // Maintain deque for the minimum in the window size [l, r]
        if (!dq.empty() && dq.front() < i - r + 1) {
            dq.pop_front();
        }

        // Check if we can achieve the average with the current prefix difference
        if (!dq.empty() && prefix[i] - prefix[dq.front()] >= 0) {
            return true;
        }

        // Ensure to add i - l to the deque, maintaining the min-prefix property
        while (!dq.empty() && prefix[dq.back()] >= prefix[i - l + 1]) {
            dq.pop_back();
        }
        dq.push_back(i - l + 1);
    }

    return false;
}

long double findLargestAverage(const vector<int>& a, int n, int l, int r) {
    long double low = -1e9, high = 1e9;  
    long double epsilon = 1e-8; 

    while (high - low > epsilon) {
        long double mid = (low + high) / 2;
        if (canAchieveAverage(a, n, l, r, mid)) {
            low = mid;  
        } else {
            high = mid;  
        }
    }

    return low;  
}

int main() {
    int n, l, r;
    cin >> n >> l >> r;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << fixed << setprecision(5) << findLargestAverage(a, n, l, r) << endl;

    return 0;
}
