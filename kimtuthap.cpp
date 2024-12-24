#include <bits/stdc++.h>
#define int long long
#define ii pair<int, int>
#define st first
#define nd second
#define endl "\n"
#define db long double
#define all(v) v.begin(), v.end()
#define Unique(v) v.erase(unique(all(v)), v.end())

using namespace std;

const int MAXN = 2505;

int n, m;
int a[MAXN][MAXN];
int h[MAXN];
int pre[MAXN][MAXN];
int dpL[MAXN], dpR[MAXN];
int l[MAXN], r[MAXN], S[MAXN];

int sum (int u, int v, int x, int y){
 return pre[x][y] - pre[u - 1][y] - pre[x][v - 1] + pre[u - 1][v - 1];
} 

void PROGRAM(){
 cin >> n >> m;
 
 for (int i = 1; i <= n; i++){
  for (int j = 1; j <= m; j++){
   cin >> a[i][j];
   
   int v = a[i][j];
   pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + v;
  }
 }
 int res = 0;
 
 for (int i = 1; i <= n; i++){
  for (int j = 1; j <= m; j++){
   if (a[i][j] == 0) h[j] = 0, S[j] = 0;
   else h[j]++, S[j] += a[i][j];
   dpL[j] = 0, dpR[j] = 0;
  }
  
  stack<int> L, R;
  
  for (int j = 1; j <= m; j++){
   while (L.size() && h[L.top()] >= h[j]) L.pop();
   l[j] = L.size() ? L.top() : 0;
   L.push(j);
  }
  
  for (int j = m; j >= 1; j--){
   while (R.size() && h[R.top()] >= h[j]) R.pop();
   r[j] = R.size() ? R.top() : m + 1;
   R.push(j);
  }
  
  for (int j = 1; j <= m; j++){

   if (h[j] == 0) continue;
   
   dpL[j] = dpL[l[j]] + sum(i - h[j] + 1, l[j] + 1, i, j);

  }
  
  for (int j = m; j >= 1; j--){
   if (h[j] == 0) continue;
   dpR[j] = dpR[r[j]] + sum(i - h[j] + 1, j, i, r[j] - 1);
   res = max(res, dpL[j] + dpR[j] - S[j]);
   
  }
  
  
  
 }
 
 cout << res << endl;
}

signed main(){
 #define TASK "kimtuthap"
 if (fopen(TASK".inp", "r")){
  freopen(TASK".inp", "r", stdin);
  freopen(TASK".out", "w", stdout); 
 }
 
 
 ios_base::sync_with_stdio(false);
 cin.tie(0);
 
 
 int test = 1;
 
 while (test--) PROGRAM();
}