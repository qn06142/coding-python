#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e3 + 5;
int mat[maxn][maxn];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> mat[i][j];
        }
    }

    m--;
    n--;
    vector<int> heights(m +21, 0);
    #ifndef ONLINE_JUDGE
    cerr << n << ' ' << m << endl;;
    #endif
    for(int i_ = 1; i_ <= n; i_++) {
        for(int j = 1; j <= m; j++) {
            if((mat[i_][j] <= mat[i_][j + 1] and mat[i_][j] <= mat[i_ + 1][j] and mat[i_ + 1][j] <= mat[i_ + 1][j + 1] and mat[i_][j  + 1] <= mat[i_ + 1][j + 1])) {
                heights[j]++;
            } else {
                heights[j] = 0;
            }
        }
        #ifndef ONLINE_JUDGE
        for(int i = 1; i <= m; i++) {
            cerr << heights[i] << ' ';
        }
        cerr << '\n';
        #endif
        cerr << "test" << endl;

        stack<int> stacc1, stacc2;
        vector<int> r(m + 1), l(m + 1);
        cerr << "test" << endl;
        for(int j = 1; j <= m; j++) {
            while(!stacc1.empty() && heights[stacc1.top()] >= heights[j]) {
                stacc1.pop();
            }
            l[j] = stacc1.empty() ? 1 : stacc1.top() + 1;
            stacc1.push(j);
        }

        for(int j = m; j >= 1; j--) {
            while(!stacc2.empty() && heights[stacc2.top()] >= heights[j]) {
                stacc2.pop();
            }
            r[j] = stacc2.empty() ? m : stacc2.top() - 1;
            stacc2.push(j);
        }

        for(int j = 1; j <= m; j++) {
            if(heights[j] > 0)
            ans = max(ans, (heights[j] + 1) * (r[j] - l[j] + 2));
        }
    }
    m ++;
    n ++;
    for(int i = 1; i <= n; i++) {
        int tt = 1;
        for(int j = 2; j <= m; j++) {
            if(mat[i][j] >= mat[i][j-1]) {
                tt++;
                ans = max(ans, tt);
            } else {
                tt = 1;
            }
        }
    }

    for(int j = 1; j <= m; j++) {
        int tt = 1;
        for(int i = 2; i <= n; i++) {
            if(mat[i][j] >= mat[i-1][j]) {
                tt++;
                ans = max(ans, tt);
            } else {
                tt = 1;
            }
        }
    }

    cout << ans;
    return 0;
}
