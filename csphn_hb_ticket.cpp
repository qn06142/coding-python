#include<bits/stdc++.h>
#define ll int
using namespace std;
ll n, a, b;
int main (){
 cin >> n;
 if(n % 100 > 18 || n / 100 > 18) {
  cout << 0;
  return 0;
 }
 a = n % 100;
 if(a > 9)
 a = (a - 9) * 10 + 9;
 else a = 10 + (a - 1);
 n = n / 100;
 if(n > 9)
 n = (n - 9) * 10 + 9;
 else n = 10 + (n - 1);
 cout << min(a,n) << max(a,n);
 return 0;
}