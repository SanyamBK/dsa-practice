#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;


typedef struct stack {
    Node *head;
    int stackSize;
} Stack;


Node *createNode(int data) {
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Stack *createStack() {
    Stack *newStack = (Stack*) malloc(sizeof(Stack));
    newStack->head = NULL;
    newStack->stackSize = 0;
    return newStack;
}


void push(Stack *s, int data) {
    Node *newNode = createNode(data);
    if (s->head == NULL) {
        s->head = newNode;
        s->stackSize++;
    } else {
        Node *temp = s->head;
        s->head = newNode;
        s->head->next = temp;
        s->stackSize++;
    }
}

int pop(Stack *s) {
    if (s->head == NULL) {
        printf("Stack Empty\n");
        return 0;
    }
    int ans = s->head->data;
    s->head = s->head->next;
    s->stackSize--;
    return ans;
}

int isEmpty(Stack *s) {
    return s->head == NULL;
}

int top(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Empty\n");
        return 0;
    }
    return s->head->data;
}

int size(Stack *s) {
    return s->stackSize;
}






