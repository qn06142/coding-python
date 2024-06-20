#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;
#define int long long
// Function to build the sparse table for range minimum queries
vector<vector<int>> build_sparse_table(vector<int>& a) {
    int n = a.size();
    vector<int> divs;
    for(int i = 1; i <= sqrt(n); i++) {
        if(n % i == 0) {
            divs.push_back(i);
            if(i!= n / i) {
                divs.push_back(n / i);
            }
        }
    }
    int k = floor(log2(n)) + 1;
    vector<vector<int>> st(n, vector<int>(k, 0));

    for (int i = 0; i < n; i++) {
        st[i][0] = a[i];
    }

    for (int j = 1; (1 << j) <= n; j++) {
        for (int i = 0; (i + (1 << j) - 1) < n; i++) {
            st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }

    return st;
}

// Function to query the minimum value in the range [l, r] using the sparse table
int query(vector<vector<int>>& st, int l, int r) {
    int j = log2(r - l + 1);
    return min(st[l][j], st[r - (1 << j) + 1][j]);
}

// Function to calculate the maximum class power given constraints
int max_class_power(int n, vector<int>& a) {
    vector<vector<int>> st = build_sparse_table(a);
    int max_power = 0;
    vector<int> divs;
    for(int i = 1; i <= sqrt(n); i++) {
        if(n % i == 0) {
            divs.push_back(i);
            if(i!= n / i) {
                divs.push_back(n / i);
            }
        }
    }
    // Iterate through all possible group sizes that divide n evenly
    for (int group_size: divs) {
        if (n % group_size == 0) {
            int num_groups = n / group_size;
            int total_power = 0;

            // Calculate the total power for this group size
            for (int i = 0; i < num_groups; i++) {
                int l = i * group_size;
                int r = (i + 1) * group_size - 1;
                int min_skill = query(st, l, r);
                total_power += min_skill * (group_size * group_size);
            }

            // Update the maximum power found so far
            max_power = max(max_power, total_power);
        }
    }

    return max_power;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << max_class_power(n, a) << endl;
    return 0;
}