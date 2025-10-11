
#pragma GCC optimize("trapv")
#include<bits/stdc++.h>
using namespace std;
long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
const int maxn = 1e5 + 5;
int a[maxn];
int main(){
  int ans = 0;
  int n;
  cin>>n;
  memset(a, 0, sizeof a);
  for(int i=1;i<=n;i++){
    int k=1;
    if (a[i]==0){
      while (binpow(10, k, LLONG_MAX) /i>n){
        if (binpow(10,k, i)==0){
          int l=binpow(10,k, LLONG_MAX)/i;
          if (a[l]==0){
            ans+=k;
            a[l]=1;
            a[i]=1;
            break;
          }
        }
        k+=1;
      }
    }
  }
  cout<<ans;
}