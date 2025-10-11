#include <bits/stdc++.h>
using namespace std;

long long ones(long long x, int b){
    if(x < 0) return 0;
    long long block = 1LL << (b + 1);
    long long full = (x + 1) / block;
    long long res = full * (1LL << b);
    long long rem = (x + 1) % block;
    res += max(0LL, rem - (1LL << b));
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        long long l, r;
        cin >> l >> r;
        long long n = r - l + 1;
        long long best = 0; 
        for(int b = 0; (1LL << b) <= r; ++b){
            long long cnt = ones(r, b) - ones(l - 1, b);
            best = max(best, cnt);
        }
        cout << (n - best) << '\n';
    }
}