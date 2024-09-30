#include<bits/stdc++.h>
#define pb push_back
#define MOD 1000000007
#define NMAX 200001
#define nl '\n'
#define pii1 pair<int, pair<int,int>>  (1,(1,2));
#define pii pair<int,int>
#define tpl tuple<int,int,int>
#define int long long
using namespace std;
ifstream fin("data.in");
ofstream fout("data.out");
const int INF=1e12;

int n,q,s,t;
vector<int>v;
int ans;
vector<int>dif;
int calc(int val)
{
    if(val>0)
        return -val*s;
    else
        return -val*t;
}
signed main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cin>>n>>q>>s>>t;
    v.resize(n+1);
    dif.resize(n+1);
    for(int i=0;i<=n;++i)
    {
        cin>>v[i];
    }
    for(int i=1;i<=n;++i)
    {
        dif[i]=v[i]-v[i-1];
        ans+=calc(dif[i]);
    }
    for(int i=1;i<=q;++i)
    {
        int st,dr,x;
        cin>>st>>dr>>x;
        ans-=calc(dif[st]);
        dif[st]+=x;
        ans+=calc(dif[st]);
        if(dr!=n)
        {
            ans-=calc(dif[dr+1]);
            dif[dr+1]-=x;
            ans+=calc(dif[dr+1]);
        }
        cout<<ans<<nl;
 
    }
 
 
 
    return 0;
}