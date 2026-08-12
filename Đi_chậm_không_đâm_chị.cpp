#include<bits/stdc++.h>
using namespace std;

char s[25], pre[25], pal[25];

long long pow10(int p) {
    long long res = 1;
    while (p--) res *= 10;
    return res;
}

long long f(long long n) {
    if (n < 0) return 0;
    if (n == 0) return 1;

    sprintf(s, "%lld", n);
    int len = strlen(s);

    long long ans = 1;
    for (int l = 1; l < len; l++) {
        int half = (l + 1) / 2;
        ans += 9LL * pow10(half - 1);
    }

    int half = (len + 1) / 2;

    memcpy(pre, s, half);
    pre[half] = '\0';

    ans += atoll(pre) - pow10(half - 1);

    int p = 0;
    for (int i = 0; i < half; i++)
        pal[p++] = pre[i];
    for (int i = len - half - 1; i >= 0; i--)
        pal[p++] = pre[i];
    pal[p] = '\0';

    if (strcmp(pal, s) <= 0)
        ans++;

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        long long l, r;
        cin >> l >> r;
        if (l > r) swap(l, r);

        cout << "Case " << i << ": " << f(r) - f(l - 1) << '\n';
    }
}