#include <stdio.h>
#include <stdlib.h>

#define MAX_COURSES 10000

typedef struct Node {
    int course;
    struct Node* next;
} Node;

typedef struct AdjList {
    Node* head;
} AdjList;

typedef struct Graph {
    int numCourses;
    int numPrerequisites;
    AdjList* array;
} Graph;

Node* createNode(int course) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->course = course;
    newNode->next = NULL;
    return newNode;
}

Graph* createGraph(int numCourses, int numPrerequisites) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numCourses = numCourses;
    graph->numPrerequisites = numPrerequisites;

    graph->array = (AdjList*)malloc((numCourses + 1) * sizeof(AdjList));
    for (int i = 1; i <= numCourses; i++) {
        graph->array[i].head = NULL;
    }

    return graph;
}

void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
}

void printGraph(Graph* graph) {
    for (int i = 1; i <= graph->numCourses; i++) {
        printf("Course %d: ", i);
        Node* currentNode = graph->array[i].head;
        while (currentNode != NULL) {
            printf("%d ", currentNode->course);
            currentNode = currentNode->next;
        }
        printf("\n");
    }
}


void freeGraph(Graph* graph) {
    if (graph == NULL) {
        return;
    }

    for (int i = 1; i <= graph->numCourses; i++) {
        Node* currentNode = graph->array[i].head;
        while (currentNode != NULL) {
            Node* temp = currentNode;
            currentNode = currentNode->next;
            free(temp);
        }
    }

    free(graph->array);
    free(graph);
}


int main() {
    int numCourses, numPrerequisites;
    scanf("%d %d", &numCourses, &numPrerequisites);

    Graph* graph = createGraph(numCourses, numPrerequisites);

    for (int i = 0; i < numPrerequisites; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        addEdge(graph, a, b);
    }

    int* inDegrees = (int*)calloc((graph->numCourses + 1), sizeof(int));

    for (int i = 1; i <= graph->numCourses; i++) {
        Node* currentNode = graph->array[i].head;
        while (currentNode != NULL) {
            int dest = currentNode->course;
            inDegrees[dest]++;
            currentNode = currentNode->next;
        }
    }

    int* queue = (int*)malloc((graph->numCourses + 1) * sizeof(int));
    int front = 0;
    int rear = 0;

    for (int i = 1; i <= graph->numCourses; i++) {
        if (inDegrees[i] == 0) {
            queue[rear++] = i;
        }
    }

    int count = 0;
    while (front != rear) {
        int course = queue[front++];
        count++;

        Node* currentNode = graph->array[course].head;
        while (currentNode != NULL) {
            int dest = currentNode->course;
            inDegrees[dest]--;
            if (inDegrees[dest] == 0) {
                queue[rear++] = dest;
            }
            currentNode = currentNode->next;
        }
    }

    free(queue);
    free(inDegrees);

    if (count == graph->numCourses) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    freeGraph(graph);

    return 0;
}
