
#include <iostream>
#include <vector>
#include <set>

using namespace std;
#define int long long
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    // Array to store values
    vector<long long> a(n + 2, -1e18);  // `a[0]` and `a[n+1]` are set to -inf initially

    // Read input and initialize sets
    set<int> id;  // Set to store the current available indices
    set<pair<int, int>> stor;  // Set to store values and their indices in sorted order

    // Insert all the values into the set
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        stor.insert(make_pair(a[i], i));
        id.insert(i);
    }

    // Add boundaries for id set
    id.insert(0);
    id.insert(n + 1);

    // Array to store results for each query
    vector<long long> res((n + 1) / 2 + 1, 0);
    long long ans = 0;

    // Process elements to combine values
    for (int i = 1; i <= (n + 1) / 2; i++) {
        // Get the largest value in the setd
        auto it = prev(stor.end());
        ans += it->first;
        res[i] = ans;

        int pos = it->second;
        stor.erase(it);  // Remove the selected element from stor

        // Find neighbors in id set
        auto it_id = id.find(pos);
        int l = *prev(it_id);  // Left neighbor
        int r = *next(it_id);  // Right neighbor

        // Update `a[pos]` by combining the neighbors
        a[pos] = a[l] + a[r] - a[pos];
        stor.insert(make_pair(a[pos], pos));  // Re-insert the updated value

        // Remove neighbors from stor and id sets
        id.erase(l);
        id.erase(r);
        stor.erase({a[l], l});
        stor.erase({a[r], r});
    }       

    // Handle queries
    int q;
    cin >> q;
    while (q--) {
        int k;
        cin >> k;
        cout << res[k] << '\n';
    }

    return 0;
}
