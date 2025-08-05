#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

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

bool isBST(Node *root, int min, int max) {
    if (root == NULL) 
        return true;

    if (root -> data < min || root -> data > max)
        return false;

    bool isLeftOK = isBST(root->left, min, root -> data -1);
    bool isRightOK = isBST(root->right, root->data, max);
    return isLeftOK && isRightOK;

}

int height(Node* root) {
    if (root == NULL) {
        return 0;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return (leftHeight > rightHeight) ? leftHeight + 1 : rightHeight + 1;
}

int balanceFactor(Node* root) {
    if (root == NULL) {
        return 0;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return leftHeight - rightHeight;
}

bool isBalanced(Node* root) {
    if (root == NULL) {
        return true;
    }

    int bf = balanceFactor(root);
    if (bf < -1 || bf > 1) {
        return false;
    }

    return isBalanced(root->left) && isBalanced(root->right);
}

bool isAVLTree(Node* root) {
    if (root == NULL) {
        return true;
    }

    return isBalanced(root) && isAVLTree(root->left) && isAVLTree(root->right);
}

int main () {
    int n;
    scanf("%d", &n);

    Node *root = inputTree(n);


    if (isAVLTree(root) && isBST(root, INT_MIN, INT_MAX)) {
        printf("YES");
    } else {
        printf("NO");
    }

}
// 6
// 50 20 80 15 -1 60 -1 -1 19 -1 -1 -1 -1
