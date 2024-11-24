#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

#define SPEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEED; ios::sync_with_stdio(false); cin.tie(0);

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int N = 100;
const int M = 1E7;

int prodPow[M+9], lcmPow[M+9];
int a[N+9];
int n;

void factNum(int n, int val, int myPow[]) {
    for (int i = 2; i <= n; ++i) {
        while (n % i == 0) {
            n /= i;
            myPow[i] += val;
        }
    }
}

ll myPow(ll x, ll y) {
    ll res = 1;
    while (y > 0) {
        if (y & 1) res *= x;
        y >>= 1;
        x *= x;
    }
    return res;
}

void factLCM(int n) {
    for (int i = 2; i <= n; ++i) {
        int cnt = 0;
        while (n % i == 0) {
            n /= i;
            ++cnt;
        }
        lcmPow[i] = max(lcmPow[i], cnt);
    }
}

void solveOne() {
    for (int i = 1; i <= n; ++i) factNum(a[i], 1, prodPow);

    for (int i = 1; i <= n; ++i) factLCM(a[i]);

    for (int i = 1; i <= M; ++i)
        prodPow[i] -= lcmPow[i];

    ll ans = 1;
    for (int i = 1; i <= M; ++i) {
        if (prodPow[i] > 0) {
            for (int j = 0; j < prodPow[i]; ++j) {
                ans *= i;
            }
        }
    }
    cout << ans << "\n";
}

int myGCD(int a, int b) {
    while (b > 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main() {
    SPEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEED;

    cin >> n;

    if (n == 0) {
        cout << "impossible";
        return 0;
    }

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (a[i] == 0) {
            cout << "impossible";
            return 0;
        }
    }

    solveOne();

    return 0;
}
