// main.cpp
#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

static const int MOD = 123456789;
static const int MAXQ = 100000;          // max T
static const int MAX_DIGITS = 100000;    // max n

struct Node {
    int p10;  // = 10^{length_of_chunk} mod MOD
    int v;    // = value_of_chunk  mod MOD
};

// fast combine: build A||B
//   new.p10 = A.p10 * B.p10 % MOD
//   new.v   = (A.v * B.p10 + B.v) % MOD
inline Node comb(const Node &A, const Node &B) {
    Node C;
    long long t1 = (long long)A.p10 * B.p10;
    C.p10 = int(t1 % MOD);
    long long t2 = (long long)A.v * B.p10 + B.v;
    C.v   = int(t2 % MOD);
    return C;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    vector<pair<string,int>> Q(T);
    int max_n = 0;
    for(int i = 0; i < T; i++){
        cin >> Q[i].first >> Q[i].second;
        if(Q[i].second > max_n)
            max_n = Q[i].second;
    }

    // DP[d][j] = result‑chunk when you take digit d and apply the "×3, split digits" rule j times.
    // We store { p10 = 10^{len} mod MOD,  v = int_value mod MOD }.
    static Node dp[10][MAX_DIGITS + 1];

    // base: 0→"0", 1→"1", …, 9→"9"
    for(int d = 0; d < 10; d++){
        dp[d][0].p10 = 10;  // one digit → 10^1
        dp[d][0].v   = d;
    }

    // build up to j = max_n
    for(int j = 1; j <= max_n; j++){
        for(int d = 0; d < 10; d++){
            int x = d * 3;
            if(x < 10){
                // just passes through
                dp[d][j] = dp[x][j - 1];
            } else {
                // split into high & low decimal digits
                dp[d][j] = comb(dp[x / 10][j - 1], dp[x % 10][j - 1]);
            }
        }
    }

    // answer each query
    for(auto &q : Q){
        const string &k = q.first;
        int n = q.second;

        // start from the last digit
        Node res = dp[k.back() - '0'][n];

        // fold in each preceding digit
        for(int i = int(k.size()) - 2; i >= 0; --i){
            res = comb(dp[k[i] - '0'][n], res);
        }
        cout << res.v << "\n";
    }
    return 0;
}
