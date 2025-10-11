#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

struct SegTree {
    struct Node {
        long long mn, lazy;
    };
    int n;
    vector<Node> st;
    SegTree(int _n): n(_n), st(4*n+4, {0,0}) {}

    void build(int p, int l, int r, const vector<long long>& A) {
        if (l == r) {
            st[p].mn = A[l];
            return;
        }
        int m = (l+r)>>1;
        build(p<<1,   l, m, A);
        build(p<<1|1, m+1, r, A);
        st[p].mn = min(st[p<<1].mn, st[p<<1|1].mn);
    }
    void build(const vector<long long>& A) { build(1,1,n,A); }

    void push(int p) {
        long long &lz = st[p].lazy;
        if (!lz) return;
        for (int ch : {p<<1, p<<1|1}) {
            st[ch].mn   += lz;
            st[ch].lazy += lz;
        }
        lz = 0;
    }

    void update(int p, int l, int r, int L, int R, long long v) {
        if (R<l || r<L) return;
        if (L<=l && r<=R) {
            st[p].mn   += v;
            st[p].lazy+= v;
            return;
        }
        push(p);
        int m = (l+r)>>1;
        update(p<<1,   l, m, L, R, v);
        update(p<<1|1, m+1, r, L, R, v);
        st[p].mn = min(st[p<<1].mn, st[p<<1|1].mn);
    }
    void update(int L, int R, long long v) { update(1,1,n,L,R,v); }

    int lastl(int p, int l, int r, int L, int R, long long k) {
        if (R<l || r<L || st[p].mn >= k) return 0;
        if (l==r) return l;
        push(p);
        int m = (l+r)>>1;

        int res = lastl(p<<1|1, m+1, r, L, R, k);
        if (res) return res;
        return lastl(p<<1, l, m, L, R, k);
    }
    int lastl(int L, int R, long long k) {
        if (L>R) return 0;
        return lastl(1,1,n,L,R,k);
    }

    long long get_min() const { return st[1].mn; }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,q;
    cin >> n >> q;
    string s;
    cin >> s;
    s = " " + s;            

    vector<long long> S(n+1,0);
    for (int i = 1; i <= n; i++)
        S[i] = S[i-1] + (s[i]=='('? +1 : -1);

    SegTree st(n);
    st.build(S);

    set<int> openp, closep;
    for (int i = 1; i <= n; i++) {
        if (s[i]=='(') openp.insert(i);
        else           closep.insert(i);
    }

    vector<int> ans(q);
    for (int qi = 0; qi < q; qi++) {
        int p; 
        cin >> p;

        if (s[p] == ')') {

            closep.erase(p);
            openp.insert(p);
            s[p] = '(';

            st.update(p, n, +2);

            int t = st.lastl(1, p-1, 2);
            int a = t + 1;

            openp.erase(a);
            closep.insert(a);
            s[a] = ')';

            st.update(a, n, -2);

            ans[qi] = a;
        }
        else {

            openp.erase(p);
            closep.insert(p);
            s[p] = ')';
            st.update(p, n, -2);

            auto it = closep.begin();
            int a = *it;  
            closep.erase(it);
            openp.insert(a);
            s[a] = '(';

            st.update(a, n, +2);

            ans[qi] = a;
        }
    }

    for (int i = 0; i < q; i++) {
        cout << ans[i] << (i+1<q?' ':'\n');
    }
}