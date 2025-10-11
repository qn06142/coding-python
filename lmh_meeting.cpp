#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    long long m;
    if(!(cin >> n >> m)) return 0;
    vector<vector<int>> g(n+1);
    for(long long i=0;i<m;i++){
        int u,v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    // 1) BFS each component and bipartite color (0/1). Collect nodes per color.
    vector<int> color(n+1, -1);
    vector<pair<vector<int>, vector<int>>> comps; // (nodes color0, nodes color1)
    for(int v=1; v<=n; ++v){
        if(color[v] != -1) continue;
        queue<int> q;
        q.push(v);
        color[v] = 0;
        vector<int> a, b;
        a.push_back(v);
        while(!q.empty()){
            int x = q.front(); q.pop();
            for(int y: g[x]){
                if(color[y] == -1){
                    color[y] = color[x]^1;
                    if(color[y]==0) a.push_back(y); else b.push_back(y);
                    q.push(y);
                } else {
                    if(color[y] == color[x]){
                        // impossible per statement, but safety:
                        cout << "-1\n";
                        return 0;
                    }
                }
            }
        }
        comps.emplace_back(a,b);
    }

    int k = (int)comps.size();
    // bitset representation: bits 0..n (inclusive) packed into ull blocks
    int W = (n + 64) / 64;
    auto make_zero = [&](void){ return vector<ull>(W, 0ULL); };
    vector<ull> dp = make_zero(); // reachable sums after processed components so far
    dp[0] = 1ULL; // sum 0 reachable

    vector<int> prev_sum(n+1, -1); // prev sum to backtrack
    vector<int> last_comp(n+1, -1); // which component produced this sum first time
    vector<char> last_choice(n+1, -1); // 0 -> used nodes0 into room1, 1 -> used nodes1 into room1
    prev_sum[0] = -2; // sentinel for start

    // have: which sums already assigned prev (so we don't reassign)
    vector<ull> have = make_zero();
    have[0] = 1ULL;

    auto shift_left = [&](const vector<ull>& A, int s)->vector<ull>{
        if(s == 0) return A;
        int word = s / 64;
        int off = s % 64;
        vector<ull> B(W, 0ULL);
        for(int i = W-1; i >= 0; --i){
            ull v = 0ULL;
            int src = i - word;
            if(src >= 0){
                v = A[src] << off;
                if(off && src-1 >= 0) v |= (A[src-1] >> (64 - off));
            }
            B[i] = v;
        }
        // mask bits beyond n
        int lastword = n / 64;
        int lastbits = n % 64 + 1;
        if(lastbits < 64){
            ull mask = (lastbits==64) ? ~0ULL : ((1ULL << lastbits) - 1ULL);
            B[lastword] &= mask;
            for(int i = lastword+1; i < W; ++i) B[i] = 0ULL;
        }
        return B;
    };

    for(int idx = 0; idx < k; ++idx){
        int s0 = (int)comps[idx].first.size();
        int s1 = (int)comps[idx].second.size();
        vector<ull> sh0 = shift_left(dp, s0);
        vector<ull> sh1 = shift_left(dp, s1);
        // new dp = sh0 | sh1  (we must use this component)
        vector<ull> ndp(W);
        for(int i=0;i<W;i++) ndp[i] = sh0[i] | sh1[i];

        // newly sums that have not been assigned prev yet:
        // newly = ndp & ~have
        for(int i=0;i<W;i++){
            ull newly = ndp[i] & ~have[i];
            while(newly){
                ull lsb = newly & -newly;
                int bit = __builtin_ctzll(newly); // position inside this word
                int pos = i*64 + bit;
                if(pos <= n && prev_sum[pos] == -1){
                    // decide from which shift it came (prefer sh0 if both)
                    bool from0 = false;
                    if( ((sh0[i] >> bit) & 1ULL) ) from0 = true;
                    int chosen = from0 ? 0 : 1;
                    int chosen_size = chosen==0 ? s0 : s1;
                    prev_sum[pos] = pos - chosen_size;
                    last_comp[pos] = idx;
                    last_choice[pos] = (char)chosen;
                }
                newly &= newly - 1ULL; // clear lsb
            }
        }
        // update have and dp for next iter
        for(int i=0;i<W;i++){
            have[i] |= ndp[i];
            dp[i] = ndp[i];
        }
    }

    // pick target t such that dp[t] true and |n-2t| minimal
    int best = -1;
    for(int t = 0; t <= n; ++t){
        int word = t/64, bit = t%64;
        if( (dp[word] >> bit) & 1ULL ){
            if(best == -1) best = t;
            else {
                if( abs(n - 2*t) < abs(n - 2*best) ) best = t;
            }
        }
    }
    if(best == -1){
        // should not happen per statement
        cout << "-1\n";
        return 0;
    }

    // backtrack to determine for each component which choice
    vector<char> chosen_for_comp(k, -1);
    int cur = best;
    while(cur != 0){
        int comp = last_comp[cur];
        int ch = last_choice[cur];
        chosen_for_comp[comp] = (char)ch;
        cur = prev_sum[cur];
    }
    // Sanity: for any comp not assigned (shouldn't happen), assign arbitrary (not likely)
    for(int i=0;i<k;i++) if(chosen_for_comp[i] == -1) chosen_for_comp[i] = 0;

    // build answer lists
    vector<int> room1, room2;
    for(int i=0;i<k;i++){
        if(chosen_for_comp[i] == 0){
            // nodes0 -> room1, nodes1 -> room2
            for(int x: comps[i].first) room1.push_back(x);
            for(int x: comps[i].second) room2.push_back(x);
        } else {
            for(int x: comps[i].second) room1.push_back(x);
            for(int x: comps[i].first) room2.push_back(x);
        }
    }

    cout << room1.size() << " " << room2.size() << "\n";
    for(size_t i=0;i<room1.size();++i){
        if(i) cout << ' ';
        cout << room1[i];
    }
    cout << "\n";
    for(size_t i=0;i<room2.size();++i){
        if(i) cout << ' ';
        cout << room2[i];
    }
    cout << "\n";
    return 0;
}
