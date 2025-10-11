#include <bits/stdc++.h>
using namespace std;
using ll = long long;

static const int BUF_SZ = 1<<20;
static char ibuf[BUF_SZ], *iptr = ibuf, *iend = ibuf;
static inline char read_char() {
    if (iptr == iend) {
        iend = ibuf + fread(ibuf,1,BUF_SZ,stdin);
        iptr = ibuf;
        if (iptr == iend) return EOF;
    }
    return *iptr++;
}
static inline bool read_int(int &x) {
    char c; int sign = 1; x = 0;
    do { c = read_char(); if (c == EOF) return false; } while (c != '-' && (c < '0' || c > '9'));
    if (c == '-') { sign = -1; c = read_char(); }
    for (; c >= '0' && c <= '9'; c = read_char())
        x = x * 10 + (c - '0');
    x *= sign;
    return true;
}
static inline void write_int(ll x, char end = '\n') {
    static char obuf[32]; int len = 0;
    if (x == 0) obuf[len++] = '0';
    else {
        if (x < 0) { putchar('-'); x = -x; }
        while (x) { obuf[len++] = char('0' + (x % 10)); x /= 10; }
    }
    for (int i = len - 1; i >= 0; --i) putchar(obuf[i]);
    putchar(end);
}

const int MAXN = 5000;
static int xs[MAXN], ys[MAXN];
static ll best[MAXN];
static bool vis[MAXN];
static int parent_arr[MAXN];
static int path_arr[MAXN];

int main(){
    int n;
    if (!read_int(n)) return 0;
    for (int i = 0; i < n; i++) {
        read_int(xs[i]);
        read_int(ys[i]);
        best[i] = LLONG_MAX;
        vis[i] = false;
        parent_arr[i] = -1;
    }

    best[0] = 0;
    ll final_cost = 0;

    for (int iter = 0; iter < n; iter++) {
        int u = -1;
        ll ubest = LLONG_MAX;

        for (int i = 0; i < n; i++) {
            if (!vis[i] && best[i] < ubest) {
                ubest = best[i];
                u = i;
            }
        }
        if (u == -1) break;
        vis[u] = true;
        if (u == n - 1) {
            final_cost = ubest;
            break;
        }

        for (int v = 0; v < n; v++) {
            if (vis[v]) continue;
            ll w = llabs(xs[u] - xs[v]) + llabs(ys[u] - ys[v]);
            ll cand = max(ubest, w);
            if (cand < best[v]) {
                best[v] = cand;
                parent_arr[v] = u;
            }
        }
    }

    int psz = 0;
    int cur = n - 1;
    while (cur != -1) {
        path_arr[psz++] = cur;
        cur = parent_arr[cur];
    }

    write_int(final_cost);
    for (int i = psz - 1; i >= 0; --i) {
        write_int(path_arr[i] + 1, i ? ' ' : '\n');
    }

    return 0;
}