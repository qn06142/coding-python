#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

// Function to compute gcd
int gcd(int a, int b) {
    while (b) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to compute lcm
long long lcm(long long a, long long b) {
    return a / gcd(a, b) * b;
}

// Function to find the cycle length for a spider
int find_cycle_length(int start, vector<int>& r, vector<bool>& visited) {
    int current = start, length = 0;

    // Traverse the cycle until we return to the start
    while (!visited[current]) {
        visited[current] = true;
        current = r[current]; // Move to the next spider
        length++;
    }

    return length;
}

int solve(int n, vector<int>& r) {
    vector<bool> visited(n, false);
    long long result = 1;

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            int cycle_length = find_cycle_length(i, r, visited);
            result = lcm(result, cycle_length);
        }
    }
    
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> r(n);
        for (int i = 0; i < n; ++i) {
            cin >> r[i];
            --r[i]; // Convert to 0-based indexing
        }

        cout << solve(n, r) << endl;
    }

    return 0;
}
