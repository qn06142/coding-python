#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long ull;

typedef struct {
    ull weight;
    ull value;
} subset_t;

int compare_subsets(const void *a, const void *b) {
    subset_t *sa = (subset_t *)a;
    subset_t *sb = (subset_t *)b;
    if (sa->weight < sb->weight)
        return -1;
    else if (sa->weight > sb->weight)
        return 1;
    else
        return 0;
}

int gen_subsets(subset_t *subsets, int size, subset_t *group) {
    int total = 1 << size; 
    for (int mask = 0; mask < total; mask++) {
        ull sum_weight = 0, sum_value = 0;
        for (int i = 0; i < size; i++) {
            if (mask & (1 << i)) {
                sum_weight += group[i].weight;
                sum_value += group[i].value;
            }
        }
        subsets[mask].weight = sum_weight;
        subsets[mask].value = sum_value;
    }
    return total;
}

ull binary_search(subset_t *subs, int subs_count, ull limit_weight) {
    int low = 0, high = subs_count - 1, mid, ans = -1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (subs[mid].weight <= limit_weight) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    if (ans == -1)
        return 0;
    return subs[ans].value;
}

int main() {

    int n;
    ull m;
    if (fscanf(stdin, "%d %llu", &n, &m) != 2) {
        fclose(stdin);
        return 1;
    }

    subset_t *items = (subset_t *)malloc(n * sizeof(subset_t));
    if (items == NULL) {
        fclose(stdin);
        return 1;
    }

    for (int i = 0; i < n; i++) {
        if (fscanf(stdin, "%llu %llu", &items[i].weight, &items[i].value) != 2) {
            free(items);
            fclose(stdin);
            return 1;
        }
    }

    int n1 = n / 2;
    int n2 = n - n1;

    subset_t *group1 = items;        
    subset_t *group2 = items + n1;     

    int total_1 = 1 << n1;
    int total_2 = 1 << n2;

    subset_t *subsets_1 = (subset_t *)malloc(total_1 * sizeof(subset_t));
    subset_t *subsets_2 = (subset_t *)malloc(total_2 * sizeof(subset_t));

    gen_subsets(subsets_1, n1, group1);
    gen_subsets(subsets_2, n2, group2);

    qsort(subsets_1, total_1, sizeof(subset_t), compare_subsets);

    int compressed_count = 0;
    for (int i = 0; i < total_1; i++) {
        if (compressed_count == 0 || subsets_1[i].value > subsets_1[compressed_count - 1].value) {
            subsets_1[compressed_count++] = subsets_1[i];
        }
    }

    ull best_value = 0;
    for (int i = 0; i < total_2; i++) {
        if (subsets_2[i].weight <= m) {
            ull remaining = m - subsets_2[i].weight;
            ull val = subsets_2[i].value + binary_search(subsets_1, compressed_count, remaining);
            if (val > best_value)
                best_value = val;
        }
    }
    fprintf(stdout, "%llu", best_value);
    fclose(stdout);
}