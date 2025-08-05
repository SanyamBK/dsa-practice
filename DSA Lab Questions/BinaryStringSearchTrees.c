#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// char *strcpy(char *dest, const char *src) {
//     char *result = dest;
//     while (*src != '\0') {
//         *dest++ = *src++;
//     }
//     *dest = '\0'; 
//     return result;
// }


typedef struct Node {
    char str[21];
    struct Node *left;
    struct Node *right;

} Node;

Node *createNode(char str[]) {
    Node* node = (Node*)malloc(sizeof(Node));
    strcpy(node->str, str);
    node->left = NULL;
    node->right = NULL;
    return node;
}

void deleteNode(Node* node) {
    if (node == NULL) return;
    deleteNode(node->left);
    deleteNode(node->right);
    free(node);
}

int compareStrings(const char* str1, const char* str2) {
    while (*str1 && (*str1 == *str2)) {
        str1++;
        str2++;
    }
    return *(const unsigned char*) str1 - *(const unsigned char*) str2;
}

// typedef struct BST {
//     Node *root;
// } BST;



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

/*
int compare(const void *s1, const void *s2) {
    char **p1 = (char **) s1;
    char **p2 = (char **) s2;
    char *str1 = *p1;
    char *str2 = *p2;

    while (*str1 || *str2) {
        if (*str1 < *str2) {
            return -1;
        } else if (*str1 > *str2) {
            return 1;
        }
        str1++;
        str2++;
    }

    return 0;
}

void lexicographic_sort(char **arr, int n) {
    qsort(arr, n, sizeof(char *), compare);
}*/

Node *insert(Node *root, char *str) {
        if (root == NULL) {
            return createNode(str);
        }
        if (compareStrings(str, root->str) <= 0) {
            root -> left = insert(root->left, str);
        }
        else {
            root -> right = insert(root->right, str);
        }
        return root;
}
/*
Node *BST(char **input, int si, int ei) {
	if (si > ei)
		return NULL;
		
	int mid = (si + ei)/2;
	char *rootData = input[mid];
	Node *root = createNode(rootData);

	Node *left = BST(input, si, mid-1);
	Node *right = BST(input, mid+1, ei);

	root->left = left;
	root->right = right;

	return root;

}
*/

void preOrder(Node *root) {
    if (root == NULL)
        return;

    preOrder(root->left);
    printf("%s\n", root->str);
    preOrder(root->right);
}


int isPefix(char *small, char *large) {
    if (small[0] == '\0')
        return 1;

    if (strlen(small) > strlen(large) || small[0] != large[0])
        return 0;

    if (!isPefix(small+1, large+1))
        return 0;

    return 1;
}

void findPref(Node *root, const char *pref) {
    if (root == NULL) {
        return;
    }

    int cmp = compareStrings(root->str, pref);
    if (cmp >= 0) {
        findPref(root->left, pref);
    }
    if (strncmp(root->str, pref, strlen(pref)) == 0) {
        printf("%s\n", root->str);
    }
    if (cmp <= 0) {
        findPref(root->right, pref);
    }
}

void print_strings_with_prefix(Node* root, char* prefix) {
    if (root == NULL) {
        return;
    }
    if (strncmp(root->str, prefix, strlen(prefix)) == 0) {
        printf("%s\n", root->str);
    }
    if (strncmp(root->str, prefix, strlen(prefix)) >= 0) {
        print_strings_with_prefix(root->left, prefix);
    }
    if (strncmp(root->str, prefix, strlen(prefix)) <= 0) {
        print_strings_with_prefix(root->right, prefix);
    }
}



Node *deleteData(char *prefix, Node *root) {
    if (root == NULL) 
        return NULL;
    
    if (strncmp(root->str, prefix, strlen(prefix)) >= 0) {
        root -> left = deleteData(prefix, root->left);
        return root;
    }
    else if (strncmp(root->str, prefix, strlen(prefix)) <= 0) {
        root -> right = deleteData(prefix, root->right);
        return root;
    }
    else {
        if (root->left == NULL && root->right == NULL) {
            deleteNode(root);
            return NULL;
        } else if (root->right == NULL) {
            Node *temp = root -> left;
            root-> left = NULL;
            deleteNode(root);
            return temp;
        } else if (root->left == NULL) {
            Node *temp = root -> right;
            root-> right = NULL;
            deleteNode(root);
            return temp;
        } else {
            Node *minNode = root -> right;
            while (minNode -> left != NULL) {
                minNode = minNode -> left;
            }
            char *rightMin;
            strcpy(rightMin, minNode->str);
            strcpy(root -> str, rightMin);
            root -> right = deleteData(rightMin, root->right);
            return root;
        }
    }
}

Node *delete_strings_with_prefix(Node* root, char* prefix) {
    if (root == NULL) {
        return NULL;
    }
    if (strncmp(root->str, prefix, strlen(prefix)) == 0) {
        root = deleteData(prefix, root);
    }
    if (strncmp(root->str, prefix, strlen(prefix)) >= 0) {
        delete_strings_with_prefix(root->left, prefix);
    }
    if (strncmp(root->str, prefix, strlen(prefix)) <= 0) {
        delete_strings_with_prefix(root->right, prefix);
    }
}

int searchPrefix(Node* node, char* prefix) {
    if (node == NULL) return 0;

    int result = strncmp(node->str, prefix, strlen(prefix));

    if (result >= 0)
        return searchPrefix(node->left, prefix);

    if (strncmp(node->str, prefix, strlen(prefix)) == 0)
        return 1;

    return searchPrefix(node->right, prefix);
}

int main() {
    int n;
    // scanf("%d", &n);
/*
    char **array = (char **) malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++) {
        char *str = (char *) malloc(21 * sizeof(char));
        scanf("%s", str);
        array[i] = str;
    }
    
    lexicographic_sort(array, n);

    Node *root = BST(array, 0, n - 1);
*/
    if(isPefix("ab", "abc")) {
        printf("true");
    }
    // Node *root = NULL;
    // for (int i = 0; i < n; i++) {
    //     char *str = (char *) malloc(21 * sizeof(char));
    //     scanf("%s", str);
    //     root = insert(root, str);
    // }

    // root = delete_strings_with_prefix(root, "ab");
    // printTree(root);
    // free(array);
    // deleteNode(root);
    return 0;
}