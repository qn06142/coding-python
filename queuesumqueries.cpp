#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;
    vector<int> students(n);
    for(int i=0; i<n; i++)
        cin >> students[i];

    vector<vector<int>> prefix_sums(n+1, vector<int>(3, 0));

    for(int i=1; i<=n; i++) {
        prefix_sums[i] = prefix_sums[i-1];
        prefix_sums[i][students[i-1]-1]++;
    }

    for(int i=0; i<q; i++) {
        int l, r;
        cin >> l >> r;
        vector<int> result(3);
        for(int j=0; j<3; j++)
            result[j] = prefix_sums[r][j] - prefix_sums[l-1][j];
        for(int j=0; j<3; j++)
            cout << result[j] << " ";
        cout << "\n";
    }

    return 0;
}