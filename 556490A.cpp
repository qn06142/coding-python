#include <bits/stdc++.h>
using namespace std;

#define int long long

struct Army {
    int count, strength;
};

bool canEliminate(vector<Army>& armies, int n, int k, int d, int mid) {
    vector<int> soldiers;
    
    for (auto& army : armies) {
        for (int i = 0; i < army.count; ++i) {
            soldiers.push_back(army.strength);
        }
    }

    sort(soldiers.begin(), soldiers.end());
    int total = 0;
    int left = 0, sum = 0;

    for (int right = 0; right < soldiers.size(); ++right) {
        while (soldiers[right] - soldiers[left] > d) {
            left++;
        }
        if ((right - left + 1) >= mid) {
            total += mid;
            if (total >= k) {
                return true;
            }
            left = right - (right - left + 1) % mid;
        }
    }
    return false;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, k, d;
    cin >> n >> k >> d;

    vector<Army> armies(n);
    for (int i = 0; i < n; ++i) {
        cin >> armies[i].count >> armies[i].strength;
    }

    int left = 0, right = 1e14, answer = 0;

    while (left <= right) {
        int mid = (left + right) / 2;
        if (canEliminate(armies, n, k, d, mid)) {
            answer = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    cout << answer << "\n";
    return 0;
}
