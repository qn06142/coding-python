#include<stdio.h>
#define maxn 200005
int bit[maxn];
#define max(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a > _b ? _a : _b; })
void update(int i, int x) {
    while(i <= maxn) {
        bit[i] = max(bit[i], x);
        i += -i & i;
    }
}

int get(int i) {
    int ans = 0;
    while(i > 0) {
        ans = max(ans, bit[i]);
        i -= -i & i;
    }
    return ans;
}

int a[maxn];
int dp[maxn];
int calc(int x) {return x % 100;}
int main() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for(int i = 1; i <= n; i++) {
        dp[i] = get(a[i] - 1) + calc(a[i]);
        update(a[i], dp[i]);
    }
    printf("%d", get(maxn));
}