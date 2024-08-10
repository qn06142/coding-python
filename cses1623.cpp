#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

using namespace std;
#define int long long
int total_weight;
int min_diff = numeric_limits<int>::max(); 

void backtrack(vector<int>& weights, int index, int group1_sum, int group2_sum) {
    if (index == (int) weights.size()) {

        int current_diff = abs(group1_sum - group2_sum);
        min_diff = min(min_diff, current_diff);
        return;
    }

    backtrack(weights, index + 1, group1_sum + weights[index], group2_sum);

    backtrack(weights, index + 1, group1_sum, group2_sum + weights[index]);
}

signed main() {
    int n;
    cin >> n;
    vector<int> weights(n);
    total_weight = 0;

    for (int i = 0; i < n; ++i) {
        cin >> weights[i];
        total_weight += weights[i];
    }

    backtrack(weights, 0, 0, 0);

    cout << min_diff << endl;

    return 0;
}