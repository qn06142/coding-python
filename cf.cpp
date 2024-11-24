#include <bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define int long long
using namespace std;
const int maxN = 5e5 + 5;
const pii mod = {1e9+7,2e9+7};
const pii base = {27,27};

int n;
int a[maxN];
int p[maxN];
int b[maxN];
map<int,int> pos;
int del[maxN];

void Solve()
{
    cin >> n;
    pos.clear();
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        b[i] = a[i];
        del[i] = 0;
    }
    sort(b + 1,b + n + 1);
    for(int i = 1; i <= n; i++)
    {
        pos[b[i]] = i;
    }
    for(int i = 1; i <= n; i++)
    {
        cin >> p[i];
    }

    int res = 0;
    int pt = n;
    int pick = 0;

    for(int i = 1; i <= n; i++)
    {
        if(b[pt] * i > res)
        {
            res = b[pt] * i;
            pick = i;
            //cout << res;return;
        }

        int j = pos[a[p[i]]];
        del[j] = 1;
        pos[b[j]]--;

        if(j >= pt)
        {
            pt--;
            while(pt >= 1 && del[pt]) pt--;
        }
        pt--;
        while(pt >= 1 && del[pt]) pt--;
        if(pt <= 0) break;
    }
    cout << res <<' '<< pick <<'\n';
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int test;
    //test = 1;
    cin >> test;
    while(test--)
    {
        Solve();
    }
}
