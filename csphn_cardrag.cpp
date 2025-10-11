#include <bits/stdc++.h>
using namespace std;

int m, n;
vector<vector<char>> a;

vector<vector<int>> state;

bool dfs(int x, int y) {

    if (state[x][y] == 2) return true;
    if (state[x][y] == 3) return false;
    if (state[x][y] == 1) {

        state[x][y] = 3;
        return false;
    }

    state[x][y] = 1;  
    char d = a[x][y];

    auto scan = [&](int dx, int dy) -> bool {
        int i = x + dx, j = y + dy;
        while (i >= 1 && i <= m && j >= 1 && j <= n) {
            if (a[i][j] != '.') {
                bool res = dfs(i, j);
                state[x][y] = res ? 2 : 3;
                return res;
            }
            i += dx; j += dy;
        }

        state[x][y] = 2;
        return true;
    };

    bool result = false;
    switch (d) {
        case 'N': result = scan(-1,  0); break;
        case 'S': result = scan( 1,  0); break;
        case 'W': result = scan( 0, -1); break;
        case 'E': result = scan( 0,  1); break;
        default:

            state[x][y] = 3;
            result = false;
    }
    return result;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (cin >> m >> n && (m || n)) {
        a.assign(m+1, vector<char>(n+1, '.'));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> a[i][j];
            }
        }

        state.assign(m+1, vector<int>(n+1, 0));
        int ans = 0;

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (a[i][j] != '.') {
                    if (dfs(i, j)) 
                        ans++;
                }
            }
        }

        cout << ans << "\n";
    }
}