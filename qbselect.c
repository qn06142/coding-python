#include <stdio.h>   // For perror (used in error checks)
#include <stdlib.h>  // For malloc, realloc, free, qsort, abs, labs, llabs
#include <string.h>  // For memset, memmove
#include <stddef.h>  // For size_t
#include <math.h>    // For abs, labs, llabs (can also be in stdlib.h C99+)

// --- Loops & Memory ---
#define rep0(i,n) for(int i=0; i<(n); ++i)
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define per(i,a,b) for(int i=(b)-1; i>=(a); --i)
#define mem(a,v) memset(a, v, sizeof(a))

// --- Min/Max (Type-safe using GCC/Clang statement expressions) ---
#define max(a,b) ({ __typeof__(a) _a = (a); __typeof__(b) _b = (b); _a > _b ? _a : _b; })
#define min(a,b) ({ __typeof__(a) _a = (a); __typeof__(b) _b = (b); _a < _b ? _a : _b; })
#define chmin(a,b) do { if ((b) < (a)) (a) = (b); } while(0)
#define chmax(a,b) do { if ((b) > (a)) (a) = (b); } while(0)

// --- Bit Manipulation (Using GCC/Clang builtins) ---
#define pc(x) __builtin_popcount(x)       // For unsigned int
#define pcl(x) __builtin_popcountl(x)     // For unsigned long
#define pcll(x) __builtin_popcountll(x)   // For unsigned long long
#define ctz(x) __builtin_ctz(x)           // For unsigned int
#define ctzl(x) __builtin_ctzl(x)         // For unsigned long
#define ctzll(x) __builtin_ctzll(x)       // For unsigned long long
// Note: Behavior is undefined if the input to ctz/ctzl/ctzll is 0.

// --- Math ---
// Greatest Common Divisor (GCD)
static inline long gcd(long a, long b) { a = labs(a); b = labs(b); while (b) { long t = a % b; a = b; b = t; } return a; }
static inline long long gcd_ll(long long a, long long b) { a = llabs(a); b = llabs(b); while (b) { long long t = a % b; a = b; b = t; } return a; }

// Least Common Multiple (LCM)
static inline long lcm(long a, long b) { if (a == 0 || b == 0) return 0; return (labs(a) / gcd(a, b)) * labs(b); }
static inline long long lcm_ll(long long a, long long b) { if (a == 0 || b == 0) return 0; return (llabs(a) / gcd_ll(a, b)) * llabs(b); }

// --- Sorting (qsort wrapper) ---
// Requires a comparison function `int cmp(const void* a, const void* b)`
#define sort_arr(a,n,cmp) qsort(a, n, sizeof(*(a)), cmp)
#define sort_vec(v,cmp) sort_arr((v).d, (v).n, cmp)

// --- Dynamic Array (Vector) ---
#define vec(t) struct{t*d; size_t n,c;} /* Using size_t for size/capacity */
#define init(v) do { (v).n = 0; (v).c = 4; (v).d = malloc((v).c * sizeof(*(v).d)); \
                    if (!(v).d) { perror("malloc failed in vec_init"); exit(EXIT_FAILURE); } } while (0)
#define push(v,x) do { \
    if ((v).n >= (v).c) { \
        size_t new_c = (v).c == 0 ? 4 : (v).c * 2; \
        t* new_d = realloc((v).d, new_c * sizeof(*(v).d)); \
        if (!new_d) { perror("realloc failed in vec_push"); exit(EXIT_FAILURE); } \
        (v).d = new_d; \
        (v).c = new_c; \
    } \
    (v).d[(v).n++] = (x); \
} while (0)
#define freev(v) do { free((v).d); (v).d = NULL; (v).n = (v).c = 0; } while (0)
#define vec_size(v) ((v).n)
#define vec_cap(v) ((v).c)
#define vec_get(v, i) ((v).d[i]) // No bounds check!
#define vec_back(v) ((v).d[(v).n-1]) // UB if empty!
#define vec_pop(v) do { if ((v).n > 0) (v).n--; } while(0) // Simple pop

// --- Queue (FIFO) ---
#define queue(t) struct{t*d; size_t h, t_, c;} /* Using size_t */
#define q_init(q) do { (q).h = (q).t_ = 0; (q).c = 4; (q).d = malloc((q).c * sizeof(*(q).d)); \
                     if (!(q).d) { perror("malloc failed in q_init"); exit(EXIT_FAILURE); } } while (0)
#define q_push(q,x) do { \
    if (((q).t_ + 1) % (q).c == (q).h) { /* Check if full (using modulo arithmetic for wrap around) */ \
        size_t new_c = (q).c == 0 ? 4 : (q).c * 2; \
        t* new_d = malloc(new_c * sizeof(*(q).d)); \
        if (!new_d) { perror("malloc failed in q_push resize"); exit(EXIT_FAILURE); } \
        size_t current_size = ((q).t_ >= (q).h) ? (q).t_ - (q).h : (q).c - (q).h + (q).t_; \
        size_t k = 0; \
        for (size_t i = 0; i < current_size; ++i) { \
            new_d[k++] = (q).d[((q).h + i) % (q).c]; \
        } \
        free((q).d); \
        (q).d = new_d; \
        (q).h = 0; \
        (q).t_ = current_size; \
        (q).c = new_c; \
    } \
    (q).d[(q).t_] = (x); \
    (q).t_ = ((q).t_ + 1) % (q).c; \
} while (0)
#define q_pop(q) ((q).h = ((q).h + 1) % (q).c) /* Does not return value; use q_front first. UB if empty! */
#define q_front(q) ((q).d[(q).h]) /* UB if empty! */
#define q_empty(q) ((q).h == (q).t_)
#define q_size(q) (((q).t_ >= (q).h) ? ((q).t_ - (q).h) : ((q).c - (q).h + (q).t_))
#define q_free(q) do { free((q).d); (q).d = NULL; (q).h = (q).t_ = (q).c = 0; } while (0)


// --- Priority Queue (Min-Heap) ---
// Requires a less-than comparison function or macro `lt(a, b)` returning non-zero if a < b
#define pqueue(t) struct{t*d; size_t n, c;} /* Using size_t */
#define pq_init(p) do { (p).n = 0; (p).c = 4; (p).d = malloc((p).c * sizeof(*(p).d)); \
                      if (!(p).d) { perror("malloc failed in pq_init"); exit(EXIT_FAILURE); } } while (0)
// Internal helper: Sift up element at index `i`
#define _pq_sift_up(p, i, lt) do { \
    size_t current = i; \
    while (current > 0) { \
        size_t parent = (current - 1) / 2; \
        if (lt((p).d[current], (p).d[parent])) { \
            t temp = (p).d[current]; (p).d[current] = (p).d[parent]; (p).d[parent] = temp; \
            current = parent; \
        } else { break; } \
    } \
} while (0)
// Internal helper: Sift down element at index `i`
#define _pq_sift_down(p, i, lt) do { \
    size_t current = i; \
    while (1) { \
        size_t l = 2 * current + 1; \
        size_t r = 2 * current + 2; \
        size_t smallest = current; \
        if (l < (p).n && lt((p).d[l], (p).d[smallest])) smallest = l; \
        if (r < (p).n && lt((p).d[r], (p).d[smallest])) smallest = r; \
        if (smallest != current) { \
            t temp = (p).d[current]; (p).d[current] = (p).d[smallest]; (p).d[smallest] = temp; \
            current = smallest; \
        } else { break; } \
    } \
} while (0)
#define pq_push(p, x, lt) do { \
    if ((p).n >= (p).c) { \
        size_t new_c = (p).c == 0 ? 4 : (p).c * 2; \
        t* new_d = realloc((p).d, new_c * sizeof(*(p).d)); \
        if (!new_d) { perror("realloc failed in pq_push"); exit(EXIT_FAILURE); } \
        (p).d = new_d; \
        (p).c = new_c; \
    } \
    (p).d[(p).n] = (x); \
    _pq_sift_up(p, (p).n, lt); \
    (p).n++; \
} while (0)
#define pq_top(p) ((p).d[0]) /* UB if empty! */
#define pq_pop(p, lt) do { \
    if ((p).n > 0) { \
        (p).n--; \
        if ((p).n > 0) { /* Only sift down if heap is not empty after decrementing n */ \
           (p).d[0] = (p).d[(p).n]; \
           _pq_sift_down(p, 0, lt); \
        } \
    } \
} while(0)
#define pq_empty(p) (!(p).n)
#define pq_size(p) ((p).n)
#define pq_free(p) do { free((p).d); (p).d = NULL; (p).n = (p).c = 0; } while (0)

// --- Map (Basic Unbalanced Binary Search Tree) ---
// Requires a comparison function 'cmp(k1, k2)' returning <0, 0, or >0.
#define MAP(name, k, v, cmp) \
    typedef struct name##_node { k key; v val; struct name##_node *l, *r; } name##_node; \
    typedef struct { name##_node *root; size_t size; } name; \
    static inline void name##_init(name *m) { m->root = NULL; m->size = 0; } \
    static inline name##_node* name##_new_node(k key, v val) { \
        name##_node* node = malloc(sizeof(name##_node)); \
        if (!node) { perror("malloc failed in " #name "_new_node"); exit(EXIT_FAILURE); } \
        node->key = key; node->val = val; node->l = node->r = NULL; \
        return node; \
    } \
    /* Recursive put helper */ \
    static inline name##_node* name##_put_recursive(name##_node* node, k key, v val, int* inserted) { \
        if (node == NULL) { \
            *inserted = 1; \
            return name##_new_node(key, val); \
        } \
        int c = cmp(key, node->key); \
        if (c < 0) node->l = name##_put_recursive(node->l, key, val, inserted); \
        else if (c > 0) node->r = name##_put_recursive(node->r, key, val, inserted); \
        else { node->val = val; *inserted = 0; } /* Update existing key */ \
        return node; /* No balancing in this basic version */ \
    } \
    static inline void name##_put(name *m, k key, v val) { \
        int inserted = 0; \
        m->root = name##_put_recursive(m->root, key, val, &inserted); \
        if (inserted) m->size++; \
    } \
    static inline v* name##_get(name *m, k key) { /* Iterative get */ \
        name##_node *n = m->root; \
        while (n) { \
            int c = cmp(key, n->key); \
            if (c == 0) return &n->val; \
            n = c < 0 ? n->l : n->r; \
        } \
        return NULL; \
    } \
    /* Recursive free helper */ \
    static inline void name##_free_nodes(name##_node *n) { \
        if (n) { \
            name##_free_nodes(n->l); \
            name##_free_nodes(n->r); \
            free(n); \
        } \
    } \
    static inline void name##_free(name *m) { \
        name##_free_nodes(m->root); \
        m->root = NULL; m->size = 0; \
    } \
    static inline size_t name##_size(const name *m) { return m->size; } \
    static inline int name##_empty(const name *m) { return m->size == 0; }


#define _FMT(x) _Generic((x),               \
    long long:    "%lld",                   \
    int:          "%d",                     \
    double:       "%f",                     \
    float:        "%f",                     \
    char:         "%c",                     \
    char *:       "%s",                     \
    const char *: "%s",                     \
    default:      "%s"                      \
)
#pragma GCC optimize("trapv")
#include <stdbool.h>
#define inp1(a1)                    scanf(_FMT(a1), &a1)
#define inp2(a1, a2)                inp1(a1); inp1(a2)
#define inp3(a1, a2, a3)            inp1(a1); inp1(a2); inp1(a3)
#define inp4(a1, a2, a3, a4)        inp1(a1); inp1(a2); inp1(a3); inp1(a4)
#define out1(a1)                    printf(_FMT(a1), (a1))
#define out2(a1, a2)                out1(a1); out1(a2)
#define out3(a1, a2, a3)            out1(a1); out1(a2); out1(a3)
#define out4(a1, a2, a3, a4)        out1(a1); out1(a2); out1(a3); out1(a4)
#define maxn 10005
int a[5][maxn];
static inline bool valid_mask(int m) {
    return (m & (m << 1)) == 0;
}
static inline bool check(int m1, int m2) {
    return (m1 & m2) == 0
        && valid_mask(m1)
        && valid_mask(m2);
}
static inline int calc(int m, int idx) {
    int ans = 0;
    for (int i = 0; i < 4; i++) {
        if (m & (1 << i)) {
            ans += a[i][idx];
        }
    }
    return ans;
}

int dp[maxn][16];
int main() {
    int n;
    inp1(n);
    for(int i = 0; i < 4; i++) {
        for(int j = 1; j <= n; j++) {
            inp1(a[i][j]);
        }
    }
    // for (int m = 0; m < 16; m++) {
        // if(valid_mask(m))
        // dp[1][m] = calc;
    // }

    for(int i = 2; i <= n; i++) {
        for(int m1 = 0; m1 < 16; m1++) {
            for(int m2 = 0; m2 < 16; m2++) {
                if(check(m1, m2)) {
                    dp[i][m1] = max(dp[i][m1], dp[i - 1][m2] + calc(m2, i));
                }
            }
            //out1(dp[i][m1]);
            //putchar(' ');
        }
        //putchar('\n');

    }
    int answer = -0x3f3f3f3f;
    for (int i = 1; i <= n; ++i) {
    	for (int m1 = 1; m1 < 16; ++m1) {
    		int cost = 0;
    		for (int j = 0; j < 4; ++j) {
    			if (m1 >> j & 1) {
    				cost += a[j][i];
    			}
    		}
    		if (valid_mask(m1)) {
    			answer = max(answer, dp[i - 1][m1] + cost);
    		}
    	}
    }
    out1(answer);
}