#include <cstdio>

#define MAX 1000000

int s[MAX+5];

void init() {
    for( int i = 1; i <= MAX; ++i ) 
        for( int j = i+i; j <= MAX; j += i ) s[j] += i;
}

int main() {
    init(); int l, r; scanf( "%d%d", &l, &r );
    int res = 0;
    for( int i = l; i <= r; ++i )
        res += s[i] > i;
    printf( "%d\n", res );
    return 0;
}