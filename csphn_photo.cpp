#include <bits/stdc++.h>
#define nmax 100007

using namespace std;

long long n,p[nmax][10],a[nmax];

bool cmp(long x, long y)
{
    long long dem=0;
    for (long i=1; i<=5; i++)
    {
        if (p[x][i]<p[y][i]) dem++;
        if (dem>=3) return true;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (long i=1; i<=5; i++)
     for (long j=1; j<=n; j++)
      {
         long u; cin >> u;
         p[u][i]=j;
      }
    for (long i=1; i<=n; i++) a[i]=i;
    sort(a+1,a+n+1,cmp);
    for (long i=1; i<=n; i++) cout << a[i] << " ";
}