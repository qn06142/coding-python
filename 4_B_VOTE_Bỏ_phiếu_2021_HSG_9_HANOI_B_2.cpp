#include<bits/stdc++.h>
using namespace std;

bool mat[(int) 5e3 + 5][(int) 5e3 + 5];
int a[(int) 5e3 + 5];
int main() {
    cerr << "ok" << endl;

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    cerr << "ok" << endl;

    for(int i = 1; i<= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            char c;
            cin >> c;
            mat[i][j] = c == 'X';
        }
    }
    cerr << "ok" << endl;
    for(int j = 1; j <= n; ++j) {
        for(int i = 1; i <= n; ++i) {
            if(mat[i][j]) {
                a[j]++;
            }
        }
    }
    int maxx = *max_element(a, a + n + 1);
    int cnt = 0;
    vector<int> ans;
    for(int i = 1; i <= n; ++i) {
        if(a[i] == maxx) {
            ans.push_back(i);
            cnt++;
        }
    }

    cout << cnt << ' ' << maxx << '\n';
    for(auto &&i : ans) {
        cout << i << ' ';
    }
}