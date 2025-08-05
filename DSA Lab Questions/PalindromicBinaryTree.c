#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insertNode(Node* root, char data, int left) {
    if (root == NULL)
        return createNode(data);
    if (left)
        root->left = createNode(data);
    else
        root->right = createNode(data);
    return root;
}

int isPalindrome(char path[], int start, int end) {
    while (start < end) {
        if (path[start] != path[end])
            return 0;
        start++;
        end--;
    }
    return 1;
}

int countPalindromicPaths(Node* root, char path[], int level, int maxLevel) {
    if (root == NULL)
        return 0;

    int count = 0;
    path[level] = root->data;

    if (root->left == NULL && root->right == NULL) {
        if (isPalindrome(path, 0, level))
            count = 1;
    }

    count += countPalindromicPaths(root->left, path, level + 1, maxLevel);
    count += countPalindromicPaths(root->right, path, level + 1, maxLevel);

    return count;
}

int main() {
    int H;
    scanf("%d", &H);

    // Read the level order traversal of the binary tree
    Node* root = NULL;
    char data;
    int left;
    for (int i = 0; i < (1 << H) - 1; i++) {
        scanf(" %c", &data);
        if (data == 'N')
            continue;
        scanf("%d", &left);
        root = insertNode(root, data, left);
    }

    char path[H];
    int count = countPalindromicPaths(root, path, 0, H - 1);
    printf("%d\n", count);

    return 0;
}
