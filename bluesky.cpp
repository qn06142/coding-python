#include<bits/stdc++.h>
#define ii pair<int, int>
#define ll pair<long long, long long>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int mod[2] = {1000000007, 998244353};
const int N = 3e5 + 1;
const string NAME = "";
int n, k, a[N], m, L[N], R[N];
bool merged[N];
long long b[N];

void inp(){
    cin >> n >> k;

    for(int i = 1; i <= n; ++i)
        cin >> a[i];
}

void solve(){
    int sig = 0;

    for(int i = 1; i <= n; ++i){
        if(!sig){
            sig = (a[i] >= 0 ? 1 : -1);
            b[++m] += 1LL * a[i];
        }
        else if(sig == 1){
            if(a[i] >= 0)
                b[m] += 1LL * a[i];
            else{
                sig = -1;
                b[++m] += 1LL * a[i];
            }
        }
        else{
            if(a[i] < 0)
                b[m] += 1LL * a[i];
            else{
                sig = 1;
                b[++m] += 1LL * a[i];
            }
        }
    }

    int cnt = 0;
    long long ans = 0;
    priority_queue<pair<long long, int>> pq;

    for(int i = 1; i <= m; ++i){
        L[i] = i - 1, R[i] = i + 1;
        pq.push({-abs(b[i]), i});

        if(b[i] >= 0)
            ++cnt, ans += b[i];
    }

    R[m] = 0;

    while(cnt > k){
        auto [tot, u] = pq.top();
        pq.pop();

        if(merged[u])
            continue;

        if(b[u] >= 0 || (L[u] && R[u])){
            int px = L[u], nx = R[u];
            merged[px] = merged[nx] = true;

            --cnt, ans += tot;
            b[u] += b[px] + b[nx];
            pq.push({-abs(b[u]), u});

            L[u] = L[px];
            if(L[u])
                R[L[u]] = u;

            R[u] = R[nx];
            if(R[u])
                L[R[u]] = u;
        }
    }

    cout << ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if(fopen((NAME + ".inp").c_str(), "r")){
        freopen((NAME + ".inp").c_str(), "r", stdin);
        freopen((NAME + ".out").c_str(), "w", stdout);
    }

    inp();
    solve();
}
