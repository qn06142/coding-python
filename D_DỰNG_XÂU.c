#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHA 26
#define MOD 1000000007

#define _FMT(x) _Generic(&(x),        \
    int*:       "%d",                \
    long long*:"%lld",               \
    double*:    "%lf",               \
    float*:     "%f",                \
    char*:      "%s"                 \
)
#define inp1(a)  scanf(_FMT(a), (a))
#define inp2(a,b) inp1(a); inp1(b)
#define out1(a)  printf(_FMT(a), (a))

typedef struct Node {
    struct Node *nxt[ALPHA];
    int prefix_cnt;
    int is_word;
} Node;

static Node *newnode(void) {
    Node *n = malloc(sizeof *n);
    if (!n) { perror("malloc"); exit(1); }
    memset(n, 0, sizeof *n);
    return n;
}

void add_word(Node *root, const char *w) {
    Node *cur = root;
    cur->prefix_cnt++;
    for (int i = 0; w[i]; i++) {
        int c = w[i] - 'a';
        if (c < 0 || c >= ALPHA) continue;
        if (!cur->nxt[c])
            cur->nxt[c] = newnode();
        cur = cur->nxt[c];
        cur->prefix_cnt++;
    }
    cur->is_word = 1;
}

char *read_line(void) {
    size_t cap = 16, len = 0;
    char *buf = malloc(cap);
    int ch;
    if (!buf) exit(1);
    while ((ch = fgetc(stdin)) != EOF && ch != '\n') {
        if (len+1 >= cap) {
            cap *= 2;
            buf = realloc(buf, cap);
            if (!buf) exit(1);
        }
        buf[len++] = ch;
    }
    if (len==0 && ch==EOF) { free(buf); return NULL; }
    buf[len] = '\0';
    return buf;
}

int main(void) {
    Node *root = newnode();
    char *text = read_line();
    int n = strlen(text);

    int k;
    inp1(k);
    int c = getchar();
    if (c!='\n' && c!=EOF) ungetc(c, stdin);

    for (int i = 0; i < k; i++) {
        char *word = read_line();
        add_word(root, word);
        free(word);
    }

    int *dp = calloc(n+1, sizeof *dp);
    dp[0] = 1;

    for (int i = 0; i < n; i++) {
        if (!dp[i]) continue;
        long long ways = dp[i];
        Node *cur = root;
        for (int j = i; j < n; j++) {
            int c = text[j] - 'a';
            if (c<0||c>=ALPHA || !cur->nxt[c])
                break;
            cur = cur->nxt[c];
            if (cur->is_word) {
                dp[j+1] = (dp[j+1] + ways) % MOD;
            }
        }
    }

    printf("%d\n", dp[n]);
    return 0;
}
