#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

/*** Input Output ***/
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdb pair<db, db>
#define vi vector<int>
#define vpdb vector<pdb>
#define vl vector<ll>
#define vdb vector<db>
#define vb vector<bool>
#define vs vector<str>
#define vpii vector<pii>
#define vpll vector<pll>
#define vpd vector<pd>
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

#define ll long long
#define ull unsigned long long
#define str string
#define db double

/*** Define Values ***/
//#define mx 200005
// #define mod 111539786
#define PI acos(-1.0)
#define eps 1e-7
#define size1 15

#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define mem(name, value) memset(name, value, sizeof(name))

/*** Sorts ***/
#define all(v) (v).begin(), (v).end()
#define rev(v) reverse(all(v))
#define srt(v) sort(all(v))
#define srtGreat(v) sort(all(v), greater<ll>())

/*** Some Prints ***/
#define en cout << '\n';
#define no cout << "NO\n"
#define yes cout << "YES\n"
#define case cout << "Case " << t++ << ": "
#define whi while (ii<=n)

//loops
#define FOR(i, a, b) for(int i=(int)a;i<=(int)b;++i)
#define ROF(i, a, b) for(int i=(int)a;i>=(int)b;i--)
#define rep(a, x) for(auto& a : x)
#define MASK(x) (1ll<<(x))
#define SQR(x) (x*x)
#define ordered_set tree<ll, null_type,less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update>
const ll MOD = 1e9+7;
const ll MAXN = 1e6+100;
const ll MAX = 2e5+100;
const ll LOG = 31;
const ll INF = 1e18;
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
using namespace std;
using namespace __gnu_pbds;
ll n,m,a[MAX],b[MAX],max1,s=0,ans=-1;
bool check(ll g){
    s=0;
    FOR(i,2,n-1)
      if (a[i]>=g) s+=b[i];
        else if (a[i]+b[i]>=g) s+=a[i]+b[i]-g;
    return s>=m;
}
void solve() {  
    cin>>n>>m;
    FOR(i,1,n) cin>>a[i];
    b[1]=0;
    max1=a[1];
    FOR(i,2,n)
      if (a[i]>max1){
        b[i]=0;
        max1=a[i];
      } else b[i]=max1-a[i];
    b[n]=0;
    max1=a[n];
    ROF(i,n-1,1)
      if (a[i]>max1){
        b[i]=0;
        max1=a[i];
      } else {
        b[i]=min(max1-a[i],b[i]);
      }
    ll l=0,r=3e9,mid;
    while(l<=r){
        mid=(l+r)/2;
        if (check(mid)){
            ans=mid;
            l=mid+1;
        } else r=mid-1;
    }
    cout<<ans<<"\n";
}  
int main(){
  IOS;
  int t=1;
  // cin>>t;
  while(t--)
    solve();
}