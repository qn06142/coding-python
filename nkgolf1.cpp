#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <climits>
#include <cstdlib>
#include <ctime>
#include <memory.h>
#include <cassert>
#include <climits>
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define REP(i, a, b) for(int i = (a); i <=(b); i++)
#define FORD(i, a, b) for(int i = (a); i > (b); i--)
#define REPD(i, a, b) for(int i = (a); i >=(b); i--)
#define TR(it, a) for(typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define RESET(a, v) memset((a), (v), sizeof((a)))
#define SZ(a) (int((a).size()))
#define ALL(a) (a).begin(), (a).end()
#define PB push_back
#define MP make_pair
#define LL long long
#define LD long double
#define II pair<int, int>
#define X first
#define Y second
#define VI vector<int>

const int N = 1010;

using namespace std;

int a[N][N], L[N], R[N], h[N], lcp[N];
int n, m, ans;

int main() {
    ios :: sync_with_stdio(0); cin.tie(0);
    cin >> m >> n;
    REP(i, 1, m) REP(j, 1, n) cin >> a[i][j];
    REP(i, 1, m) {
        REP(j, 1, n)
        if (a[i][j] >= a[i - 1][j]) h[j]++;
            else h[j] = 1;
        REP(j, 2, n)
        if (a[i][j] >= a[i][j - 1]) lcp[j]++;
            else lcp[j] = 0;
        REP(j, 2, n)
            lcp[j] = min(lcp[j], min(h[j - 1], h[j]));
        REP(j, 2, n)
        for(L[j] = j - 1; L[j] > 1 && lcp[L[j]] >= lcp[j]; L[j] = L[L[j]]);
        REPD(j, n, 2)
        for(R[j] = j + 1; R[j] <= n && lcp[R[j]] >= lcp[j]; R[j] = R[R[j]]);
        REP(j, 1, n) ans = max(ans, h[j]);
        REP(j, 2, n) ans = max(ans, lcp[j] * (R[j] - L[j]));
    }
    cout << ans;
    return 0;
}
