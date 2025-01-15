#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    #ifdef ONLINE_JUDGE
    freopen("CHOIGAME.INP", "r", stdin);
    freopen("CHOIGAME.OUT", "w", stdout);
    #endif
    int N, K;
    cin >> N >> K;

    vector<int> H(N);
    for (int i = 0; i < N; ++i) {
        cin >> H[i];
    }

    vector<int> dp(N, 0);
    dp[0] = 1; 

    for (int i = 1; i < N; ++i) {
        for (int j = N - 1; j >= 0; --j) {
            if (abs(H[i] - H[j]) <= K && dp[j] == 1) {
                dp[i] = 1;
                break; 
            }
        }
    }
    for(int i = 0; i < N; i++) {
        cout << dp[i] << ' ';
    }
    return 0;
}