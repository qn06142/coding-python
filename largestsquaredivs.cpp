#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll solve(ll A, ll B) {
    ll x = ceil(sqrt(B));
    while (x % A != 0) {
        x++;
    }
    return x * x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int Q;
    cin >> Q;
    while (Q--) {
        ll A, B;
        cin >> A >> B;
        cout << solve(A, B) << "\n";
    }

    return 0;
}
