#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct Graph {
    int numVertices;
    Node** adjList;
} Graph;

Node* createNode(int vertex) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

Graph* createGraph(int numVertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    graph->adjList = (Node**)malloc((numVertices + 1) * sizeof(Node*));

    for (int i = 0; i <= numVertices; i++) {
        graph->adjList[i] = NULL;
    }

    return graph;
}

void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;
}

void printGraph(Graph* graph) {
    for (int i = 1; i <= graph->numVertices; i++) {
        printf("Adjacency list of vertex %d: ", i);
        Node* curr = graph->adjList[i];
        while (curr != NULL) {
            printf("%d ", curr->vertex);
            curr = curr->next;
        }
        printf("\n");
    }
}

bool checkConnection(Graph* graph, int src, int dest) {
    Node* curr = graph->adjList[src];
    while (curr != NULL) {
        if (curr->vertex == dest) {
            return true;
        }
        curr = curr->next;
    }
    return false;
}

bool dfs(Graph* graph, int* teams, bool* visited, int vertex, int team) {
    visited[vertex] = true;
    teams[vertex] = team;

    Node* curr = graph->adjList[vertex];
    while (curr != NULL) {
        int neighbor = curr->vertex;
        if (!visited[neighbor]) {
            if (!dfs(graph, teams, visited, neighbor, 1 - team))
                return false;
        } else if (teams[neighbor] == teams[vertex]) {
            return false;
        }
        curr = curr->next;
    }

    return true;
}

bool canFormTeams(int numVertices, int numEdges, int edges[][2]) {
    Graph* graph = createGraph(numVertices);

    for (int i = 0; i < numEdges; i++) {
        int x = edges[i][0];
        int y = edges[i][1];
        addEdge(graph, x, y);
        addEdge(graph, y, x);
    }

    bool* visited = (bool*)calloc(numVertices + 1, sizeof(bool));
    int* teams = (int*)calloc(numVertices + 1, sizeof(int));

    for (int i = 1; i <= numVertices; i++) {
        if (!visited[i]) {
            if (!dfs(graph, teams, visited, i, 0)) {
                free(visited);
                free(teams);
                return false;
            }
        }
    }

    free(visited);
    free(teams);
    return true;
}

int main() {
    int numVertices, numEdges;
    scanf("%d %d", &numVertices, &numEdges);

    int edges[numEdges][2];
    for (int i = 0; i < numEdges; i++) {
        scanf("%d %d", &edges[i][0], &edges[i][1]);
    }

    if (canFormTeams(numVertices, numEdges, edges))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
