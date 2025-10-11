#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
const int INF = 1e9;

struct FenwickMax {
    int n;
    vector<int> bit;
    FenwickMax(int n=0): n(n), bit(n+1, 0) {}
    void update(int idx, int val){
        for(; idx <= n; idx += idx & -idx) bit[idx] = max(bit[idx], val);
    }
    int query(int idx){
        int res = 0;
        for(; idx > 0; idx -= idx & -idx) res = max(res, bit[idx]);
        return res;
    }
};

struct FenwickMin {
    int n;
    vector<int> bit;
    FenwickMin(int n=0): n(n), bit(n+1, INF) {}
    void update(int idx, int val){
        for(; idx <= n; idx += idx & -idx) if(val < bit[idx]) bit[idx] = val;
    }
    int query(int idx){
        int res = INF;
        for(; idx > 0; idx -= idx & -idx) if(bit[idx] < res) res = bit[idx];
        return res;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        int N = n * m;
        vector<pii> pos(N);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                int x; cin >> x;
                pos[x] = {i, j};
            }
        }

        FenwickMax bitmax(n);
        FenwickMin bitmin(n); 

        int ans_candidate = N; 
        for(int b = 0; b < N; ++b){
            int r = pos[b].first;
            int c = pos[b].second;

            if(r > 1){
                int mx = bitmax.query(r-1);
                if(mx > c){
                    ans_candidate = b;
                    break;
                }
            }

            if(r < n){
                int rev_limit = n - r; 
                if(rev_limit >= 1){
                    int mn = bitmin.query(rev_limit);
                    if(mn < c){
                        ans_candidate = b;
                        break;
                    }
                }
            }

            bitmax.update(r, c);
            int rev_index = n - r + 1;
            bitmin.update(rev_index, c);
        }

        int final_ans = min(ans_candidate, n + m - 1);
        cout << final_ans << '\n';
    }
    return 0;
}