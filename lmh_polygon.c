#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxn 100005

// Simple queue for vertices
typedef struct { int *d; size_t h, t, c; } queue;
static void q_init(queue *q) { q->h = q->t = 0; q->c = 4; q->d = malloc(q->c * sizeof *q->d); }
static void q_push(queue *q, int x) {
    if ((q->t + 1) % q->c == q->h) {
        size_t new_c = q->c * 2;
        int *new_d = malloc(new_c * sizeof *new_d);
        size_t sz = (q->t >= q->h) ? (q->t - q->h) : (q->c - q->h + q->t);
        for (size_t i = 0; i < sz; ++i) new_d[i] = q->d[(q->h + i) % q->c];
        free(q->d);
        q->d = new_d;
        q->c = new_c;
        q->h = 0;
        q->t = sz;
    }
    q->d[q->t] = x;
    q->t = (q->t + 1) % q->c;
}
static int  q_front(queue *q) { return q->d[q->h]; }
static void q_pop (queue *q) { q->h = (q->h + 1) % q->c; }
static int  q_empty(queue *q) { return q->h == q->t; }
static void q_free (queue *q) { free(q->d); }

// Map edge to color: use open addressing
static int edge_u[2 * (maxn * 2)], edge_v[2 * (maxn * 2)], edge_c[2 * (maxn * 2)];
static int edge_h[2 * (maxn * 2)];
static size_t edge_sz, edge_mod;
static void map_init(size_t cap) {
    edge_mod = cap;
    for (size_t i = 0; i < edge_mod; i++) edge_h[i] = -1;
}
static void map_set(int u, int v, int c) {
    if (u > v) { int t = u; u = v; v = t; }
    long long key = (long long)u * maxn + v;
    size_t h = (key ^ (key >> 20) ^ (key >> 40)) % edge_mod;
    for (int i = edge_h[h]; i != -1; i = edge_u[i]) {
        if (edge_v[i] == v && edge_u[i] == u) { edge_c[i] = c; return; }
    }
    edge_u[edge_sz] = u;
    edge_v[edge_sz] = v;
    edge_c[edge_sz] = c;
    edge_u[edge_sz + 1] = h>=0?edge_h[h]:0;
    edge_h[h] = edge_sz;
    edge_sz++;
}
static int map_get(int u, int v) {
    if (u > v) { int t = u; u = v; v = t; }
    long long key = (long long)u * maxn + v;
    size_t h = (key ^ (key >> 20) ^ (key >> 40)) % edge_mod;
    for (int i = edge_h[h]; i != -1; i = edge_u[i]) {
        if (edge_v[i] == v && edge_u[i] == u) return edge_c[i];
    }
    return 0;
}

// Vertex structure
typedef struct {
    int id, deg;
    int *adj;
    size_t adjs;
} vertex;
static vertex *verts[maxn];
static vertex *new_vert(int id) {
    vertex *v = malloc(sizeof *v);
    v->id = id; v->deg = 0; v->adjs = 0; v->adj = NULL;
    return v;
}
static void add_edge(vertex *v, int x) {
    v->adj = realloc(v->adj, (v->adjs + 1) * sizeof *v->adj);
    v->adj[v->adjs++] = x;
    v->deg++;
}
static void remove_edge(vertex *v, int x) {
    for (size_t i = 0; i < v->adjs; ++i) {
        if (v->adj[i] == x) {
            v->adj[i] = v->adj[--v->adjs];
            v->deg--;
            return;
        }
    }
}

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;
    map_init( (n + m)*2 + 1 );
    queue q;
    q_init(&q);
    for (int i = 1; i <= n; ++i) verts[i] = new_vert(i);
    for (int i = 0; i < n + m; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        add_edge(verts[u], v);
        add_edge(verts[v], u);
        map_set(u, v, 0);
    }
    for (int i = 1; i <= n; ++i) if (verts[i]->deg == 2) q_push(&q, i);

    // ear peeling
    while (!q_empty(&q)) {
        int u = q_front(&q);
        q_pop(&q);
        if (verts[u]->deg != 2) continue;
        int a = verts[u]->adj[0];
        int b = verts[u]->adj[1];
        if (map_get(u, a) == 0) map_set(u, a, 1);
        if (map_get(u, b) == 0) map_set(u, b, 1);
        if (map_get(a, b) == 0) {
            add_edge(verts[a], b);
            add_edge(verts[b], a);
            map_set(a, b, 2);
        }
        remove_edge(verts[a], u);
        remove_edge(verts[b], u);
        if (verts[a]->deg == 2) q_push(&q, a);
        if (verts[b]->deg == 2) q_push(&q, b);
    }

    // find smallest start
    int start = 1;
    while (verts[start]->deg == 0) ++start;

    int *order = malloc(n * sizeof *order);
    int cnt = 0;
    int prev = -1, cur = start;
    do {
        order[cnt++] = cur;
        int next = -1;
        for (size_t i = 0; i < verts[cur]->adjs; ++i) {
            int v = verts[cur]->adj[i];
            if (v == prev) continue;
            if (map_get(cur, v) == 1) { next = v; break; }
        }
        prev = cur;
        cur = next;
    } while (cur != start && cnt < n);

    // prepare reversed sequence
    int *rev = malloc(cnt * sizeof *rev);
    for (int i = 0; i < cnt; ++i) rev[i] = order[(cnt - i) % cnt];
    // lex compare
    int dir = 0;
    for (int i = 0; i < cnt; ++i) {
        if (order[i] < rev[i]) break;
        if (order[i] > rev[i]) { dir = 1; break; }
    }
    // output
    for (int i = 0; i < cnt; ++i) {
        int v = dir ? rev[i] : order[i];
        printf("%d%c", v, (i + 1 < cnt) ? ' ' : '\n');
    }

    return 0;
}
