#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 6;
int n, A[maxn], d[maxn], pre[maxn], seg[4*maxn], lazy[4*maxn];

const int INF = 1e9;

void push(int id) {
    seg[id * 2] += lazy[id];
    seg[id * 2 + 1] += lazy[id];
    lazy[id * 2] += lazy[id];
    lazy[id * 2 + 1] += lazy[id];
    lazy[id] = 0;
}

void update(int id, int l, int r, int u, int v, int x) {
    push(id); 
    if (u > r || v < l) return; 
    if (u <= l && r <= v) { 
        seg[id] += x;
        lazy[id] += x;
        return;
    }
    int m = (l + r) / 2;
    update(id * 2, l, m, u, v, x);      
    update(id * 2 + 1, m + 1, r, u, v, x); 
    seg[id] = min(seg[id * 2], seg[id * 2 + 1]); 
}

int get(int id, int l, int r, int u, int v) {
    push(id); 
    if (u > r || v < l) return INF; 
    if (u <= l && r <= v) return seg[id]; 
    int m = (l + r) / 2;
    return min(get(id * 2, l, m, u, v), get(id * 2 + 1, m + 1, r, u, v));
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;

    while (q--) {
        memset(seg, 0, sizeof seg);
        memset(lazy,0, sizeof lazy);
        memset(pre, 0, sizeof pre);
        memset(d, 0, sizeof d);
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> A[i];
            pre[i] = d[A[i]];
            d[A[i]] = i;
        }
        for (int i = 1; i <= n; i++)
        {
            update(1, 1, n, pre[i] + 1, i, 1);
            update(1, 1, n, pre[pre[i]] + 1, pre[i], -1);
            if (get(1, 1, n, 1, i) == 0) {
                cout << "NO";
                goto out;
            }
        }
        cout << "YES";
    out:
        cout << "\n";
    }
}