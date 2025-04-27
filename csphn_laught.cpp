#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXS 100005   
#define MAXP 35       
#define MAXN 1005     

typedef long long ll;
const ll MOD = 1000000007LL;
const ll BASE = 131LL;

char s[MAXS];
char pat[MAXN][MAXP];
int dp[MAXS];           
ll prefix[MAXS];        
ll power[MAXS];         

ll set[31][MAXN];    
int patcount[31] = {0};

int n, m;

ll getHash(int l, int r) {
    if (l == 0) return prefix[r];
    ll h = prefix[r] - (prefix[l - 1] * power[r - l + 1] % MOD);
    if (h < 0) h += MOD;
    return h;
}

int cmp_ll(const void* a, const void* b) {
    ll A = *(ll*)a;
    ll B = *(ll*)b;
    return (A < B) ? -1 : (A > B);
}

int main(){
    scanf("%d", &n);
    scanf("%s", s);
    m = strlen(s);

    int maxlen = 0;

    for (int i = 0; i < n; i++){
        scanf("%s", pat[i]);
        int len = strlen(pat[i]);
        if (len > maxlen) maxlen = len;
        ll h = 0;
        for (int j = 0; j < len; j++){
            h = (h * BASE + (pat[i][j] - 'a' + 1)) % MOD;
        }
        set[len][patcount[len]++] = h;
    }

    for (int L = 1; L <= 30; L++){
        if (patcount[L] > 0)
            qsort(set[L], patcount[L], sizeof(ll), cmp_ll);
    }

    power[0] = 1;
    for (int i = 1; i <= m; i++){
        power[i] = (power[i - 1] * BASE) % MOD;
    }
    prefix[0] = (s[0] - 'a' + 1);
    for (int i = 1; i < m; i++){
        prefix[i] = (prefix[i - 1] * BASE + (s[i] - 'a' + 1)) % MOD;
    }

    for (int i = 0; i < m; i++){
        dp[i] = -1;
    }

    int ans = 0;

    for (int i = 0; i < m; i++){

        int Lmax = (i + 1 < maxlen) ? i + 1 : maxlen;
        if(Lmax > 30) Lmax = 30;
        for (int L = 1; L <= Lmax; L++){
            int j = i - L + 1;  

            if(patcount[L] == 0) continue;
            ll subH = getHash(j, i);

            int lo = 0, hi = patcount[L] - 1, found = 0;
            while (lo <= hi) {
                int mid = (lo + hi) / 2;
                if (set[L][mid] == subH) { found = 1; break; }
                else if (set[L][mid] < subH) lo = mid + 1;
                else hi = mid - 1;
            }
            if (found) {

                int candidate = L;
                if (j > 0 && dp[j - 1] != -1) {
                    int ext = dp[j - 1] + L;
                    if (ext > candidate)
                        candidate = ext;
                }
                if (candidate > dp[i])
                    dp[i] = candidate;
            }
        }
        if (dp[i] > ans)
            ans = dp[i];
    }

    printf("%d\n", ans);
    return 0;
}
