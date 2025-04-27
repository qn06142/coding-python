#include <stdio.h>
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        long long X, Y;
        scanf("%lld %lld", &X, &Y);

        if(Y > X){
            printf("No\n");
            continue;
        }
        long long temp = X, sumdig = 0;

        while(temp > 0){
            sumdig += temp % 3;
            temp /= 3;
        }

        if(Y < sumdig || ((Y - sumdig) % 2 != 0))
            printf("No\n");
        else
            printf("Yes\n");
    }
    return 0;
}