#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<long long>> adds(n+2), removes(n+2);

    for(int i = 0; i < m; i++){
        long long l, r, x;
        cin >> l >> r >> x;
        long long C = x - l;            
        adds[l].push_back(C);
        removes[r+1].push_back(C);
    }

    multiset<long long> active;
    vector<long long> ans(n+1, 0);

    for(int j = 1; j <= n; j++){

        for(auto C : adds[j])
            active.insert(C);

        for(auto C : removes[j]){
            auto it = active.find(C);
            if (it != active.end())
                active.erase(it);
        }

        if (!active.empty())
            ans[j] = j + *prev(active.end());

    }

    for(int j = 1; j <= n; j++){
        cout << ans[j] << (j == n ? '\n' : ' ');
    }
}