#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
#define INF 1000000000

int n, k;
char x[100005];

int best_arr[100005], best_letter[100005], second_arr[100005], delta[100005];

int main(void) {
    if (scanf("%d %d", &n, &k) != 2)
        return 1;
    scanf("%s", x);

    int ans = n;

    {
        int freq[26] = {0};
        for (int i = 0; i < n; i++)
            freq[x[i]-'a']++;
        int maxf = 0;
        for (int i = 0; i < 26; i++) {
            if (freq[i] > maxf)
                maxf = freq[i];
        }
        int cst = n - maxf;
        if (cst <= k) {
            printf("1\n");
            return 0;
        }
    }

    for (int t = 2; t <= n; t++) {
        if (n % t != 0)
            continue;
        int gs = n / t;  
        int base = 0;

        for (int r = 0; r < t; r++) {
            int cnt[26] = {0};
            for (int j = r; j < n; j += t)
                cnt[x[j]-'a']++;
            int b = gs;   
            int let = -1; 
            int sec = gs; 
            for (int c = 0; c < 26; c++) {
                int cst = gs - cnt[c];
                if (cst < b) {
                    sec = b;
                    b = cst;
                    let = c;
                } else if (c != let && cst < sec) {
                    sec = cst;
                }
            }
            best_arr[r] = b;
            best_letter[r] = let;
            second_arr[r] = sec;
            delta[r] = sec - b;
            base += b;
        }

        int dmin = t;  
        for (int d = 1; d < t; d++) {
            if (t % d != 0)
                continue;
            bool bad = true;
            for (int r = 0; r < d; r++) {
                int cl = best_letter[r];
                for (int j = r; j < t; j += d) {
                    if (best_letter[j] != cl) {
                        bad = false;
                        break;
                    }
                }
                if (!bad)
                    break;
                bad = true; 
            }

            {
                bool ok = true;
                for (int r = 0; r < d; r++) {
                    int cl = best_letter[r];
                    for (int j = r; j < t; j += d) {
                        if (best_letter[j] != cl) {
                            ok = false;
                            break;
                        }
                    }
                    if (!ok)
                        break;
                }
                if (ok && d < dmin)
                    dmin = d;
            }
        }

        int extra = 0;

        if (dmin < t) {
            int fix = INF;
            for (int r = 0; r < dmin; r++) {
                if (delta[r] < fix)
                    fix = delta[r];
            }
            extra = fix;
        }
        int cand = base + extra;
        if (cand <= k) {
            printf("%d\n", t);
            return 0;
        }
    }

    printf("%d\n", ans);
    return 0;
}