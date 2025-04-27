#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> a(n+1), b(n+1), P(n+1);
    int pos = 0;

    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(a[i] == m) pos = i;

        if(a[i] > m)      b[i] = +1;
        else if(a[i] < m) b[i] = -1;
        else              b[i] = 0;
    }

    P[0] = 0;
    for(int i = 1; i <= n; i++){
        P[i] = P[i-1] + b[i];
    }

    unordered_map<int, array<long long,2>> cnt_left;
    for(int i = 0; i < pos; i++){
        int sum = P[i];
        int parity = i & 1;
        cnt_left[sum][parity]++;
    }

    long long ans = 0;
    for(int R = pos; R <= n; R++){
        int sum_r    = P[R];
        int parity_r = R & 1;
        auto it = cnt_left.find(sum_r);
        if(it != cnt_left.end()){
            ans += it->second[1 - parity_r];
        }
    }
    
    cout << ans << "\n";
    return 0;
}