#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
const int MAXA = 1000000;
const int INF = 1e9;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    if(!(cin >> N)) return 0;
    vector<int> a(N+1);
    for(int i=1;i<=N;i++) cin >> a[i];

    vector<int> spf(MAXA+1);
    for(int i=2;i<=MAXA;i++) if(!spf[i]){
        for(long long j=i;j<=MAXA;j+=i) if(!spf[j]) spf[j]=i;
    }
    spf[1]=1;

    vector<int> omega(MAXA+1,0);
    omega[1]=0;
    for(int x=2;x<=MAXA;x++){
        int p = spf[x];
        omega[x] = omega[x / p] + 1;
    }

    vector<pii> best1(MAXA+1, {INF,-1}), best2(MAXA+1, {INF,-1});

    auto push_best = [&](int v, pii cur){

        if(cur < best1[v]){
            if(best1[v].second != cur.second) best2[v] = best1[v];
            best1[v] = cur;
        } else if(cur.second != best1[v].second && cur < best2[v]){
            best2[v] = cur;
        }
    };

    auto factor = [&](int x){
        vector<pair<int,int>> res;
        while(x > 1){
            int p = spf[x];
            int cnt=0;
            while(x % p == 0){ x/=p; cnt++; }
            res.emplace_back(p,cnt);
        }
        return res;
    };

    function<vector<int>(const vector<pair<int,int>>&)> gen_divs = [&](const vector<pair<int,int>>& f){
        vector<int> ds = {1};
        for(auto &pe : f){
            int p=pe.first, e=pe.second;
            int sz = ds.size();
            long long mul = 1;
            for(int k=1;k<=e;k++){
                mul *= p;
                for(int i=0;i<sz;i++){
                    ds.push_back(ds[i] * (int)mul);
                }
            }
        }
        return ds;
    };

    for(int i=1;i<=N;i++){
        auto f = factor(a[i]);
        auto ds = gen_divs(f);
        pii cur = { omega[a[i]], i };
        for(int d : ds){
            push_best(d, cur);
        }
    }

    vector<int> ans(N+1, -1);
    for(int i=1;i<=N;i++){
        auto f = factor(a[i]);
        auto ds = gen_divs(f);
        long long bestDist = (long long)INF*2;
        int bestIdx = -1;
        for(int d : ds){

            pii cand = best1[d];
            if(cand.second == i) cand = best2[d];
            if(cand.second == -1) continue;
            int j = cand.second;
            int g = std::gcd(a[i], a[j]);
            long long dist = (long long)omega[a[i]] + omega[a[j]] - 2 * omega[g];
            if(dist < bestDist || (dist == bestDist && j < bestIdx)){
                bestDist = dist;
                bestIdx = j;
            }
        }

        if(bestIdx == -1) ans[i] = -1;
        else ans[i] = bestIdx;
    }

    for(int i=1;i<=N;i++){
        cout << ans[i] << '\n';
    }
    return 0;
}