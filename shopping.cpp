#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
#define int long long
signed main() {
    int n, x, y;
    cin >> n >> x >> y;

    vector<pair<int, int>> items(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> items[i].first >> items[i].second;
    }

    sort(items.begin() + 1, items.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return (a.first - a.second) > (b.first - b.second);
    });

    vector<int> sum_a(n + 1, 0);
    priority_queue<int, vector<int>, greater<int>> pq_a;
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        sum += items[i].first;
        pq_a.push(items[i].first);
        if (pq_a.size() > x) {
            sum -= pq_a.top();
            pq_a.pop();
        }
        sum_a[i] = sum;
    }

    vector<int> sum_b(n + 2, 0); 
    priority_queue<int, vector<int>, greater<int>> pq_b;
    sum = 0;
    for (int i = n; i >= 1; --i) {
        sum += items[i].second;
        pq_b.push(items[i].second);
        if (pq_b.size() > y) {
            sum -= pq_b.top();
            pq_b.pop();
        }
        sum_b[i] = sum;
    }

    int max_value = 0;
    for (int i = 0; i <= n; ++i) {
        if (i >= x && (n - i) >= y) {
            max_value = max(max_value, sum_a[i] + sum_b[i + 1]);
        }
    }

    cout << max_value << endl;

    return 0;
}