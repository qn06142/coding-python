#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n, q;
    cin >> m >> n >> q;

    vector<vector<ll>> a(m, vector<ll>(n));
    vector<vector<ll>> prefix(m, vector<ll>(n+1, 0));
    vector<ll> cycle_time(m);

    for(int i = 0; i < m; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j-1];
            prefix[i][j] = prefix[i][j-1] + a[i][j-1];
        }
        cycle_time[i] = prefix[i][n];
    }

    while(q--){
        ll t;
        cin >> t;

        int best_group = 1;
        ll best_L = -1, best_F = 0, best_T = 1; 

        for(int i = 0; i < m; i++){
            ll S = cycle_time[i];
            ll full_cycles = t / S;
            ll rem = t % S;

            int j = int(upper_bound(prefix[i].begin(), prefix[i].end(), rem)
                        - prefix[i].begin()) - 1;
            ll L = full_cycles * n + j;
            ll F = rem - prefix[i][j];
            ll T = (j < n ? a[i][j] : 1);  

            bool take_i = false;
            if(L > best_L) {
                take_i = true;
            }
            else if(L == best_L) {

                __int128 lhs = (__int128)F * best_T;
                __int128 rhs = (__int128)best_F * T;
                if(lhs > rhs) take_i = true;
                else if(lhs == rhs && i+1 < best_group) take_i = true;
            }

            if(take_i){
                best_group = i+1;
                best_L = L;
                best_F = F;
                best_T = T;
            }
        }

        cout << best_group << "\n";
    }

    return 0;
}