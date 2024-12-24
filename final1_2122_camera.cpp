#include <bits/stdc++.h>

using namespace std;

template<class A, class B> bool maximize(A& x, B y) {if (x < y) return x = y, true; else return false;}
template<class A, class B> bool minimize(A& x, B y) {if (x > y) return x = y, true; else return false;}

#define     all(a)                a.begin(), a.end()
#define     pb                    push_back
#define     pf                    push_front
#define     fi                    first
#define     se                    second
// #define     int                   long long

typedef     long long             ll;
typedef     unsigned long long    ull;
typedef     double                db;
typedef     long double           ld;
typedef     pair<db, db>          pdb;
typedef     pair<ld, ld>          pld;
typedef     pair<int, int>        pii;
typedef     pair<ll, ll>          pll;
typedef     pair<ll, int>         plli;
typedef     pair<int, ll>         pill;

const int MAX_N = 1e5 + 5;
const int mod = 1e9 + 7; // 998244353

int n;
int a[MAX_N];
string dir;
int l[MAX_N], r[MAX_N];
int ans[MAX_N];
int prefSum[MAX_N];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("CAMERA.INP", "r", stdin);
    freopen("CAMERA.OUT", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cin >> dir;
    dir = ' ' + dir;

    for (int i = 1; i <= n; i++) {
        l[i] = i;
        while (l[i] - 1 && a[l[i] - 1] <= a[i]) {
            l[i] = l[l[i] - 1];
        }
        prefSum[l[i] - 1]++;
        prefSum[i]--;
    }
    for (int i = 1; i <= n; i++) {
        prefSum[i] += prefSum[i - 1];
        if (dir[i] == 'E') {
            ans[i] += prefSum[i];
        }
    }

    fill(prefSum, prefSum + n + 1, 0);

    for (int i = n; i; i--) {
        r[i] = i;
        while (r[i] < n && a[r[i] + 1] <= a[i]) {
            r[i] = r[r[i] + 1];
        }
        prefSum[i + 1]++;
        prefSum[r[i] + 2]--;
    }
    for (int i = 1; i <= n; i++) {
        prefSum[i] += prefSum[i - 1];
        if (dir[i] == 'W') {
            ans[i] += prefSum[i];
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << ' ';
    }

    return 0;
}

/*


*/
