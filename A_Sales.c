#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct triplet {
    int a, b, c;
    char choices[100]; // Assuming a maximum size for choices


};
void add(int vals[3], char c1, char c2) {
    if (c1 == 'L') a += vals[0];
    else if (c1 == 'M') b += vals[1];
    else c += vals[2];
    if (c2 == 'L') a += vals[0];
    else if (c2 == 'M') b += vals[1];
    else c += vals[2];
    size_t len = strlen(choices);
    choices[len] = c1;
    choices[len + 1] = c2;
    choices[len + 2] = '\0';
}
int arr[100][3]; // Assuming a maximum size for arr
struct triplet L[100], R[100]; // Assuming a maximum size for L and R
int L_size = 0, R_size = 0;

void backtrack(int idx, int end, struct triplet cur) {
    if (idx > end) {
        L[L_size++] = cur;
        return;
    }
    for (char c1 = 'L'; c1 <= 'W'; c1++) {
        for (char c2 = 'L'; c2 <= 'W'; c2++) {
            if (c1 < c2) {
                struct triplet nxt = cur;
                nxt.add(arr[idx], c1, c2);
                backtrack(idx + 1, end, nxt);
            }
        }
    }
}

struct pair {
    int first, second;
};



struct map_entry {
    struct pair key;
    int* values;
    size_t size;
};

struct map {
    struct map_entry* entries;
    size_t capacity;
    size_t size;
};

void map_init(struct map* m, size_t capacity) {
    m->entries = (struct map_entry*)malloc(capacity * sizeof(struct map_entry));
    m->capacity = capacity;
    m->size = 0;
}

void map_insert(struct map* m, struct pair key, int value) {
    for (size_t i = 0; i < m->size; i++) {
        if (m->entries[i].key.first == key.first && m->entries[i].key.second == key.second) {
            m->entries[i].values = (int*)realloc(m->entries[i].values, (m->entries[i].size + 1) * sizeof(int));
            m->entries[i].values[m->entries[i].size++] = value;
            return;
        }
    }
    m->entries[m->size].key = key;
    m->entries[m->size].values = (int*)malloc(sizeof(int));
    m->entries[m->size].values[0] = value;
    m->entries[m->size].size = 1;
    m->size++;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d %d", &arr[i][0], &arr[i][1], &arr[i][2]);
    }
    int mid = n / 2;
    backtrack(1, mid, (struct triplet){0, 0, 0, ""});
    backtrack(mid + 1, n, (struct triplet){0, 0, 0, ""});
    
    struct map mp;
    map_init(&mp, R_size);
    for (int i = 0; i < R_size; i++) {
        struct triplet t = R[i];
        struct pair key = {t.a - t.b, t.a - t.c};
        map_insert(&mp, key, i);
    }

    long long best_sum = -1;
    char best_choices[200] = ""; // Assuming a maximum size for best_choices

    for (size_t i = 0; i < L_size; i++) {
        struct triplet lt = L[i];
        struct pair key = {lt.b - lt.a, lt.c - lt.a};
        for (size_t j = 0; j < mp.size; j++) {
            if (mp.entries[j].key.first == key.first && mp.entries[j].key.second == key.second) {
                for (size_t k = 0; k < mp.entries[j].size; k++) {
                    int ri = mp.entries[j].values[k];
                    struct triplet rt = R[ri];

                    long long common = (long long)lt.a + rt.a;

                    if (common > best_sum) {
                        best_sum = common;
                        strcpy(best_choices, lt.choices);
                        strcat(best_choices, rt.choices);
                    }
                }
            }
        }
    }

    if (best_sum < 0) {
        printf("Impossible");
    } else {
        for (size_t i = 0; i + 1 < strlen(best_choices); i += 2) {
            printf("%c%c\n", best_choices[i], best_choices[i + 1]);
        }
        printf("\n");
    }

    // Free allocated memory
    for (size_t i = 0; i < mp.size; i++) {
        free(mp.entries[i].values);
    }
    free(mp.entries);

    return 0;
}