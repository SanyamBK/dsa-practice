#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int data;
    struct node *next;
} node;

node *rangeInput(int n) {
    int data;
    node *head = NULL;
    node *tail = NULL;
    for (int i = 0; i < n; i++) {
        node *newNode = (node*) malloc(sizeof(node));
        scanf("%d", &data);
        newNode -> data = data;
        newNode -> next = NULL;
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail -> next = newNode;
            tail = newNode;
        }

    }
    return head;
}

int kthNode(node *head, int k, int n) { 
    int count = 0;
    if (k == 0 || n < k)
        return -1;
    if (k == 1)
        return head -> data;
    node *temp = head;
    while (count < k - 1) {
        temp = temp -> next;
        count++;
    }
    return temp -> data;
}

node *deleteNode(node *head, int k) {
	if (head == NULL)
		return head;

	if (k == 1) {
		head = head -> next;
		return head;
	}
	node *rest = deleteNode(head->next, k-1);
	head -> next = rest;
	return head;
}

node *deleteK(node *head, int k, int *n) {
    if (k > *n) {
        printf("-1\n");
        return head;
    }
    (*n)--;
    return deleteNode(head, k);
}

void addXtoK(node *head, int k, int x, int n) {
    if (k > n) {
        printf("-1\n");
        return;
    }
    int count = 0;
    node *temp = head;
    while (count < k - 1) {
        temp = temp -> next;
        count++;
    }
    temp->data = temp->data + x;
}

void subXfromK(node *head, int k, int x, int n) {
    if (k > n) {
        printf("-1\n");
        return;
    }
    int count = 0;
    node *temp = head;
    while (count < k - 1) {
        temp = temp -> next;
        count++;
    }
    temp->data = temp->data - x;
}

int xorK(node *head, int k, int n) {
    if (k > n)
        return -1;
    node *temp = head;
    for (int i = 0; i < n - k; i++) {
        temp = temp -> next;
    }
    int xor = temp->data;
    while (temp -> next != NULL) {
        temp = temp -> next;
        xor ^= temp->data;
    }
    return xor;

}

void printLL(node *head) {
    if (head == NULL) {
        printf("\n");
        return;
    }
    printf("%d ", head -> data);
    printLL(head->next);
}


int main () {
    int n, q;
    scanf("%d %d", &n, &q);
    node *head = rangeInput(n);
    while (q--) {
        char oper[10]; int k;
        scanf("%s", &oper);
        scanf("%d", &k);
        if (strcmp(oper, "KthNode") == 0) {
            int ans = kthNode(head, k, n);
            printf("%d\n", ans);
        }
        if (strcmp(oper, "Delete") == 0) {
            head = deleteK(head, k, &n);
            }
        
        if (strcmp(oper, "Add") == 0) {
            int x;
            scanf("%d", &x);
            addXtoK(head, k, x, n);
        }
        if (strcmp(oper, "Subtract") == 0) {
            int x;
            scanf("%d", &x);
            subXfromK(head, k, x, n);
        }

        if (strcmp(oper, "Xor") == 0) {
            int ans = xorK(head, k, n);
            printf("%d\n", ans);
        }
    }
    return 0;
}
