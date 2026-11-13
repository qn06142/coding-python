#include<bits/stdc++.h>
using namespace std;
int par[200005],tin[200005],low[200005],timer,scc,n,m;
vector<int> adj[200005];
int child[200005];
long long aHn;
bool vis[200005];
int findp(int u)
{
    if(par[u]<0) return u;
    return par[u]=findp(par[u]);
}
void merg(int u, int v)
{
    u=findp(u);
    v=findp(v);
    if(par[u]>par[v]) swap(u,v);
    par[u]+=par[v];
    par[v]=u;
}
void dfs(int u, int p)
{
    tin[u]=low[u]=++timer;
    int cnt=0;
    for(int v: adj[u])
    {
        if(v==p) continue;
        if(tin[v])
        {
            low[u]=min(low[u],tin[v]);
        }
        else
        {
            dfs(v,u);
            low[u]=min(low[u],low[v]);
            if(low[v]>tin[u]) merg(u,v);
        }
    }

}
void dfs2(int u)
{
    vis[u]=1;
    child[u]=0;
    for(int v: adj[u])
    {
        if(!vis[v] and findp(v)==findp(u))
        {
            dfs2(v);
            child[u]+=child[v];
        }
    }
    if(child[u]>0) aHn+=child[u]-1;
   // cerr << u << ' ' << child[u] << " a\n";
    child[u]++;
}

void solve()
{
    cin >> n >> m;
    fill(par+1,par+n+1,-1);
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,0);
   for(int i=1;i<=n;i++)
   {

       if(!vis[i])
       {
           dfs2(i);
       }
   }
   cout << aHn;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int test=1;

  //  cin >> test;
    while(test--)
    {
        solve();
    }

}