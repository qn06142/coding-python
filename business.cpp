#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 105;

string s;

int dp[MAXN][2][MAXN], k;

int DP(int i, bool flag, int cnt)
{
    if (i == s.size())
    {
        if (cnt == k)
            return 1;
        else
            return 0;
    }
    int res = dp[i][flag][cnt];
    if (res != -1)
    {
        return res;
    }
    res = 0;
    int lim;
    if (flag == 0)
    {
        lim = s[i] - '0';
    } else
    {
        lim = 9;
    }
    for (int d = 0; d <= lim; d++)
    {
        int newflag = flag | (d < s[i] - '0');
        int newcnt = cnt + (d != 0);
        res += DP(i + 1, newflag, newcnt);
    }
    dp[i][flag][cnt] = res;
    return res;
}

signed main()
{
    cin >> s >> k;
    int ans = 0;
    memset(dp, -1, sizeof(dp));
    ans += DP(0, 0, 0);
    cout << ans;
}
