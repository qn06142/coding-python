#include <bits/stdc++.h>
using namespace std;
int n,q,m;
vector<pair<int, int> > adj[300005];
vector<int> ed[300005];

int vis[300005];
map<pair<int, int>, bool> mp;
//int tin[300005],tout[300005],timer,low[300005];
int k;
int dist[300005],par[300005],up[300005][20],pu[300005][20],pa[300005],he[300005];
struct lbh
{
    int u,v,w;

    bool operator<(const lbh& o) const
    {
        return w<o.w;
    }
};
lbh ahn[300005];
priority_queue<lbh> pq;
int findp(int u)
{
    if(u==pa[u]) return u;
    int v=findp(pa[u]);
    return pa[u]=v;
}
bool merg(int u, int v,int w)
{
    int a=findp(u),b=findp(v);
    if(a==b) return false;
    pa[a]=b;
    adj[u].push_back({v,w});
    adj[v].push_back({u,w});
    return true;
}
void prep(int u, int p)
{
    vis[u]=1;
    for(pair<int, int> i: adj[u])
    {
        if(i.first==p) continue;
        dist[i.first]=dist[u]+i.second;
        he[i.first]=he[u]+1;
        par[i.first]=u;
        prep(i.first,u);
    }
}
void preprocess()
{
    for (int u = 1; u <= n; ++u)
    {
        up[u][0] = par[u];
    }
    for(int i=1; i<=n; i++)
    {
        for(pair<int,int> j: adj[i])
        {
            if(j.first==par[i])
            {
                pu[i][0]=j.second;
            }
        }
    }
    for (int j = 1; j < 17; ++j)
        for (int u = 1; u <= n; ++u)
        {
            up[u][j] = up[up[u][j - 1]][j - 1];
            pu[u][j] = __gcd(pu[u][j-1],pu[up[u][j-1]][j-1]);
        }
}
int lca(int u, int v)
{
    if (he[u] != he[v])
    {
        if (he[u] < he[v]) swap(u, v);


        int k = he[u] - he[v];
        for (int j = 0; (1 << j) <= k; ++j)
            if (k >> j & 1)u = up[u][j];
    }
    if (u == v) return u;


    int k = __lg(he[u]);
    for (int j = k; j >= 0; --j)
        if (up[u][j] != up[v][j])
            u = up[u][j], v = up[v][j];
    return up[u][0];
}
int getd(int u, int v)
{
    int k=lca(u,v);
 //   cout << "getd: " << u << ' ' << v << "\n";
 //   cout << "lca: " << k << "\n";
    int x=he[u]-he[k],y=0,cnt=0,ans;
    while(x>0)
    {
        if(x&1)
        {
            if(y==0) y=pu[u][cnt];
            else y=__gcd(y,pu[u][cnt]);
            u=up[u][cnt];
        }
        cnt++;
        x/=2;
    }
    ans=y;
   // cout << y << ' ';
    x=he[v]-he[k];
    cnt=0;
    y=0;
    while(x>0)
    {
        if(x&1)
        {
            if(y==0) y=pu[v][cnt];
            else y=__gcd(y,pu[v][cnt]);
            v=up[v][cnt];
        }
        cnt++;
        x/=2;
    }
  //  cout << y << "\n";
    ans=__gcd(ans,y);
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=1;i<n;i++)
    {
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    fill(vis+1,vis+n+1,0);
    for(int i=1;i<=n;i++)
    {
        if(vis[i]==0)
        {
            prep(i,0);
        }
    }
    preprocess();
    while(m--)
    {
        int u,v;
        cin >> u >> v;
        cout << getd(u,v) << "\n";
    }
}