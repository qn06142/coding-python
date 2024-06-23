#include <iostream>
#include <vector>
using namespace std;

int findMinBoxOpenings(int n, vector<int>& keys) {
    vector<bool> visited(n + 1, false);
    int cycles = 0;

    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            // Start a new cycle
            cycles++;
            int current = i;
            while (!visited[current]) {
                visited[current] = true;
                current = keys[current - 1];  // Move to the next box in the cycle
            }
        }
    }

    return cycles;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> keys(n);

    for (int i = 0; i < n; ++i) {
        cin >> keys[i];
    }

    cout << findMinBoxOpenings(n, keys) << endl;

    return 0;
}
