#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Coordinate {
    int x;
    int y;
} Coordinate;

typedef struct Node {
    Coordinate coordinate;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* front;
    Node* rear;
    int size;
} Queue;

Node* createNode(Coordinate c) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode != NULL) {
        newNode->coordinate = c;
        newNode->next = NULL;
    }
    return newNode;
}

Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    if (queue != NULL) {
        queue->front = NULL;
        queue->rear = NULL;
        queue->size = 0;
    }
    return queue;
}

void enqueue(Queue* queue, Coordinate c) {
    Node* newNode = createNode(c);
    if (queue->rear == NULL) {
        queue->front = newNode;
    } else {
        queue->rear->next = newNode;
    }
    queue->rear = newNode;
    queue->size++;
}

Coordinate dequeue(Queue* queue) {
    Coordinate c = queue->front->coordinate;
    Node* temp = queue->front;
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    queue->size--;
    free(temp);
    return c;
}

void freeQueue(Queue* queue) {
    Node* current = queue->front;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    free(queue);
}

int main() {
    int numRows, numCols;
    scanf("%d %d", &numRows, &numCols);

    int** matrix = (int**)malloc(numRows * sizeof(int*));
    for (int i = 0; i < numRows; i++) {
        matrix[i] = (int*)malloc(numCols * sizeof(int));
        for (int j = 0; j < numCols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int numQueries;
    scanf("%d", &numQueries);

    Coordinate* queries = (Coordinate*)malloc(numQueries * sizeof(Coordinate));
    for (int i = 0; i < numQueries; i++) {
        scanf("%d %d", &queries[i].x, &queries[i].y);
    }

    long long** timeMatrix = (long long**)malloc(numRows * sizeof(long long*));
    for (int i = 0; i < numRows; i++) {
        timeMatrix[i] = (long long*)malloc(numCols * sizeof(long long));
        for (int j = 0; j < numCols; j++) {
            timeMatrix[i][j] = -1;
        }
    }

    Queue* fireQueue = createQueue();
    for (int i = 0; i < numRows; i++) {
        if (matrix[i][0] == 0) {
            enqueue(fireQueue, (Coordinate){i, 0});
            timeMatrix[i][0] = 0;
        }
        if (matrix[i][numCols - 1] == 0) {
            enqueue(fireQueue, (Coordinate){i, numCols - 1});
            timeMatrix[i][numCols - 1] = 0;
        }
    }

    for (int j = 0; j < numCols; j++) {
        if (matrix[0][j] == 0) {
            enqueue(fireQueue, (Coordinate){0, j});
            timeMatrix[0][j] = 0;
        }
        if (matrix[numRows - 1][j] == 0) {
            enqueue(fireQueue, (Coordinate){numRows - 1, j});
            timeMatrix[numRows - 1][j] = 0;
        }
    }

    while (fireQueue->front != NULL) {
        Coordinate *c = (Coordinate*)malloc(sizeof(Coordinate));
        *c = dequeue(fireQueue);
        int x = c->x;
        int y = c->y;
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        for (int i = 0; i < 4; i++) {
            int newX = x + dx[i];
            int newY = y + dy[i];
            if (newX >= 0 && newX < numRows && newY >= 0 && newY < numCols && matrix[newX][newY] == 0 && timeMatrix[newX][newY] == -1) {
                timeMatrix[newX][newY] = timeMatrix[x][y] + 1;
                enqueue(fireQueue, (Coordinate){newX, newY});
            }
        }
    }

    for (int i = 0; i < numQueries; i++) {
        Coordinate *query = (Coordinate*) malloc(sizeof(Coordinate));
        *query = queries[i];
        int x = query->x;
        int y = query->y;
        if (x >= 0 && x < numRows && y >= 0 && y < numCols) {
            if (matrix[x][y] == 1 || timeMatrix[x][y] == -1) {
                printf("infinity\n");
            } else {
                printf("%lld\n", timeMatrix[x][y] + 1);
            }
        } else {
            printf("Invalid query\n");
        }
    }

    for (int i = 0; i < numRows; i++) {
        free(matrix[i]);
    }
    free(matrix);
    free(queries);

    for (int i = 0; i < numRows; i++) {
        free(timeMatrix[i]);
    }
    free(timeMatrix);
    freeQueue(fireQueue);

    return 0;
}
