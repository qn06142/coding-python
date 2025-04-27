#include <stdio.h>
#include <memory.h>
#pragma GCC optimize("trapv")
#define MAX_SIZE 1000100
#define int long long

int stack[MAX_SIZE];
int top = -1;

void push(int value) {
    stack[++top] = value;
}

void pop() {
    if (top >= 0) top--;
}

int is_empty() {
    return top == -1;
}

int peek() {
    return stack[top];
}

int a[MAX_SIZE];
int main() {
    int t;
    scanf("%lld", &t);
    
    while (t--) {
        memset(a, 0, top + 1);
        int n;
        scanf("%lld", &n);

        for (int i = 0; i < n; i++) {
            scanf("%lld", &a[i]);
        }
        if(top >= MAX_SIZE) return 1;
        top = -1;
        int res = 0;

        for (int i = 0; i < n; i++) {
            while (!is_empty() && peek() > a[i]) {
                pop();
            }
            if (a[i] > 0 && (is_empty() || peek() < a[i])) {
                res++;
            }
            push(a[i]);
        }

        printf("%lld\n", res);
    }

    return 0;
}
