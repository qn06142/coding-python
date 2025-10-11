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
    char c; ll sign = 1; x = 0;
    do { c = read_char(); if (c==EOF) return false; } while (c!='-' && (c<'0'||c>'9'));
    if (c=='-') { sign = -1; c = read_char(); }
    for (; c>='0' && c<='9'; c = read_char())
        x = x*10 + (c - '0');
    x *= sign;
    return true;
}
static inline void write_int(ll x, char end = '\n') {
    static char obuf[32]; int len=0;
    if (x==0) obuf[len++]='0';
    else {
        if (x<0) { putchar('-'); x=-x; }
        while (x){ obuf[len++] = '0' + (x%10); x/=10; }
    }
    for (int i=len-1;i>=0;i--) putchar(obuf[i]);
    putchar(end);
}

struct Edge { int depart, dur, to, next; };
const int MAXN = 1'000'000 + 5;
const int MAXM = 2'000'000 + 5;
static Edge edges[MAXM];
static int head[MAXN], ecnt;
inline void add_edge(int u, int v, int t, int d) {
    edges[ecnt] = {t, d, v, head[u]};
    head[u] = ecnt++;
}

struct State {
    ll time;
    int node;
    bool operator>(State const &o) const { return time > o.time; }
};

static ll dist_arr[MAXN];
static int prev_arr[MAXN];
static bool vis[MAXN];
static int path[MAXN];

int main(){
    int n, m;
    if (!read_int(n) || !read_int(m)) return 0;

    ecnt = 0;
    for(int i=0;i<n;i++){
        head[i] = -1;
        dist_arr[i] = numeric_limits<ll>::max();
        prev_arr[i] = -1;
        vis[i] = false;
    }

    for(int i=0,u,v,t,d;i<m;i++){
        read_int(u); read_int(v);
        read_int(t); read_int(d);
        --u; --v;
        add_edge(u,v,t,d);
        add_edge(v,u,t,d);
    }

    dist_arr[0] = 0;
    priority_queue<State, vector<State>, greater<State>> pq;
    pq.push({0,0});

    while(!pq.empty()){
        auto s = pq.top(); pq.pop();
        int cur = s.node;
        ll curt = s.time;
        if(vis[cur]) continue;
        vis[cur] = true;
        if(cur == n-1) break;

        for(int ei = head[cur]; ei != -1; ei = edges[ei].next){
            auto &e = edges[ei];
            ll depart = max(curt, (ll)e.depart);
            ll arrive = depart + e.dur;
            int to = e.to;
            if(arrive < dist_arr[to]){
                dist_arr[to] = arrive;
                prev_arr[to] = cur;
                pq.push({arrive, to});
            }
        }
    }

    if(dist_arr[n-1] == numeric_limits<ll>::max()) return 1;

    int psz = 0;
    for(int v = n-1; v != -1; v = prev_arr[v]) path[psz++] = v;

    write_int(dist_arr[n-1]);
    for(int i = psz-1; i >= 0; i--) write_int((ll)path[i]+1, ' ');
    putchar('\n');
    return 0;
}