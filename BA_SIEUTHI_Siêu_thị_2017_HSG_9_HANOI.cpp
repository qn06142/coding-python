#include <bits/stdc++.h>

using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(0);cout.tie(0);
long long a[(int) 1e7], s = 0, k, t, n;
void input() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    s = s + a[i];
  }
  t = n % k;
}
void xuli() {
  sort(a + 1, a + 1 + n, greater < int > ());
  for (int i = k; i <= n; i = i + k) {
    s = s - a[i];
  }
  cout << s;
}
int main() {
  fast;
  input();
  xuli();
}