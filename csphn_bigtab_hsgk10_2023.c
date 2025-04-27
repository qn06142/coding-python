#include <stdio.h>

#define MAX 1000

int m, n;
int grid[MAX][MAX];
int height[MAX];
int stack[MAX];
int values[MAX * MAX];
int unique_values[MAX * MAX];
int unique_count = 0;

int max(int a, int b) {
    return a > b ? a : b;
}

int largest_rectangle(int *height, int len) {
    int max_area = 0;
    int top = -1;

    for (int i = 0; i <= len; ++i) {
        int h = (i < len) ? height[i] : 0;
        while (top >= 0 && height[stack[top]] >= h) {
            int height_idx = stack[top--];
            int width = (top == -1) ? i : i - stack[top] - 1;
            int area = height[height_idx] * width;
            if (area > max_area)
                max_area = area;
        }
        stack[++top] = i;
    }
    return max_area;
}

int is_new_value(int val) {
    for (int i = 0; i < unique_count; ++i) {
        if (unique_values[i] == val)
            return 0;
    }
    return 1;
}

int solve_for_value(int val) {
    int max_area = 0;
    for (int i = 0; i < n; ++i)
        height[i] = 0;

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == val)
                height[j]++;
            else
                height[j] = 0;
        }
        int area = largest_rectangle(height, n);
        if (area > max_area)
            max_area = area;
    }
    return max_area;
}

int main() {
    scanf("%d %d", &m, &n);

    int total = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &grid[i][j]);
            int val = grid[i][j];
            if (is_new_value(val)) {
                unique_values[unique_count++] = val;
            }
        }
    }

    int result = 0;
    for (int i = 0; i < unique_count; ++i) {
        int area = solve_for_value(unique_values[i]);
        if (area > result)
            result = area;
    }

    printf("%d\n", result);
    return 0;
}
