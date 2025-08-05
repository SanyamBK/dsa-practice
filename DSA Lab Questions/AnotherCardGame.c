#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

    y->height = fmax(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = fmax(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = fmax(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = fmax(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

Node* insert(Node* node, ll data) {
    if (node == NULL)
        return createNode(data);

    if (data <= node->data)
        node->left = insert(node->left, data);
    else
        node->right = insert(node->right, data);

    node->height = fmax(getHeight(node->left), getHeight(node->right)) + 1;

    int balance = getBalance(node);

    if (balance > 1 && data <= node->left->data)
        return rightRotate(node);

    if (balance < -1 && data > node->right->data)
        return leftRotate(node);

    if (balance > 1 && data > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && data <= node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

Node* minValueNode(Node* node) {
    Node* current = node;

    while (current->left != NULL)
        current = current->left;

    return current;
}

Node* deleteNode(Node* root, ll data) {
    if (root == NULL)
        return root;

    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else {
        if (root->left == NULL || root->right == NULL) {
            Node* temp = root->left ? root->left : root->right;

            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else {
                *root = *temp;
                free(temp);
            }
        } else {
            Node* temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }

    if (root == NULL)
        return root;

    root->height = fmax(getHeight(root->left), getHeight(root->right)) + 1;

    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

ll minNode(Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root->data;
}

ll maxNode(Node* root) {
    while (root->right != NULL) {
        root = root->right;
    }
    return root->data;
}

ll getSum(Node* root) {
    if (root == NULL)
        return 0;
    ll sum = root->data;
    return sum + getSum(root->left) + getSum(root->right);
}

int main() {
    int n;
    scanf("%d", &n);
    Node* root = NULL;
    ll data;
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &data);
        root = insert(root, data);
        sum += data;
    }

    while (n >= 2) {
        ll min = minNode(root);
        ll max = maxNode(root);
        root = deleteNode(root, min);
        root = deleteNode(root, max);
        sum -= (min + max);

        ll diff = llabs(min - max);
        root = insert(root, diff);

        sum += diff;
        printf("%lld\n", sum);
        n--;
    }

    return 0;
}
