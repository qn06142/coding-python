#include <stdio.h>
#include <string.h>

int main() {

    char S[100005];
    if (scanf("%s", S) != 1) {
        return 1;
    }

    int n = strlen(S) + 1;
    int stack[n];  
    int top = -1;  
    int i;

    for (i = 1; i <= n; i++) {

        stack[++top] = i;

        if (i == n || S[i - 1] == '<') {

            while (top != -1) {
                printf("%d ", stack[top--]);
            }
        }
    }

    return 0;
}