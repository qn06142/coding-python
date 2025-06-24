#include <bits/stdc++.h>
using namespace std;

struct Query {
    int l, r, idx;
    int block;
    bool operator<(Query const& o) const {
        if (block != o.block) return block < o.block;

        return (block & 1) ? (r < o.r) : (r > o.r);
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for(int &x : a) cin >> x;

    vector<int> vals = a;
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());

    vals.erase(remove_if(vals.begin(), vals.end(),
                [&](int x){ return x > n; }),
               vals.end());

    vector<int> b(n), orig;
    orig.reserve(vals.size());
    for(int i = 0; i < (int)vals.size(); i++){
        orig.push_back(vals[i]);
    }
    for(int i = 0; i < n; i++){
        int x = a[i];
        auto it = lower_bound(vals.begin(), vals.end(), x);
        if (it != vals.end() && *it == x)
            b[i] = int(it - vals.begin());
        else
            b[i] = -1;  
    }

    int q;
    cin >> q;
    int B = max(1, int(n / max(1.0, sqrt(q)))); 
    vector<Query> qs(q);
    for(int i = 0; i < q; i++){
        cin >> qs[i].l >> qs[i].r;
        --qs[i].l; 

        qs[i].r = qs[i].r; 
        qs[i].idx = i;
        qs[i].block = qs[i].l / B;
    }
    sort(qs.begin(), qs.end());

    vector<int> ans(q);
    vector<int> cnt(orig.size(), 0);
    int cur_l = 0, cur_r = 0;
    int cur_ans = 0;

    auto add = [&](int pos){
        int v = b[pos];
        if (v < 0) return;
        int x = orig[v];

        if (cnt[v] == x) --cur_ans;
        cnt[v]++;
        if (cnt[v] == x) ++cur_ans;
    };
    auto remove = [&](int pos){
        int v = b[pos];
        if (v < 0) return;
        int x = orig[v];
        if (cnt[v] == x) --cur_ans;
        cnt[v]--;
        if (cnt[v] == x) ++cur_ans;
    };

    for(auto &qr : qs){
        int L = qr.l, R = qr.r;
        while(cur_l > L) add(--cur_l);
        while(cur_r < R) add(cur_r++);
        while(cur_l < L) remove(cur_l++);
        while(cur_r > R) remove(--cur_r);
        ans[qr.idx] = cur_ans;
    }
    for(int i = 0; i < q; i++){
        cout << ans[i] << "\n";
    }
}