#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
typedef struct Node {
    int x, y, w;
} Node;

typedef struct queue {
    Node *data;
    int front, rear, size, capacity;
} queue_t;

queue_t *create_queue(int capacity) {
    queue_t *q = (queue_t *)malloc(sizeof(queue_t));
    if (!q) {
        perror("os what the fuck");
        exit(EXIT_FAILURE);
    }
    q->capacity = capacity;
    q->size = 0;
    q->front = 0;
    q->rear = -1;
    q->data = (Node *)malloc(capacity * sizeof(Node));
    if (!q->data) {
        perror("os what the fuck");
        exit(EXIT_FAILURE);
    }
    return q;
}

int is_empty(queue_t *q) {
    return q->size == 0;
}

int is_full(queue_t *q) {
    return q->size == q->capacity;
}

void enqueue(queue_t *q, int x, int y, int w) {
    if (is_full(q)) {
        fprintf(stderr, "help im full");
        exit(EXIT_FAILURE);
    }
    q->rear = (q->rear + 1) % q->capacity;
    q->data[q->rear] = (Node){x, y, w};
    q->size++;
}

Node dequeue(queue_t *q) {
    if (is_empty(q)) {
        fprintf(stderr, "skill issue bro");
        exit(EXIT_FAILURE);
    }
    Node value = q->data[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size--;
    return value;
}

void free_queue(queue_t *q) {
    free(q->data);
    free(q);
}

void print_queue(queue_t *q) {
    if (is_empty(q)) {
        printf("are you dumb?");
        return;
    }
    printf("Queue:\n");
    for (int i = 0; i < q->size; i++) {
        int index = (q->front + i) % q->capacity;
        printf("(%d, %d, %d) ", q->data[index].x, q->data[index].y, q->data[index].w);
    }
    printf("\n");
}
int** mat;
int** dis;
int n, m;

int bfs() {
    queue_t* q = create_queue(n * m);

    enqueue(q, 1, 1, mat[1][1]);

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    while(!is_empty(q)) {
        Node cur = dequeue(q);

        if(dis[cur.x][cur.y] <= cur.w) continue;
        dis[cur.x][cur.y] = cur.w;
        for (int i = 0; i < 4; i++) {
            int nx = cur.x + dx[i], ny = cur.y + dy[i];
            if (nx >= 1 && nx <= m && ny >= 1 && ny <= n) {
                int new_cost = cur.w + mat[nx][ny];
                if(new_cost < dis[nx][ny]) {
                    enqueue(q, nx, ny, new_cost);
                }
            }
        }
    }
    free_queue(q);
    return dis[m][n];
}

int main() {
    scanf("%d %d", &m, &n);

    mat = (int**)malloc((m+1) * sizeof(int*));
    dis = (int**)malloc((m+1) * sizeof(int*));
    for (int i = 1; i <= m; i++) {
        mat[i] = (int*)malloc((n+1) * sizeof(int));
        dis[i] = (int*)malloc((n+1) * sizeof(int));
        for (int j = 1; j <= n; j++) {
            scanf("%d", &mat[i][j]);
            dis[i][j] = INT_MAX;  
        }
    }
    int result = bfs();
    printf("%d\n", result);
}