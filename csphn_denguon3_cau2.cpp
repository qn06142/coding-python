#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e6 + 5;
bool dd[MAX];
vector<int> b[MAX];
int f[MAX], cnt[MAX];

int main() {
    int n;
    cin >> n;

    for (int i = 1; i * i <= n; i++) {
        dd[i * i] = true;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j += i) {
            b[j].push_back(i);
        }
    }

    for (int i = 1; i <= n; i++) {
        for (auto x : b[i]) {
            if (dd[x]) {
                f[i] = x;
            }
        }
        cnt[i / f[i]]++;
    }

    long long res = 0;
    for (int i = 1; i <= n; i++) {
        res += cnt[i] * cnt[i];
    }

    cout << res << endl;

    return 0;
}
