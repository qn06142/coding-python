#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_N 500010
#define INF 1000000000

typedef struct Node {
    int v;
    struct Node* next;
} Node;

Node* adj[MAX_N];
int dist[MAX_N];
int queue[MAX_N];
int front, rear;

void add_edge(int u, int v) {
    Node* node1 = (Node*)malloc(sizeof(Node));
    node1->v = v;
    node1->next = adj[u];
    adj[u] = node1;

    Node* node2 = (Node*)malloc(sizeof(Node));
    node2->v = u;
    node2->next = adj[v];
    adj[v] = node2;
}

void bfs(int *x, int b) {
    for (int i = 1; i <= MAX_N; i++) {
        dist[i] = INF;
    }

    front = rear = 0;
    for (int i = 0; i < b; i++) {
        int city = x[i];
        dist[city] = 0;
        queue[rear++] = city;
    }

    while (front < rear) {
        int u = queue[front++];
        for (Node* node = adj[u]; node; node = node->next) {
            int v = node->v;
            if (dist[v] == INF) {
                dist[v] = dist[u] + 1;
                queue[rear++] = v;
            }
        }
    }
}

int main() {
    int n, m, b, r;
    scanf("%d %d %d %d", &n, &m, &b, &r);

    int x[b], y[r];
    for (int i = 0; i < b; i++) {
        scanf("%d", &x[i]);
    }
    for (int i = 0; i < r; i++) {
        scanf("%d", &y[i]);
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        add_edge(u, v);
    }

    bfs(x, b);

    for (int i = 0; i < r; i++) {
        printf("%d ", dist[y[i]]);
    }
    printf("\n");

    return 0;
}
