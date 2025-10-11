#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    int N = 2*n + 1;
    vector<ll> A(N);
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }

    // Build two multisets:
    //  low  will contain the smallest (n+1) elements  -> we take its max() as the median
    //  high will contain the remaining n elements
    multiset<ll> low, high;
    vector<ll> sorted = A;
    sort(sorted.begin(), sorted.end());
    for(int i = 0; i <= n; i++)        low.insert(sorted[i]);
    for(int i = n+1; i < N; i++)       high.insert(sorted[i]);

    auto rebalance = [&](){
        // ensure |low| == n+1
        while((int)low.size() > n+1){
            auto it = prev(low.end());
            high.insert(*it);
            low.erase(it);
        }
        while((int)low.size() < n+1){
            auto it = high.begin();
            low.insert(*it);
            high.erase(it);
        }
    };

    // Process queries
    for(int qi = 0; qi < m; qi++){
        int idx;
        ll k;
        cin >> idx >> k;
        // --- remove old ---
        ll old = A[idx];
        if(old <= *prev(low.end()))
            low.erase(low.find(old));
        else
            high.erase(high.find(old));

        // --- insert new ---
        A[idx] = k;
        if(low.empty() || k <= *prev(low.end()))
            low.insert(k);
        else
            high.insert(k);

        // --- rebalance & output median ---
        rebalance();
        ll median = *prev(low.end());
        cout << median << "\n";
    }

    return 0;
}
