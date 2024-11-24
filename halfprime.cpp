#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5;
int divs[MAXN];
bool isprime[MAXN];
int pref[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    for (int i = 1; i <= 1e6; i++) {
        for (int j = i; j <= 1e6; j += i) {
            divs[j]++;
        }
    }

    memset(isprime, true, sizeof(isprime));
    isprime[0] = isprime[1] = false;
    for (int i = 2; i * i <= 1e6; i++) {
        if (isprime[i]) {
            for (int j = i * i; j <= 1e6; j += i) {
                isprime[j] = false;
            }
        }
    }

    for (int i = 1; i <= 1e6; i++) {
        if (isprime[divs[i]]) {
            pref[i] = pref[i - 1] + 1;
        } else {
            pref[i] = pref[i - 1];
        }
    }

    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        cout << pref[b] - pref[a - 1] << '\n';
    }

    return 0;
}