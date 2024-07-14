#include <iostream>
using namespace std;
int main()
{
    int n,q;
    cin >> n >> q;
    int a[n+1];
    int pref[n+1];
    pref[0] = 0;
    for (int i = 1;i <=n;i++)
    {
        cin >> a[i];
        pref[i] = max(pref[i-1],pref[i-1] + a[i]);
    }
    while (q--)
    {
          int l,r;
          cin >> l >> r;
          cout << pref[r] - pref[l-1] << '\n';
    }
return 0;
}