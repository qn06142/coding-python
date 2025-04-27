#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define MAX_COWS 100
#define MAX_MACHINES 20

typedef struct {
    int l, r, req;
} Cow;

typedef struct {
    int l, r, d, cost;
} Machine;

int C, M;
Cow cows[MAX_COWS];
Machine mac[MAX_MACHINES];
bool used[MAX_MACHINES];  
int best = INT_MAX;

bool check() {

    for (int i = 0; i < C; i++) {
        int l = cows[i].l;
        int r = cows[i].r;
        int req = cows[i].req;

        for (int room = l; room <= r; room++) {
            int cooling = 0;

            for (int j = 0; j < M; j++) {
                if (used[j]) {
                    if (mac[j].l <= room && room <= mac[j].r) {
                        cooling += mac[j].d;
                    }
                }
            }

            if (cooling < req) {
                return false;
            }
        }
    }
    return true;
}

void backtracc(int idx, int curcost) {

    if (curcost >= best) {
        return;
    }

    if (idx == M) {
        if (check()) {
            if (curcost < best)
                best = curcost;
        }
        return;
    }

    used[idx] = false;
    backtracc(idx + 1, curcost);

    used[idx] = true;
    backtracc(idx + 1, curcost + mac[idx].cost);

}

int main() {

    if (scanf("%d %d", &C, &M) != 2) return 1;

    for (int i = 0; i < C; i++) {
        if (scanf("%d %d %d", &cows[i].l, &cows[i].r, &cows[i].req) != 3) return 1;
    }

    for (int i = 0; i < M; i++) {
        if (scanf("%d %d %d %d", &mac[i].l, &mac[i].r, &mac[i].d, &mac[i].cost) != 4) return 1;
    }

    backtracc(0, 0);

    printf("%d\n", best);
    return 0;
}