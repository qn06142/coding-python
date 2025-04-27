#pragma GCC optimize("O3")
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_CAPACITY 50

typedef struct {
    int x, y;
} point;
#define max(a,b) \
  ({ __typeof__ (a) _a = (a); \
    __typeof__ (b) _b = (b); \
    _a > _b ? _a : _b; })
int n;               
int max_color = 0;   

int **fw;
int **bw;
int *mc;
int *ans;

int *fenw_lis;
int *fenw_lds;

point **color_coords;   
int *coord_size;        
int *coord_capacity;    

void push_coord(int color, point pt) {
    if (coord_size[color] == coord_capacity[color]) {
        int new_capacity = (coord_capacity[color] == 0) ? INITIAL_CAPACITY : coord_capacity[color] * 2;
        point *new_array = realloc(color_coords[color], new_capacity * sizeof(point));
        if (!new_array) {
            fprintf(stderr, "Memory allocation failed\n");
            exit(1);
        }
        color_coords[color] = new_array;
        coord_capacity[color] = new_capacity;
    }
    mc[color] = max(mc[color], pt.y);
    color_coords[color][coord_size[color]++] = pt;
}

int fenw_query_lis(int *fenw, int pos) {
    int res = 0;
    while (pos > 0) {
        if (fenw[pos] > res)
            res = fenw[pos];
        pos -= pos & -pos;
    }
    return res;
}

void fenw_update_lis(int *fenw, int pos, int val, int size) {
    while (pos < size) {
        if (fenw[pos] < val)
            fenw[pos] = val;
        pos += pos & -pos;
    }
}

int fenw_query_lds(int *fenw, int pos, int size) {
    int res = 0;
    while (pos < size) {
        if (fenw[pos] > res)
            res = fenw[pos];
        pos += pos & -pos;
    }
    return res;
}

void fenw_update_lds(int *fenw, int pos, int val) {
    while (pos > 0) {
        if (fenw[pos] < val)
            fenw[pos] = val;
        pos -= pos & -pos;
    }
}

void lis_func(int color) {

    memset(fenw_lis, 0, (mc[color] + 5) * sizeof(int));
    int m = coord_size[color];  
    for (int i = 1; i < m; i++) {
        int pos = color_coords[color][i].y;
        int dp = fenw_query_lis(fenw_lis, pos) + 1;
        int x = color_coords[color][i].x;
        int y = color_coords[color][i].y;
        fw[x][y] = dp;
        fenw_update_lis(fenw_lis, pos, dp, n + 5);
    }
}

void lds_func(int color) {
    memset(fenw_lds, 0, (mc[color] + 5) * sizeof(int));
    int m = coord_size[color];
    for (int i = m - 1; i >= 1; i--) {
        int pos = color_coords[color][i].y;
        int dp = fenw_query_lds(fenw_lds, pos, mc[color] + 5) + 1;
        int x = color_coords[color][i].x;
        int y = color_coords[color][i].y;
        bw[x][y] = dp;
        fenw_update_lds(fenw_lds, pos, dp);
    }
}

int main(void) {
    if (scanf("%d", &n) != 1)
        return 1;

    fw = malloc((n + 1) * sizeof(int *));
    bw = malloc((n + 1) * sizeof(int *));
    for (int i = 0; i <= n; i++) {
        fw[i] = calloc(n + 1, sizeof(int));
        bw[i] = calloc(n + 1, sizeof(int));
    }

    ans = calloc(2 * n, sizeof(int));

    fenw_lis = calloc(n + 5, sizeof(int));
    fenw_lds = calloc(n + 5, sizeof(int));

    int total_cells = n * n;
    int *grid_colors = calloc(total_cells, sizeof(int));
    int idx = 0, color;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (scanf("%d", &color) != 1)
                break;
            grid_colors[idx++] = color;
            if (color > max_color)
                max_color = color;
        }
    }

    mc = calloc((max_color + 1), sizeof(int));
    color_coords = malloc((max_color + 1) * sizeof(point *));
    coord_size = malloc((max_color + 1) * sizeof(int));
    coord_capacity = malloc((max_color + 1) * sizeof(int));
    for (int i = 0; i <= max_color; i++) {
        color_coords[i] = NULL;
        coord_size[i] = 0;
        coord_capacity[i] = 0;
    }

    idx = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            color = grid_colors[idx++];
            if (coord_size[color] == 0) {

                push_coord(color, (point){0, 0});
            }
            push_coord(color, (point){i, j});
        }
    }
    free(grid_colors);

    for (color = 1; color <= max_color; color++) {
        if (coord_size[color] > 0) {
            lis_func(color);
            lds_func(color);
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int sum = fw[i][j] + bw[i][j] - 1;
            if (sum < 2 * n)
                ans[sum]++;
        }
    }

    for (int i = 1; i < 2 * n; i++) {
        printf("%d\n", ans[i]);
    }
    return 0;
}