#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NODES 100005

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* adjacencyList[MAX_NODES];
int parentNode[MAX_NODES], nodeDepth[MAX_NODES];
bool isVisited[MAX_NODES];

void addEdge(int u, int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = v;
    newNode->next = adjacencyList[u];
    adjacencyList[u] = newNode;
}

typedef struct {
    int node;
    int parent;
    int depth;
} QueueNode;

QueueNode createQueueNode(int node, int parent, int depth) {
    QueueNode qNode;
    qNode.node = node;
    qNode.parent = parent;
    qNode.depth = depth;
    return qNode;
}

typedef struct {
    QueueNode* array;
    int capacity;
    int front;
    int rear;
    int count;
} Queue;

Queue* createQueue(int capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = 0;
    queue->rear = -1;
    queue->count = 0;
    queue->array = (QueueNode*)malloc(queue->capacity * sizeof(QueueNode));
    return queue;
}

bool isQueueEmpty(Queue* queue) {
    return (queue->count == 0);
}

bool isQueueFull(Queue* queue) {
    return (queue->count == queue->capacity);
}

void enqueue(Queue* queue, QueueNode item) {
    if (isQueueFull(queue))
        return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->count++;
}

QueueNode dequeue(Queue* queue) {
    QueueNode emptyNode;
    emptyNode.node = -1;
    emptyNode.parent = -1;
    emptyNode.depth = -1;
    if (isQueueEmpty(queue))
        return emptyNode;
    QueueNode dequeuedItem = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->count--;
    return dequeuedItem;
}

void depthFirstSearch(int startNode, int numNodes) {
    Queue* queue = createQueue(numNodes);
    enqueue(queue, createQueueNode(startNode, 0, 0));

    while (!isQueueEmpty(queue)) {
        QueueNode currentQueueNode = dequeue(queue);
        int currentNode = currentQueueNode.node;
        int parent = currentQueueNode.parent;
        int depth = currentQueueNode.depth;

        parentNode[currentNode] = parent;
        isVisited[currentNode] = true;
        nodeDepth[currentNode] = depth;

        for (Node* nextNode = adjacencyList[currentNode]; nextNode != NULL; nextNode = nextNode->next) {
            if (!isVisited[nextNode->data]) {
                enqueue(queue, createQueueNode(nextNode->data, currentNode, depth + 1));
            }
        }
    }
}

bool isTowards(int x, int y) {
    while (nodeDepth[y] > nodeDepth[x]) {
        y = parentNode[y];
    }
    return x == y;
}

bool isAway(int x, int y) {
    while (nodeDepth[x] > nodeDepth[y]) {
        x = parentNode[x];
    }
    return x == y;
}

int main() {
    int numNodes, numQueries;
    scanf("%d", &numNodes);
    for (int i = 1; i < numNodes; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);
        addEdge(v, u);
    }
    depthFirstSearch(1, numNodes);
    scanf("%d", &numQueries);
    while (numQueries--) {
        char queryType[10];
        int x, y;
        scanf("%s %d %d", queryType, &x, &y);
        if (strcmp(queryType, "towards") == 0) {
            printf("%s\n", isTowards(x, y) ? "YES" : "NO");
        } else {
            printf("%s\n", isAway(x, y) ? "YES" : "NO");
        }
    }
    return 0;
}