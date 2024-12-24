#include <bits/stdc++.h>
using namespace std;

constexpr int MAX_N = 1e5 + 5;
constexpr int MAX_P = 7;
constexpr int MAX_MASK = (1 << MAX_P);

long long dp[MAX_N][MAX_MASK];
long long skills[MAX_N][MAX_P];
long long playerIndices[MAX_N];
long long scores[MAX_N];
bool compareByScore(long long player1, long long player2) {
    return scores[player1] > scores[player2];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long long numPlayers, numSkills, maxBasePlayers;
    cin >> numPlayers >> numSkills >> maxBasePlayers;

    memset(dp, -1, sizeof(dp));

    for (long long i = 1; i <= numPlayers; i++) {
        cin >> scores[i];
    }

    for (long long i = 1; i <= numPlayers; i++) {
        for (long long j = 0; j < numSkills; j++) {
            cin >> skills[i][j];
        }
    }

    for (long long i = 1; i <= numPlayers; i++) {
        playerIndices[i] = i;
    }

    sort(playerIndices + 1, playerIndices + numPlayers + 1, compareByScore);

    dp[0][0] = 0;

    for (long long i = 1; i <= numPlayers; i++) {
        long long currentPlayer = playerIndices[i];

        for (long long mask = 0; mask < (1 << numSkills); mask++) {
            long long usedSkills = __builtin_popcount(mask); 
            long long unselectedPlayers = (i - 1) - usedSkills;

            if (unselectedPlayers < maxBasePlayers) {
                if (dp[i - 1][mask] != -1) {
                    dp[i][mask] = dp[i - 1][mask] + scores[currentPlayer];
                }
            } else {
                if (dp[i - 1][mask] != -1) {
                    dp[i][mask] = dp[i - 1][mask];
                }
            }

            for (long long skill = 0; skill < numSkills; skill++) {
                if (mask & (1 << skill)) {
                    long long prevMask = mask ^ (1 << skill);
                    if (dp[i - 1][prevMask] != -1) {
                        long long newScore = dp[i - 1][prevMask] + skills[currentPlayer][skill];
                        dp[i][mask] = max(dp[i][mask], newScore);
                    }
                }
            }
        }
    }

    cout << dp[numPlayers][(1 << numSkills) - 1] << "\n";
    return 0;
}