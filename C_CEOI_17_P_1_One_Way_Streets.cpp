#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    if(!(cin>>n>>m)) return 0;
    vector<int> A(m+1), B(m+1);
    vector<vector<pair<int,int>>> adj(n+1);
    for(int i=1;i<=m;i++){
        int a,b; cin>>a>>b; A[i]=a; B[i]=b;
        adj[a].push_back({b,i});
        adj[b].push_back({a,i});
    }

    vector<int> tin(n+1,0), low(n+1,0), vis(n+1,0);
    vector<char> is_bridge(m+1, false);
    int timer = 1;
    function<void(int,int)> dfs1 = [&](int v, int pe){
        vis[v]=1;
        tin[v]=low[v]=timer++;
        for(auto [to, eid] : adj[v]){
            if(eid==pe) continue;
            if(vis[to]){
                low[v] = min(low[v], tin[to]);
            }else{
                dfs1(to, eid);
                low[v] = min(low[v], low[to]);

                if(low[to] > tin[v]){
                    is_bridge[eid] = true;
                }
            }
        }
    };
    for(int i=1;i<=n;i++) if(!vis[i]) dfs1(i, -1);

    vector<int> comp(n+1, 0);
    int comp_cnt = 0;
    for(int i=1;i<=n;i++){
        if(comp[i]) continue;
        ++comp_cnt;

        stack<int> st; st.push(i);
        comp[i]=comp_cnt;
        while(!st.empty()){
            int v=st.top(); st.pop();
            for(auto [to,eid] : adj[v]){
                if(comp[to]) continue;
                if(is_bridge[eid]) continue;
                comp[to]=comp_cnt;
                st.push(to);
            }
        }
    }

    vector<vector<pair<int,int>>> tree(comp_cnt+1);

    for(int i=1;i<=m;i++){
        if(!is_bridge[i]) continue;
        int u = A[i], v = B[i];
        int cu = comp[u], cv = comp[v];

        tree[cu].push_back({cv, i});
        tree[cv].push_back({cu, i});
    }

    int LOG = 1;
    while((1<<LOG) <= comp_cnt) ++LOG;
    vector<vector<int>> up(LOG, vector<int>(comp_cnt+1, 0));
    vector<int> depth(comp_cnt+1, 0);
    vector<int> parent_edge(comp_cnt+1, -1); 
    vector<int> parent_comp(comp_cnt+1, 0);

    function<void(int,int)> dfs_lca = [&](int root, int pe){

        stack<int> st; st.push(root);
        parent_comp[root]=0; parent_edge[root]=-1; depth[root]=0;
        while(!st.empty()){
            int v=st.top(); st.pop();
            for(auto [to, eid] : tree[v]){
                if(to==parent_comp[v]) continue;
                parent_comp[to]=v;
                parent_edge[to]=eid;
                depth[to]=depth[v]+1;
                st.push(to);
            }
        }
    };

    for(int c=1;c<=comp_cnt;c++){
        if(parent_comp[c]==0){ 
            parent_comp[c]=0; 
            depth[c]=0;

            stack<int> st; st.push(c);
            parent_comp[c]=0;
            parent_edge[c]=-1;
            while(!st.empty()){
                int v=st.top(); st.pop();
                for(auto [to,eid] : tree[v]){
                    if(to==parent_comp[v]) continue;
                    if(parent_comp[to]!=0 || to==c) {

                        if(to==c) continue;
                    }
                    parent_comp[to]=v;
                    parent_edge[to]=eid;
                    depth[to]=depth[v]+1;
                    st.push(to);
                }
            }
        }
    }

    for(int v=1; v<=comp_cnt; ++v) up[0][v] = parent_comp[v];
    for(int k=1;k<LOG;k++){
        for(int v=1; v<=comp_cnt; ++v){
            up[k][v] = up[k-1][ v ] ? up[k-1][ up[k-1][v] ] : 0;
        }
    }

    auto lca = [&](int a, int b){
        if(a==0 || b==0) return 0;
        if(depth[a] < depth[b]) swap(a,b);
        int diff = depth[a]-depth[b];
        for(int k=0;k<LOG;k++) if(diff & (1<<k)) a = up[k][a];
        if(a==b) return a;
        for(int k=LOG-1;k>=0;k--){
            if(up[k][a]!=up[k][b]){
                a=up[k][a];
                b=up[k][b];
            }
        }
        return up[0][a];
    };

    int p; cin>>p;
    vector<long long> need_up(comp_cnt+1, 0), need_down(comp_cnt+1, 0);
    for(int i=0;i<p;i++){
        int x,y; cin>>x>>y;
        int cx = comp[x], cy = comp[y];
        if(cx == cy) continue; 
        int L = lca(cx, cy);

        need_up[cx] += 1;
        need_up[L] -= 1;
        need_down[cy] += 1;
        need_down[L] -= 1;
    }

    vector<char> ans(m+1, 'B'); 

    vector<int> seen(comp_cnt+1, 0);
    for(int root=1; root<=comp_cnt; ++root){
        if(seen[root]) continue;

        stack<tuple<int,int,int>> st;
        st.push({root, 0, 0});
        while(!st.empty()){
            auto [v, pcomp, state] = st.top(); st.pop();
            if(state==0){
                if(seen[v]) continue;
                seen[v]=1;
                st.push({v,pcomp,1});
                for(auto [to,eid] : tree[v]){
                    if(to==pcomp) continue;
                    st.push({to, v, 0});
                }
            }else{

                for(auto [to,eid] : tree[v]){
                    if(to==pcomp) continue;
                    need_up[v] += need_up[to];
                    need_down[v] += need_down[to];

                    long long upv = need_up[to];
                    long long downv = need_down[to];
                    if(upv>0 && downv>0){

                    }
                    if(upv>0){

                        int ca = comp[A[eid]], cb = comp[B[eid]];

                        int from_comp = to, to_comp = v;
                        if(ca==from_comp && cb==to_comp) ans[eid] = 'R';
                        else ans[eid] = 'L';
                    } else if(downv>0){

                        int ca = comp[A[eid]], cb = comp[B[eid]];
                        int from_comp = v, to_comp = to;
                        if(ca==from_comp && cb==to_comp) ans[eid] = 'R';
                        else ans[eid] = 'L';
                    } else {

                        ans[eid] = 'B';
                    }
                }
            }
        }
    }

    string out;
    out.resize(m);
    for(int i=1;i<=m;i++) out[i-1] = ans[i];
    cout<<out<<"\n";
}