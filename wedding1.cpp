#include <bits/stdc++.h>
using namespace std;

const int MAXN = 4005;
int n;
vector<int> enemies[MAXN];
vector<int> seating;
bool used[MAXN];

bool is_valid(int knight, int pos) {
    int prev = seating[(pos - 1 + 2 * n) % (2 * n)];
    int next = seating[(pos + 1) % (2 * n)];
    return find(enemies[knight].begin(), enemies[knight].end(), prev) == enemies[knight].end() &&
           find(enemies[knight].begin(), enemies[knight].end(), next) == enemies[knight].end();
}

bool backtrack(int pos) {
    if (pos == 2 * n) return true;
    for (int i = 1; i <= 2 * n; ++i) {
        if (!used[i] && is_valid(i, pos)) {
            seating[pos] = i;
            used[i] = true;
            if (backtrack(pos + 1)) return true;
            used[i] = false;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= 2 * n; ++i) {
        int k; cin >> k;
        enemies[i].resize(k);
        for (int j = 0; j < k; ++j) cin >> enemies[i][j];
    }
    
    seating.assign(2 * n, 0);
    if (backtrack(0)) {
        for (int i = 0; i < 2 * n; ++i) cout << seating[i] << ' ';
    } else {
        cout << "-1\n";
    }
    return 0;
}
