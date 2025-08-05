#include <stdio.h>
#include <stdlib.h>
#include <string.h>
                   
typedef long long ll;
                  
typedef struct Node {
    ll data;
    struct Node* left;
    struct Node* right;
    int height;
} Node;
                  
int getHeight(Node* node) {
    if (node == NULL)
        return 0;
    return node->height;
}                  
               
ll getSum(Node* root) {
    if (root == NULL)
        return 0;
    ll sum = root->data;
    return sum + getSum(root->left) + getSum(root->right);
}                     
                 
int getBalance(Node* node) {
    if (node == NULL)
        return 0;
    return getHeight(node->left) - getHeight(node->right);
}                         
                     
Node* createNode(ll data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;
    return newNode;
}
                  
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = (getHeight(y->left) > getHeight(y->right) ? getHeight(y->left) : getHeight(y->right)) + 1;
    x->height = (getHeight(x->left) > getHeight(x->right) ? getHeight(x->left) : getHeight(x->right)) + 1;

    return x;
}
                             
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = (getHeight(x->left) > getHeight(x->right) ? getHeight(x->left) : getHeight(x->right)) + 1;
    y->height = (getHeight(y->left) > getHeight(y->right) ? getHeight(y->left) : getHeight(y->right)) + 1;

    return y;
}
                          
Node* insert(Node* node, ll data, int* leftrot, int* rightrot) {
    if (node == NULL)
        return createNode(data);

    if (data < node->data)
        node->left = insert(node->left, data, leftrot, rightrot);
    else
        node->right = insert(node->right, data, leftrot, rightrot);

    node->height = (getHeight(node->left) > getHeight(node->right) ? getHeight(node->left) : getHeight(node->right)) + 1;

    int balance = getBalance(node);

    if (balance > 1 && data < node->left->data) {
        (*rightrot)++;
        return rightRotate(node);
    }

    if (balance < -1 && data > node->right->data) {
        (*leftrot)++;
        return leftRotate(node);
    }

    if (balance > 1 && data > node->left->data) {
        node->left = leftRotate(node->left);
        (*leftrot)++;
        (*rightrot)++;
        return rightRotate(node);
    }

    if (balance < -1 && data < node->right->data) {
        node->right = rightRotate(node->right);
        (*rightrot)++;
        (*leftrot)++;
        return leftRotate(node);
    }

    return node;
}
                                                              
ll subtree(ll data, Node* root) {
    if (root == NULL) {
        printf("NA\n");
        return -1;
    }

    if (root->data == data) {
        return getSum(root);
    }

    if (root->data > data) {
        return subtree(data, root->left);
    } else {
        return subtree(data, root->right);
    }
}
                                 
int main() {
    int q;
    scanf("%d", &q);
                                     
    Node* root = NULL;
                                      
    while (q--) {
        char query[10];
        ll x;
        scanf("%s %lld", query, &x);
        if (strcmp(query, "insert") == 0) {
            int left_rot = 0, right_rot = 0;
            root = insert(root, x, &left_rot, &right_rot);
            printf("%d %d\n", left_rot, right_rot);
        }
        if (strcmp(query, "subtree") == 0) {
            ll sum = subtree(x, root);
            if (sum != -1) {
                printf("%lld\n", sum);
            }
        }
    }
                             
    return 0;
}
