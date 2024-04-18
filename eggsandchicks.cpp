#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const int MAXN = 25;
pll chicken[MAXN];
ll n, x;

bool check(ll mid) {
    vector<ll> eggs;
    for(int i=0; i<n; i++){
        ll t = min(mid, chicken[i].first);
        ll cnt = (t + chicken[i].first - 1) / chicken[i].first;
        eggs.push_back(cnt * chicken[i].second);
        mid -= t;
    }
    sort(eggs.begin(), eggs.end(), greater<ll>());
    ll sum = 0;
    for(int i=0; i<min(mid, (ll)eggs.size()); i++){
        sum += eggs[i];
    }
    return sum >= x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> x;
    for(int i=0; i<n; i++){
        cin >> chicken[i].second >> chicken[i].first;
    }

    ll low = 0, high = 1e18;
    while(high - low > 1){
        ll mid = (low + high) / 2;
        if(check(mid)){
            high = mid;
        } else {
            low = mid;
        }
    }

    cout << high << "\n";

    return 0;
}
