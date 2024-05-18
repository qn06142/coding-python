#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;
int mat[405][405], pref[405][405];
int main() {
    int n, m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> mat[i][j];
            pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + mat[i][j];
        }
    }
    vector<int> ans;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            for(int a = i; a <= n; a++) {
                for(int b = j; b <= m; b++) {
                    ans.push_back((pref[a][b] + pref[i - 1][j - 1] - pref[i - 1][b] - pref[a][j - 1]) - ((pref[a - 1][b - 1] + pref[i][j] - pref[i][b - 1] - pref[a - 1][j])))
                }
            }
        }
    }
    cout << *max_element(ans.begin(), ans.end());
}