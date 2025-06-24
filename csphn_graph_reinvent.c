#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define maxn 100005
#define INF 1000000000

typedef struct {
    int *items;
    int front;
    int rear;
    int capacity;
    int size;
} queue_t;

queue_t* create_queue(int capacity) {
    queue_t* queue = malloc(sizeof(*queue));
    if (!queue) return NULL;
    queue->capacity = capacity;
    queue->front = 0;
    queue->rear = -1;
    queue->size = 0;
    queue->items = malloc(capacity * sizeof *queue->items);
    if (!queue->items) {
        free(queue);
        return NULL;
    }
    return queue;
}

bool is_full(queue_t* queue) {
    return queue->size == queue->capacity;
}

bool is_empty(queue_t* queue) {
    return queue->size == 0;
}

bool push(queue_t* queue, int item) {
    if (is_full(queue)) return false;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->items[queue->rear] = item;
    queue->size++;
    return true;
}

int pop(queue_t* queue) {
    if (is_empty(queue)) return -1;
    int item = queue->items[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return item;
}

int front(queue_t* queue) {
    if (is_empty(queue)) return -1;
    return queue->items[queue->front];
}

int rear(queue_t* queue) {
    if (is_empty(queue)) return -1;
    return queue->items[queue->rear];
}

void free_queue(queue_t* queue) {
    if (queue) {
        free(queue->items);
        free(queue);
    }
}

int zone[maxn];
int visited[maxn];
int source[maxn];
int** adj;
int* adj_size;
int n, m, x;

void pushedge(int u, int v) {
    adj[u] = realloc(adj[u], (adj_size[u] + 1) * sizeof(int));
    adj[u][adj_size[u]++] = v;
}

#define MIN(a, b) ({ __typeof__(a) _a = (a); __typeof__(b) _b = (b); _a < _b ? _a : _b; })

int main() {
    scanf("%d %d %d", &n, &m, &x);
    adj = calloc(n + 1, sizeof(int*));
    adj_size = calloc(n + 1, sizeof(int));
    for (int i = 1; i <= n; i++) {
        visited[i] = -1;
        source[i] = 0;
    }
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        pushedge(u, v);
    }
    for (int i = 1; i <= x; i++) {
        scanf("%d", &zone[i]);
    }
    queue_t* q = create_queue(n + 1);
    for (int i = 1; i <= x; i++) {
        int house = zone[i];
        if (house >= 1 && house <= n) {
            visited[house] = 0;
            source[house] = house;
            push(q, house);
        }
    }
    int ans = INF;
    while (!is_empty(q)) {
        int t = pop(q);
        for (int i = 0; i < adj_size[t]; i++) {
            int v = adj[t][i];
            if (visited[v] == -1) {
                visited[v] = visited[t] + 1;
                source[v] = source[t];
                push(q, v);
            } else if (source[t] != source[v]) {
                ans = MIN(ans, visited[t] + visited[v] + 1);
            }
        }
    }
    if (ans == INF) ans = -1;
    printf("%d\n", ans);
}
