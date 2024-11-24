#include <iostream>

using namespace std;
long long a, b, c, d, ans;
int main() {
  cin >> a >> b >> c;
  ans += c + min(a, b);
  if (a > min(a, b)) ans += (a - min(a, b)) / 3;
  cout << ans;
}