#include<bits/stdc++.h>
#define ll long long
#define ios ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#pragma GCC optimize("O3","unroll-loops")
#pragma GCC optimize("Ofast")
using namespace std;
const int N=3e4;
int a[N],b[N],n,m;
int main() {
    ios
    int n;
    cin >> n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=n;i>0;i--)
    {
        int k=upper_bound(b+1,b+1+m,a[i])-b;
        m=max(m,k);
        b[k]=a[i];
    }
    cout<<n-m;
    return 0;
}