#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005

int n;
long long a[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    while (q--) {
        int l, r;
        cin >> l >> r;
        
        vector<int> filtered;
        for (int i = 0; i < n; i++) {
            if (l <= a[i] && a[i] <= r) {
                filtered.push_back(a[i]);
            }
        }
        
        long long diff = 0;
        if (!filtered.empty()) {
            for (size_t i = 0; i < filtered.size() - 1; i++) {
                diff += abs(filtered[i] - filtered[i + 1]);
            }
        }
        
        cout << diff << endl;
    }
    

    return 0;
}