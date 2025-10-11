#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    int maxv = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        maxv = max(maxv, a[i]);
    }

    int B = 0;
    while ((1 << B) <= maxv) ++B;
    if (B == 0) B = 1; 
    int size = 1 << B;
    vector<int> freq(size, 0);
    for (int v : a) freq[v]++;

    vector<int> sub = freq;
    for (int bit = 0; bit < B; ++bit) {
        for (int mask = 0; mask < size; ++mask) {
            if (mask & (1 << bit)) sub[mask] += sub[mask ^ (1 << bit)];
        }
    }

    vector<int> sup = freq;
    for (int bit = 0; bit < B; ++bit) {
        for (int mask = 0; mask < size; ++mask) {
            if (!(mask & (1 << bit))) sup[mask] += sup[mask | (1 << bit)];
        }
    }

    int full = (1 << B) - 1;
    for (int i = 0; i < n; ++i) {
        int x = a[i];
        long long subset = sub[x];                
        long long superset = sup[x];              
        long long disjoint = sub[full ^ x];      
        long long nonzero = (long long)n - disjoint;     
        cout << subset << ' ' << superset << ' ' << nonzero << '\n';
    }
}