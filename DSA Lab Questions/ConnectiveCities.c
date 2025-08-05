#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Node {
    int val;
    struct Node* next;
} Node;

typedef struct Graph {
    int n;
    Node** adj;
} Graph;

Node* newNode(int val) {
    Node* node = malloc(sizeof(Node));
    node->val = val;
    node->next = NULL;
    return node;
}

Graph* newGraph(int n) {
    Graph* graph = malloc(sizeof(Graph));
    graph->n = n;
    graph->adj = malloc(sizeof(Node*) * n);
    for (int i = 0; i < n; i++) {
        graph->adj[i] = NULL;
    }
    return graph;
}

void addEdge(Graph* graph, int u, int v) {
    Node* node = newNode(v);
    node->next = graph->adj[u];
    graph->adj[u] = node;
}

void dijkstra(Graph* graph, int s, int* dist) {
    for (int i = 0; i < graph->n; i++) {
        dist[i] = INT_MAX;
    }
    dist[s] = 0;

    Node* queue[graph->n];
    int front = 0;
    int rear = 0;
    queue[rear++] = newNode(s);

    while (front < rear) {
        Node* node = queue[front++];
        for (Node* adj = node->next; adj != NULL; adj = adj->next) {
            if (dist[adj->val] > dist[node->val] + 1) {
                dist[adj->val] = dist[node->val] + 1;
                queue[rear++] = adj;
            }
        }
    }
}

int main() {
    int n, t;
    scanf("%d %d", &n, &t);

    Graph* graph = newGraph(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        u--;
        v--;
        addEdge(graph, u, v);
        addEdge(graph, v, u);
    }

    int* dist = malloc(sizeof(int) * n);
    dijkstra(graph, 0, dist);

    int ans[t];
    for (int i = 0; i < t; i++) {
        int v, d;
        scanf("%d %d", &v, &d);
        v--;
        ans[i] = (dist[v] == d);
    }

    for (int i = 0; i < t; i++) {
        printf("%d\n", ans[i]);
    }

    free(dist);
    free(graph);
    return 0;
}
