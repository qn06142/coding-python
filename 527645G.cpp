#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Hàm đếm số cặp (i, j) có tích >= x
long long countPairs(const vector<int>& a, long long x) {
    int n = a.size();
    long long count = 0;
    for (int i = 0; i < n; ++i) {
        int l = i + 1, r = n - 1, pos = i;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (1LL * a[i] * a[mid] >= x) {
                pos = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        count += (n - pos - 1);
    }
    return count;
}

int main() {
    int n;
    long long k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    sort(a.begin(), a.end());
    
    long long l = 0, r = 1LL * a[n-1] * a[n-1];
    long long ans = 0;
    while (l <= r) {
        long long mid = (l + r) / 2;
        if (countPairs(a, mid) >= k) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    
    cout << ans << endl;
    return 0;
}
