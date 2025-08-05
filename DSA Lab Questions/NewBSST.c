#include <stdio.h>
#include <stdlib.h>

char *strcpy(char *dest, const char *src) {
    char *result = dest;
    while (*src != '\0') {
        *dest++ = *src++;
    }
    *dest = '\0';
    return result;
}

int strlen(char *str) {
    if (str[0] == '\0')
        return 0;
    return 1 + strlen(str+1);
}

int isPefix(char *small, char *large)
{
    if (small[0] == '\0') return 1;
    if (strlen(small) > strlen(large) || small[0] != large[0]) {
        return 0;
    }
    if (!isPefix(small + 1, large + 1)) {
        return 0;
    }
    return 1;
}


typedef struct Node {
    char str[21];
    struct Node *left;
    struct Node *right;
} Node;

Node *createNode(char str[])
{
    Node *node = (Node *)malloc(sizeof(Node));
    strcpy(node->str, str);
    node->left = NULL;
    node->right = NULL;
    return node;
}

void deleteNode(Node *node)
{
    if (node == NULL)
        return;
    deleteNode(node->left);
    deleteNode(node->right);
    free(node);
}

int compareStrings(const char *str1, const char *str2) {
    while (*str1 && (*str1 == *str2)) {
        str1++;
        str2++;
    }
    return *(const unsigned char *)str1 - *(const unsigned char *)str2;
}


Node *insert(Node *root, char *str) {
    if (root == NULL) {
        return createNode(str);
    }
    if (compareStrings(str, root->str) <= 0) {
        root->left = insert(root->left, str);
    }
    else {
        root->right = insert(root->right, str);
    }
    return root;
}


void preOrder(Node *root)
{
    if (root == NULL)
        return;
    preOrder(root->left);
    printf("%s\n", root->str);
    preOrder(root->right);
}


void printTree(Node* root) {
    if (root == NULL)
        return;
    printf("%s:", root->str);
    if (root->left != NULL)
        printf("L:%s,", root->left->str);
    if (root->right != NULL)
        printf("R:%s\n", root->right->str);
    else 
        printf("\n");
    printTree(root->left);
    printTree(root->right);
}


int main()
{
    int n;
    /*
    scanf("%d", &n);

    Node *root = NULL;
    for (int i = 0; i < n; i++) {
        char *str = (char *) malloc(21 * sizeof(char));
        scanf("%s", str);
        root = insert(root, str);
    }
    */
    int cmp = compareStrings("ab", "aab");
    printf("%d\n", cmp);
    // printTree(root);
    // deleteNode(root);
    return 0;
}