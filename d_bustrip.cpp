#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef unsigned long long ULL;

#define MAXN 310

int blocks;

ULL mat[MAXN][MAXN/64 + 1];
ULL ans[MAXN][MAXN/64 + 1];
ULL cur[MAXN][MAXN/64 + 1];
ULL temp[MAXN][MAXN/64 + 1];

void bool_mat_mult(ULL A[MAXN][MAXN/64 + 1], ULL B[MAXN][MAXN/64 + 1],
                   ULL C[MAXN][MAXN/64 + 1], int n) {

    ULL T[MAXN][MAXN/64 + 1];
    memset(T, 0, sizeof(T));

    for (int r = 0; r < n; r++) {
        for (int bi = 0; bi < blocks; bi++) {
            ULL val = B[r][bi];
            if(val) {
                for (int bit = 0; bit < 64; bit++){
                    int col = bi * 64 + bit;
                    if(col >= n) break;
                    if(val & (1ULL << bit)) {
                        int block_index = r / 64;
                        int pos = r % 64;
                        T[col][block_index] |= (1ULL << pos);
                    }
                }
            }
        }
    }

    memset(C, 0, sizeof(ULL) * MAXN * (MAXN/64 + 1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int found = 0;
            for (int bi = 0; bi < blocks; bi++) {
                if (A[i][bi] & T[j][bi]) {
                    found = 1;
                    break;
                }
            }
            if (found) {
                int block_index = j / 64;
                int pos = j % 64;
                C[i][block_index] |= (1ULL << pos);
            }
        }
    }
}

int main(){
    int n, m;

    unsigned long long k;  
    scanf("%d %d %llu", &n, &m, &k);

    blocks = (n + 63) / 64;

    memset(cur, 0, sizeof(cur));
    for (int i = 0; i < m; i++){
        int u, v;
        scanf("%d %d", &u, &v);
        u--; v--;

        int bu = u / 64, pu = u % 64;
        int bv = v / 64, pv = v % 64;
        cur[u][v/64] |= (1ULL << (v % 64));
        cur[v][u/64] |= (1ULL << (u % 64));
    }

    memset(ans, 0, sizeof(ans));
    for (int i = 0; i < n; i++){
        int bi = i / 64, pos = i % 64;
        ans[i][bi] |= (1ULL << pos);
    }

    while(k > 0){
        if (k & 1ULL) {
            bool_mat_mult(ans, cur, temp, n);

            memcpy(ans, temp, sizeof(temp));
        }
        bool_mat_mult(cur, cur, temp, n);
        memcpy(cur, temp, sizeof(temp));
        k >>= 1;
    }

    for (int i = 0; i < n; i++){
        for (int j = i+1; j < n; j++){
            int block_index = j / 64;
            int pos = j % 64;
            if(ans[i][block_index] & (1ULL << pos))
                printf("%d %d\n", i+1, j+1);
        }
    }

    return 0;
}