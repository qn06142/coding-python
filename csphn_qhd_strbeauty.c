#include <stdio.h>
#include <string.h>
#include <limits.h>

#define MAXL 105
#define MAXK 105
#define ALPH 26
#define NEG_INF (-1000000000)

int dp[MAXL][MAXK][ALPH];
int score[ALPH][ALPH];
char S[MAXL];

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int K, N;

    if (scanf("%s %d", S, &K) != 2) return 0;
    int L = strlen(S);

    scanf("%d", &N);

    for (int i = 0; i < ALPH; i++) {
        for (int j = 0; j < ALPH; j++) {
            score[i][j] = 0;
        }
    }

    for (int i = 0; i < N; i++) {
        char x, y;
        int z;
        scanf(" %c %c %d", &x, &y, &z);
        score[x - 'a'][y - 'a'] = z;
    }

    for (int i = 0; i <= L; i++) {
        for (int c = 0; c <= K; c++) {
            for (int a = 0; a < ALPH; a++) {
                dp[i][c][a] = NEG_INF;
            }
        }
    }

    for (int a = 0; a < ALPH; a++) {
        int cost = (S[0] - 'a' == a) ? 0 : 1;
        if (cost <= K) {
            dp[1][cost][a] = 0;
        }
    }

    for (int i = 1; i < L; i++) {
        for (int c = 0; c <= K; c++) {
            for (int a = 0; a < ALPH; a++) {
                if (dp[i][c][a] == NEG_INF) continue;
                for (int b = 0; b < ALPH; b++) {
                    int cost_inc = (S[i] - 'a' == b) ? 0 : 1;
                    if (c + cost_inc <= K) {
                        int val = dp[i][c][a] + score[a][b];
                        dp[i + 1][c + cost_inc][b] = max(
                            dp[i + 1][c + cost_inc][b], val
                        );
                    }
                }
            }
        }
    }

    int ans = NEG_INF;
    for (int c = 0; c <= K; c++) {
        for (int a = 0; a < ALPH; a++) {
            if (dp[L][c][a] > ans) {
                ans = dp[L][c][a];
            }
        }
    }
    if (ans == NEG_INF) ans = 0;

    printf("%d\n", ans);
    return 0;
}