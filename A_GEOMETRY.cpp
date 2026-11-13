#include <bits/stdc++.h>
using namespace std;

pair<int,int> parse(string s) {
    size_t p = s.find('.');
    long long n = 0;
    int l = 0;

    if (p == string::npos) {
        n = stoll(s);
    } else {
        string a = s.substr(0, p);
        string b = s.substr(p + 1);

        l = b.size();

        if (!a.empty())
            n = stoll(a);

        for (char c : b)
            n = n * 10 + c - '0';
    }

    if (!n)
        return {18, 18};

    int v2 = 0, v5 = 0;
    long long t = n;

    while (t % 2 == 0) {
        v2++;
        t /= 2;
    }

    t = n;

    while (t % 5 == 0) {
        v5++;
        t /= 5;
    }

    v2 = min(9, v2 - l);
    v5 = min(9, v5 - l);

    return {v2 + 9, v5 + 9};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    long long cnt[19][19] = {};

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        pair<int,int> p = parse(s);
        cnt[p.first][p.second]++;
    }

    long long ans = 0;

    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            if (!cnt[i][j])
                continue;

            for (int x = 0; x < 19; x++) {
                for (int y = 0; y < 19; y++) {
                    if (!cnt[x][y])
                        continue;

                    if (i + x >= 18 && j + y >= 18) {
                        if (i == x && j == y)
                            ans += cnt[i][j] * (cnt[i][j] - 1);
                        else
                            ans += cnt[i][j] * cnt[x][y];
                    }
                }
            }
        }
    }

    cout << ans / 2 << '\n';
}