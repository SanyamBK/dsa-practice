#include <stdio.h>
#include <math.h>
#include <stdlib.h>
 
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;
 
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
 
Node* insert(int data, Node* node) {
    if (node == NULL) {
        Node* newNode = createNode(data);
        return newNode;
    }
 
    if (data < node->data) {
        node->left = insert(data, node->left);
    } else {
        node->right = insert(data, node->right);
    }
 
    return node;
}
 
void printPreOrder(Node* root) {
    if (root == NULL)
        return;

    printf("%d ", root->data);
    printPreOrder(root->left);
    printPreOrder(root->right);
}
 
Node* buildBST(int n) {
    Node* root = NULL;
 
    int data;
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        root = insert(data, root);
    }
 
    return root;
}

int main() {
    int n;
    scanf("%d", &n);
    Node* root = buildBST(n);
    printPreOrder(root);
}

