#include <bits/stdc++.h>
using namespace std;

const int MAXN = 500;
int m, n, k;
int a[MAXN + 1][MAXN + 1];
int freq[MAXN * MAXN + 1]; 

bool check(int x) {
    memset(freq, 0, sizeof(freq));
    int distinct = 0;

    for (int i = 1; i + x - 1 <= m; i++) {
        for (int j = 1; j + x - 1 <= n; j++) {
            if (j == 1) { 
                distinct = 0;
                memset(freq, 0, sizeof(freq));
                for (int u = i; u < i + x; u++) {
                    for (int v = j; v < j + x; v++) {
                        if (++freq[a[u][v]] == 1) distinct++;
                    }
                }
            } else { 
                for (int u = i; u < i + x; u++) {

                    if (--freq[a[u][j - 1]] == 0) distinct--;

                    if (++freq[a[u][j + x - 1]] == 1) distinct++;
                }
            }
            if (distinct <= k) return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> m >> n >> k;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    int l = 1, r = min(m, n), ans = 0;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            ans = mid; 
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout << ans << "\n";
    return 0;
}