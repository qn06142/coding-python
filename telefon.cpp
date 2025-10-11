#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    if(!(cin >> N)) return 0;
    vector<int> a(N+1);
    for(int i=1;i<=N;i++) cin >> a[i];

    // vis[u] = id of start that visited u (0 = unvisited)
    vector<int> vis(N+1, 0);
    vector<int> reps; // one representative node from each cycle

    for(int i=1;i<=N;i++){
        if(vis[i]) continue;
        int u = i;
        while(!vis[u]){
            vis[u] = i;      // mark with current traversal id
            u = a[u];
        }
        // if we met a node visited in the same traversal -> found a new cycle
        if(vis[u] == i){
            // take u as representative of this cycle
            reps.push_back(u);
        }
    }

    int k = (int)reps.size();
    if(k <= 1){
        cout << 0 << '\n';
        return 0;
    }

    cout << k << '\n';
    // connect reps[i] -> reps[(i+1)%k]
    for(int i=0;i<k;i++){
        int from = reps[i];
        int to = reps[(i+1)%k];
        cout << from << ' ' << to << '\n';
    }
    return 0;
}
