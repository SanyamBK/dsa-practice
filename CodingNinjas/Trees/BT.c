#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* create_node(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node* inputTree(int n) {
    if (n == 0) {
        return NULL;
    }

    int val;
    scanf("%d", &val);
    Node* root = create_node(val);

    Node* queue[n];
    int front = -1, rear = -1;

    queue[++rear] = root;

    int i = 1;
    while (i < n && front != rear) {
        Node* node = queue[++front];

        scanf("%d", &val);
        if (val != -1) {
            node->left = create_node(val);
            queue[++rear] = node->left;
        }

        scanf("%d", &val);
        if (val != -1) {
            node->right = create_node(val);
            queue[++rear] = node->right;
        }

        i++;
    }

    return root;
}


void printTree(Node *root) {
    if (root == NULL) {
        return;
    }

    printf("%d: ", root->data);
    if (root->left != NULL) {
        printf("%d ", root->left->data);
    }
    if (root->right != NULL) {
        printf("%d ", root->right->data);
    }
    printf("\n");
    printTree(root->left);
    printTree(root->right);
}


int main() {
    int arr[] = {1, 2, 3, 4, -1, 5, -1, 6, -1, -1, -1, -1, -1};
    Node* root = inputTree(6);
    printTree(root);
    return 0;
}
