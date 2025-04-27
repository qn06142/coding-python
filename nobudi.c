#include <stdio.h>
#include <stdlib.h>

struct subset_key {
    int key[6];
};

int compare_subset(const void *a, const void *b) {
    const struct subset_key *pa = (const struct subset_key *)a;
    const struct subset_key *pb = (const struct subset_key *)b;
    for (int i = 0; i < 6; i++) {
        if (pa->key[i] != pb->key[i])
            return pa->key[i] - pb->key[i];
    }
    return 0;
}

int main(void)
{
    int n;
    if (scanf("%d", &n) != 1) {
        fprintf(stderr, "failed to read number of cows\n");
        return 1;
    }

    int total_keys = n * 31;
    struct subset_key *keys = malloc(total_keys * sizeof(struct subset_key));
    if (keys == NULL) {
        fprintf(stderr, "memory allocation failed\n");
        return 1;
    }
    int key_count = 0;

    int probs[5];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 5; j++) {
            if (scanf("%d", &probs[j]) != 1) {
                fprintf(stderr, "error reading problem numbers\n");
                free(keys);
                return 1;
            }
        }

        for (int j = 1; j < 5; j++) {
            int tmp = probs[j];
            int k = j - 1;
            while (k >= 0 && probs[k] > tmp) {
                probs[k + 1] = probs[k];
                k--;
            }
            probs[k + 1] = tmp;
        }

        for (int mask = 1; mask < (1 << 5); mask++) {

            keys[key_count].key[0] = 0;
            for (int pos = 0; pos < 5; pos++) {
                if (mask & (1 << pos)) {
                    keys[key_count].key[0]++; 
                    keys[key_count].key[keys[key_count].key[0]] = probs[pos];
                }
            }
            key_count++;
        }
    }

    qsort(keys, key_count, sizeof(struct subset_key), compare_subset);

    long long res = 0;
    for (int i = 0; i < key_count; ) {
        int count = 1;
        while (i + count < key_count && compare_subset(&keys[i], &keys[i + count]) == 0) {
            count++;
        }
        if (count >= 2) {
            int subset_size = keys[i].key[0];
            long long pairs = (long long)count * (count - 1) / 2;
            int sign = (subset_size % 2 == 1) ? 1 : -1;
            res += sign * pairs;
        }
        i += count;
    }

    long long total_pairs = (long long)n * (n - 1) / 2;
    long long answer = total_pairs - res;
    printf("%lld\n", answer);

    free(keys);
    return 0;
}