#include <stdio.h>
#include <string.h>

typedef long long ll;

char s[25];
int len, m;

ll memo[25][110][2];

ll dp(int pos, int mod, int tight) {

    if (pos == len) {
        return (mod % m == 0) ? 1 : 0;
    }

    if (memo[pos][mod][tight] != -1)
        return memo[pos][mod][tight];

    ll res = 0;

    int limit = (tight) ? (s[pos] - '0') : 9;

    for (int d = 0; d <= limit; d++) {
        int newtight = (tight && (d == limit));
        int newmod = (mod + d) % m;
        res += dp(pos + 1, newmod, newtight);
    }

    memo[pos][mod][tight] = res;
    return res;
}

int main() {
    unsigned long long n;

    scanf("%llu %d", &n, &m);

    sprintf(s, "%llu", n);
    len = 0;
    while (s[len] != '\0') len++;

    memset(memo, -1, sizeof(memo));

    ll result = dp(0, 0, 1) - 1;

    printf("%lld\n", result);

    return 0;
}