#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct Queue {
    Node *head;
    Node *tail;
    int size;
} Queue;

Node *newNode(int data) {
    Node *new_node = (Node*) malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

Queue *createQueue() {
    Queue *queue = (Queue*) malloc(sizeof(Queue));
    queue->head = NULL;
    queue->tail = NULL;
    queue->size = 0;
    return queue;
}

int getSize(Queue *queue) {
    return queue->size;
}

int isEmpty(Queue *queue) {
    return queue->size == 0;
}

void enqueue(Queue *queue, int data) {
    Node *new_node = newNode(data);
    if (queue->head == NULL) {
        queue->head = new_node;
        queue->tail = new_node;
    } else {
        queue->tail->next = new_node;
        queue->tail = new_node;
    }
    queue->size++;
}

int dequeue(Queue *queue) {
    if (queue->head == NULL)
        return -1;
    int ans = queue->head->data;
    queue->head = queue->head->next;
    queue->size--;
    return ans;
}
