#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    int64 mod;
    cin >> n >> m >> mod;

    vector<int> col_deg(n, 0);

    for(int i = 0; i < m; i++){
        string s;
        cin >> s;
        int cnt1 = 0;
        for(int j = 0; j < n; j++){
            if(s[j] == '1'){
                col_deg[j]++;
                cnt1++;
            }
        }
        if(cnt1 != 2){

            cout << 0 << "\n";
            return 0;
        }
    }

    int r = n - m;         
    int x0 = 0, y0 = 0;    
    for(int j = 0; j < n; j++){
        int need = 2 - col_deg[j];
        if(need < 0 || need > 2){
            cout << 0 << "\n";
            return 0;
        }
        if(need == 1) x0++;
        else if(need == 2) y0++;
    }
    if(x0 + 2*y0 != 2*r){
        cout << 0 << "\n";
        return 0;
    }

    int max_x = 2*r;
    vector<int64> dp(max_x+1, 0), ndp(max_x+1, 0);
    dp[x0] = 1;

    for(int k = 0; k < r; k++){
        fill(ndp.begin(), ndp.end(), 0);

        int S = 2*(r - k);
        for(int x = 0; x <= S; x += 1){
            int64 ways = dp[x];
            if(!ways) continue;
            int y = (S - x) / 2;

            if(y >= 2){
                int64 c = int64(y) * (y - 1) / 2 % mod;
                ndp[x + 2] = (ndp[x + 2] + ways * c) % mod;
            }

            if(y >= 1 && x >= 1){
                int64 c = int64(y) * x % mod;
                ndp[x] = (ndp[x] + ways * c) % mod;
            }

            if(x >= 2){
                int64 c = int64(x) * (x - 1) / 2 % mod;
                ndp[x - 2] = (ndp[x - 2] + ways * c) % mod;
            }
        }
        swap(dp, ndp);
    }

    cout << dp[0] % mod << "\n";
}