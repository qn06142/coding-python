#include<bits/stdc++.h>

#define FOR(i, a, b) for(int i = (a); i <= (b); i++)

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int mod = 1e9 + 7;
const int N = 1e6 + 7;

void add(int& x, int y) {
    if ((x+=y) >= mod) x-=mod;
}

int n, dp[N][2];

string s;

int sum[26][2];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>s;
    n = s.size();
    s = " " + s;
    int res = 0;
    FOR(i, 1, n) {
        dp[i][0] = 1; 

        for (int x = 0; x < 26; x++) {
            int c = s[i] - 'A';
            if (c > x) add(dp[i][1], sum[x][0]); else
            if (c < x) add(dp[i][0], sum[x][1]);
        }

        add(res, dp[i][0]);
        add(res, dp[i][1]);
        add(sum[s[i] - 'A'][0], dp[i][0]);
        add(sum[s[i] - 'A'][1], dp[i][1]);

    }
    cout<<res;
    return 0;
}