#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 1234567890
extern char* strdup(const char*);
int count(const char *text, const char *pattern) {
    int count = 0;
    int n = strlen(text);
    int pl = strlen(pattern);
    for (int i = 0; i <= n - pl; i++) {
        if (strncmp(&text[i], pattern, pl) == 0) {
            count++;
        }
    }
    return count;
}

int main() {
    int n;
    char S[100005];

    while (scanf("%d %s", &n, S) == 2) {

        char *f[105]; 
        if(n < 1) continue; 

        f[1] = strdup("A");
        if(n >= 2)
            f[2] = strdup("B");

        for (int i = 3; i <= n; i++) {
            int len1 = strlen(f[i - 1]);
            int len2 = strlen(f[i - 2]);
            int newLen = len1 + len2;
            f[i] = (char *)malloc(newLen + 1);
            strcpy(f[i], f[i - 1]);
            strcat(f[i], f[i - 2]);
        }

        int occ = count(f[n], S);
        printf("%d\n", occ % MOD);

        for (int i = 1; i <= n; i++) {
            free(f[i]);
        }
    }
    return 0;
}