#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 100000;

// Function to precompute the sum of proper divisors for all numbers up to MAX_N
vector<int> precomputeSumOfDivisors() {
    vector<int> sum_divisors(MAX_N + 1, 0);
    for (int i = 1; i <= MAX_N; ++i) {
        for (int j = 2 * i; j <= MAX_N; j += i) {
            sum_divisors[j] += i;
        }
    }
    return sum_divisors;
}

// Fenwick Tree class
class FenwickTree {
    vector<int> tree;
    int n;

public:
    FenwickTree(int size) : n(size) {
        tree.resize(size + 1, 0);
    }

    void update(int index, int value) {
        while (index <= n) {
            tree[index] += value;
            index += index & -index;
        }
    }

    int query(int index) {
        int sum = 0;
        while (index > 0) {
            sum += tree[index];
            index -= index & -index;
        }
        return sum;
    }

    int range_query(int left, int right) {
        return query(right) - query(left - 1);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Precompute the sum of proper divisors for all numbers up to MAX_N
    vector<int> sum_divisors = precomputeSumOfDivisors();

    // Read number of queries
    int Q;
    cin >> Q;

    // Prepare for handling multiple queries efficiently
    vector<int> L(Q), R(Q), X(Q);
    for (int q = 0; q < Q; ++q) {
        cin >> L[q] >> R[q] >> X[q];
    }

    // Process each unique X value to avoid redundant calculations
    vector<int> results(Q);
    for (int q = 0; q < Q; ++q) {
        int x = X[q];

        // Create a Fenwick Tree for current X
        FenwickTree fenwickTree(MAX_N);

        // Populate the Fenwick Tree
        for (int i = 1; i <= MAX_N; ++i) {
            if (sum_divisors[i] > x) {
                fenwickTree.update(i, 1);
            }
        }

        // Answer each query using the Fenwick Tree
        for (int q = 0; q < Q; ++q) {
            if (X[q] == x) {
                results[q] = fenwickTree.range_query(L[q], R[q]);
            }
        }
    }

    // Output all results
    for (const int& result : results) {
        cout << result << endl;
    }

    return 0;
}
