#include <iostream>
#include <vector>
#include <climits>
#include <cmath>

using namespace std;
#define int long long
int min_cost_to_buy(int n, vector<int>& prices) {
    vector<int> prefix_sums(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        prefix_sums[i] = prefix_sums[i - 1] + prices[i];
    }

    int total_sum = prefix_sums[n];
    int min_cost = INT_MAX;

    int left = 0, right = 1;

    while (right <= n) {
        int current_sum = prefix_sums[right] - prefix_sums[left];

        int cost = abs(2 * current_sum - total_sum);
        min_cost = min(min_cost, cost);

        right++;

        while (left < right - 1 && 2 * current_sum > total_sum) {
            left++;
            current_sum = prefix_sums[right - 1] - prefix_sums[left];
            cost = abs(2 * current_sum - total_sum);
            min_cost = min(min_cost, cost);
        }
    }

    return min_cost;
}

signed main() {
    int n;
    cin >> n;

    vector<int> prices(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> prices[i];
    }

    cout << min_cost_to_buy(n, prices) << endl;
    return 0;
}

