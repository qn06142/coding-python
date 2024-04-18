#include<bits/stdc++.h>
using namespace std;

long long sum_n(long long n) {
    return n * (n + 1) / 2;
}

bool check(long long mid, long long L, long long R) {
    return sum_n(R) - sum_n(mid) >= sum_n(mid) - sum_n(L-1);
}

long long solve(long long L, long long R) {
    long long low = L, high = R;
    while(high - low > 1){
        long long mid = (low + high) / 2;
        if(check(mid, L, R)){
            low = mid;
        } else {
            high = mid;
        }
    }
    return low;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long L, R;
    cin >> L >> R;
    cout << solve(L, R) << "\n";

    return 0;
}
