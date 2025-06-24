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
        __typeof__((v).d) new_d = realloc((v).d, new_c * sizeof(*(v).d)); \
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
        __typeof__((q).d) new_d = malloc(new_c * sizeof(*(q).d)); \
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
        size_t cur->l = 2 * current + 1; \
        size_t cur->r = 2 * current + 2; \
        size_t smallest = current; \
        if (cur->l < (p).n && lt((p).d[cur->l], (p).d[smallest])) smallest = cur->l; \
        if (cur->r < (p).n && lt((p).d[cur->r], (p).d[smallest])) smallest = cur->r; \
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
    typedef struct name##_node { k key; v val; struct name##_node *cur->l, *cur->r; } name##_node; \
    typedef struct { name##_node *root; size_t size; } name; \
    static inline void name##_init(name *m) { m->root = NULL; m->size = 0; } \
    static inline name##_node* name##_new_node(k key, v val) { \
        name##_node* node = malloc(sizeof(name##_node)); \
        if (!node) { perror("malloc failed in " #name "_new_node"); exit(EXIT_FAILURE); } \
        node->key = key; node->val = val; node->cur->l = node->cur->r = NULL; \
        return node; \
    } \
    /* Recursive put helper */ \
    static inline name##_node* name##_put_recursive(name##_node* node, k key, v val, int* inserted) { \
        if (node == NULL) { \
            *inserted = 1; \
            return name##_new_node(key, val); \
        } \
        int c = cmp(key, node->key); \
        if (c < 0) node->cur->l = name##_put_recursive(node->cur->l, key, val, inserted); \
        else if (c > 0) node->cur->r = name##_put_recursive(node->cur->r, key, val, inserted); \
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
            n = c < 0 ? n->cur->l : n->cur->r; \
        } \
        return NULL; \
    } \
    /* Recursive free helper */ \
    static inline void name##_free_nodes(name##_node *n) { \
        if (n) { \
            name##_free_nodes(n->cur->l); \
            name##_free_nodes(n->cur->r); \
            free(n); \
        } \
    } \
    static inline void name##_free(name *m) { \
        name##_free_nodes(m->root); \
        m->root = NULL; m->size = 0; \
    } \
    static inline size_t name##_size(const name *m) { return m->size; } \
    static inline int name##_empty(const name *m) { return m->size == 0; }

    #define _FMT(x) _Generic(&(x), \
    long long*: "%lld", \
    int*:       "%d",   \
    double*:    "%lf",  \
    float*:     "%f",   \
    char*:      "%c",   \
    char**:     "%s"    \
)
#define vec_lower_bound(v, x, cmp)                                      \
    __extension__ ({                                                    \
        size_t __lo = 0, __hi = (v).n;                                  \
        while (__lo < __hi) {                                           \
            size_t __mid = __lo + ((__hi - __lo) >> 1);                 \
            if (cmp((v).d[__mid], (x)) < 0)                              \
                __lo = __mid + 1;                                       \
            else                                                        \
                __hi = __mid;                                           \
        }                                                               \
        __lo;                                                           \
    })
#define inp1(a1)                    scanf(_FMT(a1), &a1)
#define inp2(a1, a2)                inp1(a1); inp1(a2)
#define inp3(a1, a2, a3)            inp1(a1); inp1(a2); inp1(a3)
#define inp4(a1, a2, a3, a4)        inp1(a1); inp1(a2); inp1(a3); inp1(a4)
#define out1(a1)                    printf(_FMT(a1), (a1))
#define out2(a1, a2)                out1(a1); out1(a2)
#define out3(a1, a2, a3)            out1(a1); out1(a2); out1(a3)
#define out4(a1, a2, a3, a4)        out1(a1); out1(a2); out1(a3); out1(a4)
#define maxn 20005
#include <stdbool.h>
int a[maxn];
long long fenwick[maxn];  
struct query {
    int l, r, i;
};
struct query* newquery(int l, int r, int i) {
    struct query* a = malloc(sizeof (struct query));
    a->l = l;
    a->r = r;
    a->i = i;
    return a;
}
const int blocksize = 100;
bool cmp(const struct query *a, const struct query *b) {
    int ba = a->l / blocksize, bb = b->l / blocksize;
    if (ba != bb) return ba < bb;
    if (ba & 1)       return a->r > b->r;
    else              return a->r < b->r;
}
static int cmpsort(const void *pa, const void *pb) {
    const struct query *a = *(const struct query * const *)pa;
    const struct query *b = *(const struct query * const *)pb;
    if      (cmp(a,b))  return -1;
    else if (cmp(b,a))  return +1;
    else                return  0;
}
void update(int idx, long long val) {
    while (idx < maxn) {
        fenwick[idx] += val;
        idx += idx & -idx;
    }
}

long long query(int idx) {
    long long sum = 0;
    while (idx > 0) {
        sum += fenwick[idx];
        idx -= idx & -idx;
    }
    return sum;
}
int cmp_int1(int i, int j) {
    return i - j;
}
int cmp_int(const void* i, const void* j) {
    return *(const int*)i - *(const int*)j;
}
int ans = 0;
struct query **queries;
int *res;
int main() {
    int n, q;
    inp2(n, q);
    for(int i = 1; i <= n; i++) {
        inp1(a[i]);
    }
    vec(int) cmp;
    init(cmp);
    for(int i = 1; i <= n; i++) {
        push(cmp, a[i]);
    }
    sort_vec(cmp, cmp_int);
    for(int i = 1; i <= n; i++) {
        a[i] = vec_lower_bound(cmp, a[i], cmp_int1) + 1;
    }
    freev(cmp);
    queries = malloc(sizeof(struct query*) * q);
    for(int i = 0; i < q; i++) {
        int x, y;
        inp2(x, y);

        queries[i] = newquery(x, y, i);
    }
    qsort(queries, q, sizeof(struct query*), cmpsort);
    res = calloc(q, sizeof *res);
    int l = 1, r = 0;
    for(int i = 0; i < q; i++) {
        struct query* cur = queries[i];
        while(r < cur->r){
            r++;
            // count how many > a[r] are already in [l..r-1]
            ans += (query(maxn-1) - query(a[r]));
            update(a[r], +1);
        }
        // Shrink r from the right
        while(r > cur->r){
            // remove a[r]: subtract those greater than it
            ans -= (query(maxn-1) - query(a[r]));
            update(a[r], -1);
            r--;
        }
        // Extend l to the left
        while(l > cur->l){
            l--;
            // count how many < a[l] are already in [l+1..r]
            ans += query(a[l]-1);
            update(a[l], +1);
        }
        // Shrink l from the left
        while(l < cur->l){
            // remove a[l]: subtract those smaller than it
            ans -= query(a[l]-1);
            update(a[l], -1);
            l++;
        }
        res[cur->i] = ans;
    }
    for(int i = 0; i < q; i++) {
        out1(res[i]);
        putchar('\n');
    }
}