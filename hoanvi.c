#include <stdio.h>

int main() {
    int N, L;
    scanf("%d %d", &N, &L);

    int pos = -1;

    for (int i = 1; i <= N; i++) {
        int val;
        scanf("%d", &val);
        if(val == 1) {
            pos = i;
        }
    }

    if(N <= L) {
        printf("1\n");
        return 0;
    }

    int low = pos - L + 1;
    if(low < 1) low = 1;
    int high = pos;
    if(high > N - L + 1) high = N - L + 1;

    int ans = 1e9; 

    for (int x = low; x <= high; x++) {

        int left = ( (x - 1) + (L - 1) - 1 ) / (L - 1);

        int remaining = N - (x + L - 1);
        int right = ( remaining + (L - 1) - 1 ) / (L - 1);

        int total = 1 + left + right;  
        if(total < ans)
            ans = total;
    }

    printf("%d\n", ans);
    return 0;
}