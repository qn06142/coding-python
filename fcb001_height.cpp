#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll n, a[100001], b[100001];
int main()
{
    cin >> n;
    for (ll i = 1; i <= n; i++)
    {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(a + 1, a + n + 1);
    for (ll i = 1; i <= n; i++)
    {
        ll it = lower_bound(a + 1, a + n + 1, b[i]) - a - 1;
        cout << it << " ";
    }
}