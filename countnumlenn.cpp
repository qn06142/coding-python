#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
int S[10];
int dp[11][10] = {0};
int countValidNumbers(int m, int n) {

    sort(S, S + m);

    for (int j = 0; j < m; j++) {
        dp[1][j] = 1;
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            dp[i][j] = 0;
            for (int k = 0; k < m; k++) {
                if (abs(S[j] - S[k]) <= 2) {
                    dp[i][j] += dp[i - 1][k];
                }
            }
        }
    }

    int result = 0;
    for (int j = 0; j < m; j++) {
        result += dp[n][j];
    }
    return result;
}

int main() {
    int t;
    cin >> t;
    int results[300];

    for (int i = 0; i < t; i++) {
        int m, n;
        cin >> m >> n;

        for (int j = 0; j < m; j++) {
            cin >> S[j];
        }
        results[i] = countValidNumbers(m, n);
    }

    for (int i = 0; i < t; i++) {
        cout << results[i] << endl;
    }

    return 0;
}