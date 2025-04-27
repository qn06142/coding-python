#include <stdio.h>
#include <string.h>
#define MAXN 200005

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        int L;
        scanf("%d", &L);
        char s[MAXN];
        scanf("%s", s);
        int n = (int)strlen(s);

        int nxt[MAXN];
        int last = -1;
        for (int i = n-1; i >= 0; i--){
            if(s[i]=='1') last = i;
            nxt[i] = last;
        }
        long long ans = 0;
        for (int l = 0; l < n; l++){
            if(nxt[l] == -1) continue; 
            int rmax = nxt[l] + 17; 
            if(rmax >= n) rmax = n-1;
            long long v = 0;

            for (int r = l; r <= rmax; r++){
                v = (v << 1) + (s[r] - '0');
                int len = r - l + 1;
                if(v == len) ans++;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}