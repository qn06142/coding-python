#include <bits/stdc++.h>
using namespace std;

const int MAXN = 505;
const int INF = 1e9;
bool isedge[MAXN][MAXN];
int reach[MAXN][MAXN]; 
pair<char, pair<int, int>> stor[(int) 1e5 + 5];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    memset(reach, 0x3f, sizeof reach);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        isedge[x][y] = 1;
    }
    for(int i = 1; i <= k; i++) {
        char c;
        cin >> c;
        if(c == 'Y') {
            int x, y;
            cin >> x >> y;
            stor[i] = make_pair(c, make_pair(x, y));
        } else {
            int x;
            cin >> x;
            stor[i] = make_pair(c, make_pair(x, 0));
            reach[x][x] = min(reach[x][x], i);
            for(int i = 1; i <= n; i++) {
                if(isedge[x][i])
                reach[x][i] = max(reach[x][x], reach[i][i]);
                if(isedge[i][x]) 
                reach[i][x] = max(reach[x][x], reach[i][i]);
            }
        }
    }
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                reach[i][j] = min(reach[i][j], max(reach[i][k], reach[k][j]));
            }
        }
    }
    for(int i = 1; i <= k; i++) {
        if(stor[i].first == 'Y') {
            cout << (((reach[stor[i].second.first][stor[i].second.second] <= i) or stor[i].second.first == stor[i].second.second) ? 'Y' : 'N');
        }
    }
    return 0;
}