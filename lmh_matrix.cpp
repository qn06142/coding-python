#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m,n;
    cin >> m >> n;
    vector<vector<int>> A(m, vector<int>(n));
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            cin >> A[i][j];

    vector<vector<int>> S(m, vector<int>(n));
    for(int r = 0; r < m; r++){
        S[r] = A[r];
        sort(S[r].rbegin(), S[r].rend());
    }

    int r1 = 0;
    for(int r = 1; r < m; r++){
        if(S[r] > S[r1]) 
            r1 = r;
    }

    vector<pair<int,int>> cols;
    cols.reserve(n);
    for(int c = 0; c < n; c++){
        cols.emplace_back(A[r1][c], c);
    }
    sort(cols.begin(), cols.end(),
         [&](auto &a, auto &b){
             return a.first > b.first;
         });

    vector<int> col_perm(n);
    for(int j = 0; j < n; j++){
        col_perm[j] = cols[j].second;
    }

    vector<vector<int>> V(m, vector<int>(n));
    for(int r = 0; r < m; r++){
        for(int j = 0; j < n; j++){
            V[r][j] = A[r][ col_perm[j] ];
        }
    }

    vector<int> row_perm(m);
    iota(row_perm.begin(), row_perm.end(), 0);
    sort(row_perm.begin(), row_perm.end(),
         [&](int a, int b){
             return V[a] > V[b];
         });

    for(int i = 0; i < m; i++){
        int r = row_perm[i];
        for(int j = 0; j < n; j++){
            if(j) cout << ' ';
            cout << A[r][ col_perm[j] ];
        }
        cout << "\n";
    }

    return 0;
}