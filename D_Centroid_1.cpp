#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;

int n, K;
vector<int> g[MAXN];
bool removed[MAXN];
int sub_size[MAXN];
long long answer = 0;

void dfs_size(int u, int p) {
    sub_size[u] = 1;
    for (int v : g[u]) {
        if (v == p || removed[v]) continue;
        dfs_size(v, u);
        sub_size[u] += sub_size[v];
    }
}

int find_centroid(int u, int p, int comp_size) {
    for (int v : g[u]) {
        if (v == p || removed[v]) continue;
        if (sub_size[v] > comp_size / 2)
            return find_centroid(v, u, comp_size);
    }
    return u;
}

void dfs_depth(int u, int p, int d, vector<int> &depths) {
    if (d > K) return; 
    depths.push_back(d);
    for (int v : g[u]) {
        if (v == p || removed[v]) continue;
        dfs_depth(v, u, d + 1, depths);
    }
}

void decompose(int entry) {

    dfs_size(entry, -1);
    int c = find_centroid(entry, -1, sub_size[entry]);

    removed[c] = true;

    map<int,int> cnt; 
    cnt[0] = 1; 

    for (int v : g[c]) {
        if (removed[v]) continue;
        vector<int> depths;
        dfs_depth(v, c, 1, depths);

        for (int d : depths) {
            if (d <= K) {
                if (cnt.count(K - d))
                    answer += cnt[K - d];
            }
        }

        for (int d : depths) {
            if (d <= K) cnt[d]++;
        }
    }

    for (int v : g[c]) {
        if (!removed[v]) decompose(v);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> K;
    for (int i = 0; i < n-1; i++) {
        int a,b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    decompose(1);

    cout << answer << "\n";
}