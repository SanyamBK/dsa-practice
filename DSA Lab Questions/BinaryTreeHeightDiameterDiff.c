#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

typedef struct pair {
    int first;
    int second;
} pair;

Node* createNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void deleteTree(Node* node) {
    if (node == NULL) {
        return;
    }
    deleteTree(node->left);
    deleteTree(node->right);
    free(node);
}


Node* inputTree(int n) {
    if (n == 0) {
        return NULL;
    }

    int val;
    scanf("%d", &val);
    Node* root = createNode(val);

    Node* queue[n];
    int front = -1, rear = -1;

    queue[++rear] = root;

    int i = 1;
    while (i < n && front != rear) {
        Node* node = queue[++front];

        scanf("%d", &val);
        if (val != -1) {
            node->left = createNode(val);
            queue[++rear] = node->left;
        }

        scanf("%d", &val);
        if (val != -1) {
            node->right = createNode(val);
            queue[++rear] = node->right;
        }

        i++;
    }

    return root;
}

int height(Node *root) {
    if (root == NULL)
        return -1;
    return 1 + fmax(height(root->left), height(root->right));
}

pair Diameter(Node *root) {
    if (root == NULL) {
        pair p;
        p.first = 0;
        p.second = 0;
        return p;
    }
    pair leftans = Diameter(root->left);
    pair rightans = Diameter(root->right);

    int ld = leftans.second;
    int lh = leftans.first;
    int rd = rightans.second;
    int rh = rightans.first;

    int height = 1 + fmax(lh, rh);
    int diameter = fmax(lh + rh, fmax(ld, rd));
    pair p;
    p.first = height;
    p.second = diameter;
    return p;
}

int diameter(Node *root) {
    return Diameter(root).second;
}

int main() {
    int n;
    scanf("%d", &n);
    Node* root = inputTree(n);
    int ans = abs(height(root) - diameter(root));
    printf("%d\n", ans);
    deleteTree(root);
    return 0;
}

