#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m;
    cin >> m;
    vector<long long> b(m);
    for(int i=0;i<m;i++) cin>>b[i];
    sort(b.begin(), b.end());

    vector<long long> vals;
    vector<int> cnt;
    for(int i=0;i<m;){
        int j=i;
        while(j<m && b[j]==b[i]) j++;
        vals.push_back(b[i]);
        cnt.push_back(j-i);
        i=j;
    }
    const int BITS = 10;
    const int MASK = (1<<BITS)-1;
    const int INF_NEG = -1000000000;
    vector<int> dp(1<<BITS, INF_NEG), ndp(1<<BITS, INF_NEG);
    dp[0] = 0;
    long long prev = vals[0];
    bool first = true;
    int nvals = vals.size();
    int conflict = (1<<1) | (1<<8) | (1<<9); 
    for(int idx=0; idx<nvals; ++idx){
        long long v = vals[idx];
        int w = cnt[idx];
        if(first){

            first = false;
        }
        long long delta = (idx==0? 0 : v - prev);
        fill(ndp.begin(), ndp.end(), INF_NEG);
        if(delta >= BITS){

            int best = INF_NEG;
            for(int mask=0; mask<=MASK; ++mask) best = max(best, dp[mask]);

            ndp[0] = max(ndp[0], best); 

            ndp[1] = max(ndp[1], best + w); 
        } else {
            for(int mask=0; mask<=MASK; ++mask){
                if(dp[mask] == INF_NEG) continue;
                int shifted = ( (mask << delta) & MASK );

                ndp[shifted] = max(ndp[shifted], dp[mask]);

                if( (shifted & conflict) == 0 ){
                    int newmask = shifted | 1; 
                    ndp[newmask] = max(ndp[newmask], dp[mask] + w);
                }
            }
        }
        dp.swap(ndp);
        prev = v;
    }
    int ans = 0;
    for(int mask=0; mask<=MASK; ++mask) ans = max(ans, dp[mask]);
    int removed = m - ans;
    cout<<removed<<"\n";
}