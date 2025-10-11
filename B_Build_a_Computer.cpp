#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long L, R;
    if(!(cin >> L >> R)) return 0;

    vector<pair<long long,int>> blocks;
    long long cur = L;
    while(cur <= R){
        int maxAlign = 0;
        long long tmp = cur;
        while(tmp % 2 == 0 && tmp > 0){ maxAlign++; tmp >>= 1; }
        int maxLen = 0;
        long long len = R - cur + 1;
        while((1LL << (maxLen+1)) <= len) maxLen++;
        int k = min(maxAlign, maxLen);
        blocks.push_back({cur, k});
        cur += (1LL << k);
    }

    int M = 0;
    long long tmpR = R;
    while(tmpR > 0){ M++; tmpR >>= 1; }
    if(M == 0) M = 1;

    int start = 1;
    int chain_begin = 2;
    int terminal = chain_begin + M; 
    int next_id = terminal + 1;

    unordered_map<int, vector<pair<int,int>>> edges;

    for(int i = chain_begin; i < terminal; ++i){
        edges[i].push_back({i+1, 0});
        edges[i].push_back({i+1, 1});
    }

    unordered_map<long long,int> trans;
    auto make_key = [&](int node, int bit)->long long{
        return ( (long long)node << 2 ) | (bit & 3);
    };

    for(auto &bk : blocks){
        long long a = bk.first;
        int k = bk.second;
        long long prefix_val = a >> k;
        vector<int> bits;
        long long t = prefix_val;
        while(t > 0){
            bits.push_back(t & 1);
            t >>= 1;
        }
        reverse(bits.begin(), bits.end());
        int p = chain_begin + (M - k);
        int cur_node = start;

        if(bits.empty()){

            edges[cur_node].push_back({p, 0});
        } else {
            for(size_t i=0;i<bits.size();++i){
                int b = bits[i];
                if(i+1 == bits.size()){

                    edges[cur_node].push_back({p, b});
                } else {
                    long long key = make_key(cur_node, b);
                    if(trans.count(key)){
                        cur_node = trans[key];
                    } else {
                        int nid = next_id++;
                        trans[key] = nid;
                        edges[cur_node].push_back({nid, b});
                        cur_node = nid;
                    }
                }
            }
        }
    }

    int n = max(next_id-1, terminal);

    vector<vector<pair<int,int>>> adj(n+1);
    for(int i=1;i<=n;i++){
        if(edges.count(i)){
            for(auto &pr : edges[i]) adj[i].push_back(pr);
        }
    }

    cout << n << "\n";
    for(int i=1;i<=n;i++){
        cout << adj[i].size();
        for(auto &pr : adj[i]){
            cout << " " << pr.first << " " << pr.second;
        }
        cout << "\n";
    }
    return 0;
}