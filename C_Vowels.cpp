#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
static const int M = 1<<24;

int32_t g[M];
int cnt_small[25];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        int m = 0;
        for(int j=0; j<3; j++){
            char c; 
            cin >> c;
            m |= 1 << (c - 'a');
        }
        g[m]++;
    }
    for(int d=0; d<24; d++){
        int bit = 1 << d;
        for(int T = 0; T < M; T++){
            if (T & bit){
                g[T] += g[T ^ bit];
            }
        }
    }
    uint32_t ans = 0;
    for(int T=0; T<M; T++){
        uint32_t x = uint32_t(n - g[T]);
        ans ^= x * x;
    }

    cout << ans << "\n";
}
