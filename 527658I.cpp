#include <iostream>
#include <vector>
using namespace std;

int countWays(const vector<int>& weights, int index, int leftSum, int rightSum) {
    // Base case: if we've placed all weights
    if (index == weights.size()) {
        return leftSum <= rightSum ? 1 : 0;
    }

    int currentWeight = weights[index];
    int count = 0;

    // Place the current weight on the left pan
    if (leftSum + currentWeight <= rightSum) {
        count += countWays(weights, index + 1, leftSum + currentWeight, rightSum);
    }
    // Place the current weight on the right pan
    count += countWays(weights, index + 1, leftSum, rightSum + currentWeight);

    return count;
}

int main() {
    int n;
    cin >> n;
    vector<int> weights(n);
    for (int i = 0; i < n; ++i) {
        cin >> weights[i];
    }

    // Start backtracking from index 0 with initial left and right sums as 0
    int result = countWays(weights, 0, 0, 0);

    cout << result << endl;
    return 0;
}
