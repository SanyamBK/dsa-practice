#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Node {
    struct Node* lchild;
    long long int data;
    int bf;
    int height;
    long long int sum;
    struct Node* rchild;
} *root = NULL;


int height(struct Node* p) {
    if (p == NULL)
        return 0;
    return p->height;
}

long long int SubtreeSum(struct Node* p) {
    if (p == NULL)
        return 0;
    return p->sum;
}

struct Node* LLRotation(struct Node* p) {
    struct Node* pl = p->lchild;
    p->lchild = pl->rchild;
    pl->rchild = p;

    // Update height and subtree sum for p and pl
    p->height = 1 + fmax(height(p->lchild), height(p->rchild));
    pl->height = 1 + fmax(height(pl->lchild), height(pl->rchild));
    p->sum = (long long int)p->data + SubtreeSum(p->lchild) + SubtreeSum(p->rchild);
    pl->sum = (long long int)pl->data + SubtreeSum(pl->lchild) + SubtreeSum(pl->rchild);

    if (p == root)
        root = pl;
    return pl;
}

struct Node* LRRotation(struct Node* p) {
    struct Node* pl = p->lchild;
    struct Node* plr = pl->rchild;
    pl->rchild = plr->lchild;
    p->lchild = plr->rchild;
    plr->lchild = pl;
    plr->rchild = p;

    // Update height and subtree sum for p, pl, and plr
    p->height = 1 + fmax(height(p->lchild), height(p->rchild));
    pl->height = 1 + fmax(height(pl->lchild), height(pl->rchild));
    plr->height = 1 + fmax(height(plr->lchild), height(plr->rchild));
    p->sum = (long long int)p->data + SubtreeSum(p->lchild) + SubtreeSum(p->rchild);
    pl->sum = (long long int)pl->data + SubtreeSum(pl->lchild) + SubtreeSum(pl->rchild);
    plr->sum = (long long int)plr->data + SubtreeSum(plr->lchild) + SubtreeSum(plr->rchild);

    if (p == root)
        root = plr;
    return plr;
}

struct Node* RRRotation(struct Node* p){
    struct Node* pr = p->rchild;
    p->rchild = pr->lchild;
    pr->lchild = p;

    // Update height and subtree sum for p and pr
    p->height = 1 + fmax(height(p->lchild), height(p->rchild));
    pr->height = 1 + fmax(height(pr->lchild), height(pr->rchild));
    p->sum = (long long int)p->data + SubtreeSum(p->lchild) + SubtreeSum(p->rchild);
    pr->sum = (long long int)pr->data + SubtreeSum(pr->lchild) + SubtreeSum(pr->rchild);

    if (p == root)
        root = pr;
    return pr;
}

struct Node* RLRotation(struct Node* p) {
    struct Node* pr = p->rchild;
    struct Node* prl = pr->lchild;
    p->rchild = prl->lchild;
    pr->lchild = prl->rchild;
    prl->rchild = pr;
    prl->lchild = p;

    // Update height and subtree sum for p, pr, and prl
    p->height = 1 + fmax(height(p->lchild), height(p->rchild));
    pr->height = 1 + fmax(height(pr->lchild), height(pr->rchild));
    prl->height = 1 + fmax(height(prl->lchild), height(prl->rchild));
    p->sum = (long long int)p->data + SubtreeSum(p->lchild) + SubtreeSum(p->rchild);
    pr->sum = (long long int)pr->data + SubtreeSum(pr->lchild) + SubtreeSum(pr->rchild);
    prl->sum = (long long int)prl->data + SubtreeSum(prl->lchild) + SubtreeSum(prl->rchild);

    if (p == root)
        root = prl;
    return prl;
}

struct Node* RInsert(struct Node* p, long long int key , int *leftRotations , int *rightRotations) {
    if (p == NULL) {
        struct Node* t = (struct Node*)malloc(sizeof(struct Node));
        t->data = key;
        t->bf = 0;
        t->lchild = t->rchild = NULL;
        t->height = 1;
        t->sum = (long long int)key;
        return t;
    }

    if (key < p->data) {
        p->lchild = RInsert(p->lchild, key , leftRotations , rightRotations);
        p->height = 1 + fmax(height(p->lchild), height(p->rchild));
        p->sum = (long long int)p->data + SubtreeSum(p->lchild) + SubtreeSum(p->rchild);

        int lbf = height(p->lchild) + 1;
        int rbf = height(p->rchild) + 1;
        p->bf = lbf - rbf;

        if (p->bf == 2 && p->lchild->bf == 1) {
            (*rightRotations)++;
            return LLRotation(p);
        }
        if (p->bf == 2 && p->lchild->bf == -1) {
            (*leftRotations)++;
            (*rightRotations)++;
            return LRRotation(p);
        }
    } else if (key > p->data) {
        p->rchild = RInsert(p->lchild, key , leftRotations , rightRotations);
        p->height = 1 + fmax(height(p->lchild), height(p->rchild));
        p->sum = (long long int)p->data + SubtreeSum(p->lchild) + SubtreeSum(p->rchild);

        int lbf = height(p->lchild) + 1;
        int rbf = height(p->rchild) + 1;
        p->bf = lbf - rbf;

        if (p->bf == -2 && p->rchild->bf == -1) {
            (*rightRotations)++;
            return RRRotation(p);
        }
        if (p->bf == -2 && p->rchild->bf == 1) {
            (*rightRotations)++;
            (*leftRotations)++;
            return RLRotation(p);
        }
    }
    return p;
}


struct Node* insert(struct Node* node, long long data, int* leftrot, int* rightrot) {
    if (node == NULL)
        return createNode(data);

    if (data < node->data)
        node->lchild = insert(node->lchild, data, leftrot, rightrot);
    else
        node->rchild = insert(node->rchild, data, leftrot, rightrot);

    node->height = (height(node->lchild) > height(node->rchild) ? height(node->lchild) : height(node->rchild)) + 1;

    int balance = getBalance(node);

    if (balance > 1 && data < node->lchild->data) {
        (*rightrot)++;
        return RRotate(node);
    }

    if (balance < -1 && data > node->lchild->data) {
        (*leftrot)++;
        return L(node);
    }

    if (balance > 1 && data > node->lchild->data) {
        node->lchild = leftRotate(node->lchild);
        (*leftrot)++;
        (*rightrot)++;
        return rightRotate(node);
    }

    if (balance < -1 && data < node->rchild->data) {
        node->rchild = rightRotate(node->rchild);
        (*rightrot)++;
        (*leftrot)++;
        return leftRotate(node);
    }

    return node;
}

void Inorder(struct Node* p) {
    if (p) {
        Inorder(p->lchild);
        printf("%lld ", p->data);
        Inorder(p->rchild);
    }
}

struct Node* Search(struct Node* p, long long int key) {
    if (p == NULL || p->data == key)
        return p;
    if (key < p->data)
        return Search(p->lchild, key);
    else
        return Search(p->rchild, key);
}

long long int getSum(struct Node* root) {
    if (root == NULL)
        return 0;
    long long int sum = root->data;
    return sum + getSum(root->lchild) + getSum(root->rchild);
}

int main() {
    int Q;
    scanf("%d", &Q);

    while (Q--) {
        char query[10];
        long long int x;
        scanf("%s%lld", query, &x);

        if (query[0] == 'i') {
            int leftRotations = 0;
            int rightRotations = 0;
            root = RInsert(root, x , &leftRotations , &rightRotations);
            printf("%d %d\n", leftRotations, rightRotations);
        } else if (query[0] == 's') {
            struct Node* subtreeRoot = Search(root, x);
            if (subtreeRoot)
                printf("%lld\n", getSum(subtreeRoot));
            else
                printf("NA\n");
        }
    }

    return 0;
}