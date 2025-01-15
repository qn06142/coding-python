#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> a;
int total_sum;
int max_sum = 0;
const int maxn = 15;
const int maxs = 1000;
int dp[maxn][maxs][maxs];

void backtrack(int index, int sum1, int sum2) {
    if (index == N) {

        if (sum1 == sum2) {
            max_sum = max(max_sum, sum1);
        }
        return;
    }

    if (dp[index][sum1][sum2] != -1) {
        return;
    }

    dp[index][sum1][sum2] = 1;

    backtrack(index + 1, sum1 + a[index], sum2);

    backtrack(index + 1, sum1, sum2 + a[index]);

    backtrack(index + 1, sum1, sum2);
}

int main() {
    #ifdef ONLINE_JUDGE
    freopen("CT.INP", "r", stdin);
    freopen("CT.OUT", "w", stdout);
    #endif
    cin >> N;
    a.resize(N);
    total_sum = 0;

    for (int i = 0; i < N; i++) {
        cin >> a[i];
        total_sum += a[i];
    }

    for (int i = 0; i < maxn; i++) {
        for (int j = 0; j < maxs; j++) {
            for (int k = 0; k < maxs; k++) {
                dp[i][j][k] = -1;
            }
        }
    }

    backtrack(0, 0, 0);

    cout << max_sum << endl;

    return 0;
}
