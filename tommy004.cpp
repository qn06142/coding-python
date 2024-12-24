#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e7;
bool prime[MAX];
int freq[MAX];
int f[MAX];
int pref[MAX];

void sieve() {
    memset(prime, 1, sizeof prime);
    prime[0] = prime[1] = 0;
    for (int i = 2; i * i < MAX; i++) {
        if (prime[i]) {
            for (int j = i * i; j < MAX; j += i) {
                prime[j] = 0;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        freq[t]++;
    }

    sieve();

    for (int i = 2; i < MAX; i++) {
        if (prime[i]) {
            for (int j = i; j < MAX; j += i) {
                f[i] += freq[j];
            }
        }
        pref[i] = pref[i - 1] + f[i];
    }

    int m;
    cin >> m;
    while (m--) {
        int l, r;
        cin >> l >> r;

        r = min(r, MAX - 1);
        if (l >= MAX) {
            cout << "0\n";
        } else {
            l = max(l, 2);
            cout << pref[r] - pref[l - 1] << '\n';
        }
    }

    return 0;
}
