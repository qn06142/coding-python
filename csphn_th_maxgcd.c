#include<stdio.h>
#include<math.h>
int gcd(int a, int b)
{
    int temp;
    while (b != 0)
    {
        temp = a % b;

        a = b;
        b = temp;
    }
    return a;
}
#define max(a,b) \
  ({ __typeof__ (a) _a = (a); \
    __typeof__ (b) _b = (b); \
    _a > _b ? _a : _b; })
#define maxn 100005
int pref[maxn], suff[maxn];
int a[maxn];
int main() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for(int i = 1; i <= n; i++) {
        pref[i] = gcd(a[i], pref[i - 1]);
    }
    for(int i = n; i >= 1; i--) {
        suff[i] = gcd(a[i], suff[i + 1]);
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        ans = max(ans, gcd(pref[i - 1], suff[i + 1]));
    }
    printf("%d", ans);
}