#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e18;

struct Group {
    ll d;      
    bool left; 
    bool right;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<ll,int>> pts;
    pts.reserve(n);
    for (int i = 0; i < n; i++){
        ll x;
        cin >> x;
        ll d = llabs(x);
        int sign = (x > 0) ? 1 : -1; 
        pts.push_back({d, sign});
    }

    sort(pts.begin(), pts.end(), [](auto a, auto b){
        if(a.first == b.first)
            return a.second < b.second;
        return a.first < b.first;
    });

    vector<Group> groups;
    for(auto &p : pts){
        ll d = p.first;
        int s = p.second;
        if(groups.empty() || groups.back().d != d){
            Group g;
            g.d = d;
            g.left = false;
            g.right = false;
            groups.push_back(g);
        }
        if(s == 1)
            groups.back().right = true;
        else
            groups.back().left = true;
    }

    int m = groups.size();

    vector<array<ll,2>> dp(m, {INF, INF});

    ll d0 = groups[0].d;
    if(groups[0].left && groups[0].right){
        dp[0][0] = dp[0][1] = 3 * d0; 
    } else if(groups[0].right){
        dp[0][1] = d0; 
        dp[0][0] = INF;
    } else if(groups[0].left){
        dp[0][0] = d0; 
        dp[0][1] = INF;
    }

    for (int i = 1; i < m; i++){
        ll d_i = groups[i].d;
        ll d_prev = groups[i-1].d;
        if(groups[i].left && groups[i].right){

            dp[i][1] = min(dp[i-1][0] + (3*d_i - d_prev),
                           dp[i-1][1] + (3*d_i + d_prev));

            dp[i][0] = min(dp[i-1][0] + (3*d_i + d_prev),
                           dp[i-1][1] + (3*d_i - d_prev));
        }
        else if(groups[i].right){

            dp[i][1] = min(dp[i-1][0] + (d_i + d_prev),
                           dp[i-1][1] + (d_i - d_prev));
            dp[i][0] = INF;
        }
        else if(groups[i].left){

            dp[i][0] = min(dp[i-1][0] + (d_i - d_prev),
                           dp[i-1][1] + (d_i + d_prev));
            dp[i][1] = INF;
        }
    }

    ll ans = min(dp[m-1][0], dp[m-1][1]);
    cout << ans << "\n";

    return 0;
}
