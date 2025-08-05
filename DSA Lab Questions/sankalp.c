#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct AVLNode {
    int value;
    struct AVLNode* left;
    struct AVLNode* right;
    int height;
    long long subtree_sum;
} AVLNode;

typedef struct AVLTree {
    AVLNode* root;
} AVLTree;

AVLNode* create_node(int value) {
    AVLNode* node = (AVLNode*)malloc(sizeof(AVLNode));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    node->subtree_sum = value;
    return node;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int get_height(AVLNode* node) {
    if (node == NULL)
        return 0;
    return node->height;
}

long long get_subtree_sum(AVLNode* node) {
    if (node == NULL)
        return 0;
    return node->subtree_sum;
}

void update_subtree_sum(AVLNode* node) {
    if (node == NULL)
        return;
    node->subtree_sum = (long long)node->value + get_subtree_sum(node->left) + get_subtree_sum(node->right);
}

int get_balance_factor(AVLNode* node) {
    if (node == NULL)
        return 0;
    return get_height(node->left) - get_height(node->right);
}

AVLNode* rotate_right(AVLNode* y) {
    AVLNode* x = y->left;
    AVLNode* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1 + max(get_height(y->left), get_height(y->right));
    x->height = 1 + max(get_height(x->left), get_height(x->right));

    update_subtree_sum(y);
    update_subtree_sum(x);

    return x;
}

AVLNode* rotate_left(AVLNode* x) {
    AVLNode* y = x->right;
    AVLNode* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = 1 + max(get_height(x->left), get_height(x->right));
    y->height = 1 + max(get_height(y->left), get_height(y->right));

    update_subtree_sum(x);
    update_subtree_sum(y);

    return y;
}

AVLNode* insert(AVLNode* node, int value, int* L, int* R) {
    if (node == NULL)
        return create_node(value);

    if (value < node->value) {
        node->left = insert(node->left, value, L, R);
    }
    else {
        node->right = insert(node->right, value, L, R);
    }

    node->height = 1 + max(get_height(node->left), get_height(node->right));
    int balance_factor = get_balance_factor(node);

    // Left Rotation
    if (balance_factor > 1 && value < node->left->value)
        (*R)++;
        return rotate_right(node);

    // Right Rotation
    if (balance_factor < -1 && value > node->right->value)
        (*L)++;
        return rotate_left(node);

    // Left-Right Rotation
    if (balance_factor > 1 && value > node->left->value) {
        (*L)++;
        node->left = rotate_left(node->left);
        (*R)++;
        return rotate_right(node);
    }

    // Right-Left Rotation
    if (balance_factor < -1 && value < node->right->value) {
        (*R)++;
        node->right = rotate_right(node->right);
        (*L)++;
        return rotate_left(node);
    }

    update_subtree_sum(node);

    return node;
}

AVLNode* search(AVLNode* node, int value) {
    if (node == NULL || node->value == value)
        return node;

    if (value < node->value)
        return search(node->left, value);
    else
        return search(node->right, value);
}

void subtree_sum(AVLTree* tree, int value) {
    AVLNode* node = search(tree->root, value);
    if (node)
        printf("%lld\n", get_subtree_sum(node));
    else
        printf("NA\n");
}

int main() {
    int Q;
    scanf("%d", &Q); // Number of queries

    AVLTree tree;
    tree.root = NULL;

    for (int i = 0; i < Q; i++) {
        char operation[10];
        int value;
        scanf("%s %d", operation, &value);

        int L = 0, R = 0; // Initialize rotation counts for each query

        if (strcmp(operation, "insert") == 0) {
            tree.root = insert(tree.root, value, &L, &R);
            printf("%d %d\n", L, R);
        }
        else if (strcmp(operation, "subtree") == 0) {
            subtree_sum(&tree, value);
        }
    }

    return 0;
}