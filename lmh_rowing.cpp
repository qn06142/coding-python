#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    ll h;
    cin >> n >> h;

    vector<ll> x(n+2), y(n+2);
    x[0] = 0;        y[0]        = h;  
    x[n+1] = 0;      y[n+1]      = 0;  
    for(int i = 1; i <= n; i++){
        cin >> x[i] >> y[i];
    }

    const ll INF = LLONG_MAX;
    vector<ll> dist_sq(n+2, INF);
    dist_sq[0] = 0;

    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<>> pq;
    pq.emplace(0, 0);

    vector<char> seen(n+2, 0);

    while(!pq.empty()){
        auto [d2, u] = pq.top(); 
        pq.pop();
        if(seen[u] || d2 != dist_sq[u]) continue;
        if(u == n+1) break;     
        seen[u] = 1;

        for(int v = 0; v < n+2; v++){
            if(seen[v] || v == u) continue;
            ll dx = x[u] - x[v];
            ll dy = y[u] - y[v];
            ll edge_sq = dx*dx + dy*dy;
            ll cand  = max(d2, edge_sq);
            if(cand < dist_sq[v]){
                dist_sq[v] = cand;
                pq.emplace(cand, v);
            }
        }
    }

    ll ans = (ll)floor(sqrt((long double)dist_sq[n+1]));
    cout << ans << "\n";
    return 0;
}