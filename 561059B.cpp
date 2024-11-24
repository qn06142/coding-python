#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int popcnt(long long num) {
    return __builtin_popcountll(num);
}

long long divide(vector<long long>& a, int left, int right) {
    if (left == right) {
        return 1;  
    }

    int mid = (left + right) / 2;
    long long ans = 0;

    ans += divide(a, left, mid);
    ans += divide(a, mid + 1, right);

    unordered_map<int, int> cnt_left, cnt_right;

    long long current_max = a[mid], current_min = a[mid + 1];
    cnt_right[popcnt(current_min)]++;
    int j = mid + 1;

    for (int i = mid; i >= left; --i) {
        current_max = max(current_max, a[i]);

        while (j <= right && a[j] <= current_max) {
            current_min = min(current_min, a[j]);
            cnt_right[popcnt(current_min)]++;  
            j++;
        }

        ans += cnt_right[popcnt(current_max)];
    }

    cnt_right.clear();
    current_max = a[mid + 1];
    j = mid;

    for (int i = mid + 1; i <= right; ++i) {
        current_max = max(current_max, a[i]);

        while (j >= left && a[j] >= current_max) {
            cnt_left[popcnt(a[j])]++;
            j--;
        }

        ans += cnt_left[popcnt(current_max)];
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<long long> a(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    long long result = divide(a, 0, n - 1);

    cout << result << "\n";
    return 0;
}