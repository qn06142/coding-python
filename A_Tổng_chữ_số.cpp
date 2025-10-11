#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128_t;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<i64> A(N);
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }

    i128 S = 0;
    for(i64 x: A){
        i64 t = x;
        while(t){
            S += (t % 10);
            t /= 10;
        }
    }

    const int K = 16;
    i64 p10[K+1];
    p10[0] = 1;
    for(int k = 1; k <= K; k++){
        p10[k] = p10[k-1] * 10;
    }

    i128 C = 0;
    vector<i64> X(N);
    for(int k = 0; k < K; k++){

        i64 M = p10[k+1];
        for(int i = 0; i < N; i++){
            X[i] = A[i] % M;
        }
        sort(X.begin(), X.end());

        for(int i = 0; i < N; i++){
            i64 need = M - X[i];
            auto it = lower_bound(X.begin(), X.end(), need);
            C += (X.end() - it);
        }
    }

    i128 ans = (i128)2 * N * S - (i128)9 * C;

    bool neg = (ans < 0);
    if(neg) ans = -ans;
    string out;
    do {
        out.push_back(char('0' + ans % 10));
        ans /= 10;
    } while(ans);
    if(neg) out.push_back('-');
    reverse(out.begin(), out.end());
    cout << out << "\n";
}