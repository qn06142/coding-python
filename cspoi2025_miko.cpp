#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct SegTree {
    int n;
    vector<int> st;
    SegTree(int _n=0){ init(_n); }
    void init(int _n){
        n = 1;
        while(n < _n) n <<= 1;
        st.assign(2*n, 0);
    }
    void build(const vector<int>& a){ 
        int m = (int)a.size()-1;
        init(m+1);
        for(int i=1;i<=m;i++) st[n+i] = a[i];
        for(int i=n-1;i>0;i--) st[i] = max(st[2*i], st[2*i+1]);
    }
    int range_max(int L, int R){ 
        if(L>R) return 0;
        L += n; R += n;
        int res = 0;
        while(L<=R){
            if(L&1) res = max(res, st[L++]);
            if(!(R&1)) res = max(res, st[R--]);
            L >>= 1; R >>= 1;
        }
        return res;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    if(!(cin>>n)) return 0;

    vector<int> a(n+1, 0);
    for(int i=1;i<=n-1;i++){
        cin >> a[i];
    }
    SegTree seg;
    seg.build(a);

    long long ans = 0;
    for(int i=1;i<=n-1;i++){
        int prev = i;
        int t = 1;
        int cur = a[i]; 
        if(cur <= prev) continue; 

        ans += 1LL * t * (cur - prev);

        while(true){

            int L = prev + 1;
            int R = cur;
            if(L > R) break;
            int nxt = seg.range_max(L, R);
            if(nxt <= cur) break; 
            t++;
            ans += 1LL * t * (nxt - cur);
            prev = cur;
            cur = nxt;
            if(cur >= n) break;
        }
    }

    cout << ans;
}