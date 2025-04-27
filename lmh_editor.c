#include <stdio.h>
#include <string.h>
#include <limits.h>

#define MAXN 105
#define MOD 1000000007LL
#define BASE 31LL

char s[MAXN];
int n;
int memo[MAXN];

long long hash[MAXN];
long long power[MAXN];

void calchash() {
    power[0] = 1;
    hash[0] = s[0] - 'a' + 1;
    for (int i = 1; i < n; i++) {
        power[i] = (power[i-1] * BASE) % MOD;
        hash[i] = (hash[i-1] + (s[i]-'a'+1) * power[i]) % MOD;
    }
}

long long gethash(int l, int r) {
    if(l == 0)
        return hash[r-1];
    long long res = (hash[r-1] - hash[l-1] + MOD) % MOD;
    res = (res * power[MAXN-1 - l]) % MOD;  
    return res;
}

int comp(int i, int len) {

    long long hash1 = 0;
    for (int j = 0; j < len; j++) {
        hash1 = (hash1 + (s[j]-'a'+1) * power[j]) % MOD;
    }

    long long seg = 0;
    for (int j = 0; j < len; j++) {
        seg = (seg + (s[i+j]-'a'+1) * power[j]) % MOD;
    }
    return (hash1 == seg);
}

int getlen(int i) {
    int L = (i < n - i ? i : n - i); 
    int low = 0, high = L;
    while(low < high) {
        int mid = (low + high + 1) / 2;
        if(comp(i, mid))
            low = mid;
        else
            high = mid - 1;
    }
    return low; 
}

int solve(int i) {
    if(i == n)
        return 0;
    if(memo[i] != -1)
        return memo[i];

    int ans = INT_MAX;

    ans = 1 + solve(i + 1);

    if(i > 0) {
        int maxcopy = getlen(i);
        if(maxcopy > 0) {
            int candidate = 1 + solve(i + maxcopy);
            if(candidate < ans)
                ans = candidate;
        }
    }

    memo[i] = ans;
    return ans;
}

int main() {
    int t;
    scanf("%d", &t);

    while(t--) {
        scanf("%s", s);
        n = strlen(s);

        calchash();

        for (int i = 0; i <= n; i++)
            memo[i] = -1;

        int result = solve(0);
        printf("%d\n", result);
    }
    return 0;
}