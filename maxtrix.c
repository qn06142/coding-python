#include <stdio.h>
#include <string.h>

#define MAX_N 410
#define MAX_M 410

unsigned long long rowBits[MAX_N][7];
char grid[MAX_N][MAX_M];
int n, m;

int main(){
    int i, j, k, seg;
    scanf("%d %d", &n, &m);

    int segCount = (m + 63) / 64;

    for(i = 0; i < n; i++){
        scanf("%s", grid[i]);
        for(seg = 0; seg < segCount; seg++){
            rowBits[i][seg] = 0ULL;
        }
        for(j = 0; j < m; j++){
            if(grid[i][j] == '1'){
                int pos = j / 64;
                int bit = j % 64;
                rowBits[i][pos] |= (1ULL << bit);
            }
        }
    }

    long long ans = 0;

    for(i = 0; i < n; i++){
        for(j = i + 1; j < n; j++){
            int height = j - i + 1;
            int p = height / 2;  

            unsigned long long combined[7];
            for(seg = 0; seg < segCount; seg++){
                if(seg == segCount - 1 && (m % 64) != 0)
                    combined[seg] = (1ULL << (m % 64)) - 1;
                else
                    combined[seg] = ~0ULL;
            }

            for(k = 0; k < p; k++){
                for(seg = 0; seg < segCount; seg++){
                    unsigned long long eq = ~( rowBits[i+k][seg] ^ rowBits[j-k][seg] );
                    combined[seg] &= eq;
                }
            }

            int cnt = 0;
            for(int col = 0; col < m; col++){
                seg = col / 64;
                int bit = col % 64;
                int valid = (combined[seg] >> bit) & 1ULL;
                if(valid)
                    cnt++;
                else {
                    ans += (long long)cnt * (cnt + 1) / 2;
                    cnt = 0;
                }
            }
            ans += (long long)cnt * (cnt + 1) / 2;
        }
    }

    printf("%lld\n", ans);
    return 0;
}