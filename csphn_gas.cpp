#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k; // Read the number of gas stations and tank capacity

    vector<int> cost(n);
    for (int i = 0; i < n; ++i) {
        cin >> cost[i]; // Read the cost at each gas station
    }

    // Greedy algorithm to find the minimum starting station
    int tank = 0; // Remaining gas in the tank
    int start = 0; // Starting station
    int sumGas = 0; // Total gas available
    int sumCost = 0; // Total cost

    for (int i = 0; i < n; ++i) {
        sumGas += cost[i];
        sumCost += cost[i];
        tank += (cost[i] - k);

        if (tank < 0) {
            start = i + 1; // Choose the next station as the starting point
            tank = 0;
        }
    }

    if (sumGas < sumCost) {
        cout << -1 << endl; // Cannot complete the circuit
    } else {
        cout << start << endl; // Print the minimum starting station index
    }

    return 0;
}
