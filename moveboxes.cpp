#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

long long min_cost_to_sort_boxes(int N, const vector<int>& A, const vector<int>& W) {
    vector<bool> visited(N, false);
    long long total_cost = 0;
    int global_min_weight = *min_element(W.begin(), W.end());

    for (int start = 0; start < N; ++start) {
        if (!visited[start]) {
            int current = start;
            long long cycle_weight_sum = 0;
            int min_in_cycle = INT_MAX;
            int cycle_length = 0;

            while (!visited[current]) {
                visited[current] = true;
                cycle_length++;
                cycle_weight_sum += W[current];
                min_in_cycle = min(min_in_cycle, W[current]);
                current = A[current] - 1;
            }

            if (cycle_length > 1) {
                long long cost_using_cycle_min = cycle_weight_sum + (cycle_length - 2) * min_in_cycle;
                long long cost_using_global_min = cycle_weight_sum + min_in_cycle + (cycle_length + 1) * global_min_weight;
                total_cost += min(cost_using_cycle_min, cost_using_global_min);
            }
        }
    }

    return total_cost;
}

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    vector<int> W(N);

    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    for (int i = 0; i < N; ++i) {
        cin >> W[i];
    }

    cout << min_cost_to_sort_boxes(N, A, W) << endl;

    return 0;
}