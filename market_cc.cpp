#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fastIO ios_base::sync_with_stdio(false); cin.tie(nullptr);

unordered_map<int, int> le, ri; 

void generateLeftSubsets(vector<int>& a, int m, int index, int sum) {
    if (index > m) {
        le[sum]++;
        return;
    }
    generateLeftSubsets(a, m, index + 1, sum);          
    generateLeftSubsets(a, m, index + 1, sum + a[index]); 
}

void generateRightSubsets(vector<int>& b, int n, int index, int sum) {
    if (index > n) {
        ri[sum]++;
        return;
    }
    generateRightSubsets(b, n, index + 1, sum);          
    generateRightSubsets(b, n, index + 1, sum + b[index]); 
}

signed main() {
    fastIO
    int n, x;
    cin >> n >> x;

    if (n == 1) {
        int val;
        cin >> val;
        cout << (val == x ? 1 : 0) << "\n";
        return 0;
    }

    int m = n - n / 2; 
    n /= 2;            

    vector<int> a(m + 1), b(n + 1);
    for (int i = 1; i <= m; ++i) {
        cin >> a[i];
        a[i] -= x; 
    }
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
        b[i] -= x; 
    }

    generateLeftSubsets(a, m, 1, 0);

    generateRightSubsets(b, n, 1, 0);

    int ans = 0;
    for (auto& pair : le) {
        ans += pair.second * ri[-pair.first]; 
    }

    cout << ans - 1 << "\n"; 
    return 0;
}