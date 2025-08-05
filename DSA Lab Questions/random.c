#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 

struct Node
{
    struct Node *lchild;
   long long data;
   int height;
    struct Node *rchild;
} *root=NULL;
 
int NodeHeight(struct Node *root)
{
    struct Node*p=root;
    int hl,hr;
    hl=p && p->lchild?p->lchild->height:0;
    hr=p && p->rchild?p->rchild->height:0;
    return hl>hr?hl+1:hr+1;
}
 
int BalanceFactor(struct Node *root)
{
    struct Node *p=root;
    int hl,hr;
    hl=p && p->lchild?p->lchild->height:0;
    hr=p && p->rchild?p->rchild->height:0;
    return hl-hr;
}
 
struct Node *search(struct Node *root, long long key){
    while(root!=NULL){
        if (key == root->data){
            return root;
        }
        else if(key < root->data){
            root = root->lchild;
        }
        else{
            root = root->rchild;
        }
    }
    return NULL;
}
 
struct Node * LLRotation(struct Node *root)
 
{
    struct Node *p=root;
    struct Node *pl=p->lchild;
    struct Node *plr=pl->rchild;
 
    pl->rchild=p;
    p->lchild=plr;
    p->height=NodeHeight(p);
    pl->height=NodeHeight(pl);
 
    if(root==p)
        root=pl;
    return pl;
}
 
struct Node * RRRotation(struct Node *root)
{   struct Node *p=root;
 
    struct Node *pr=p->rchild;
    struct Node *prl=pr->lchild;
 
    pr->lchild = p;
    p->rchild = prl;
    p->height = NodeHeight(p);
    pr->height = NodeHeight(pr);
    
    if(root==p)
        root=pr;
 
    return pr;
}
 
struct Node * LRRotation(struct Node *root)
{
    struct Node *p=root;
    struct Node *pl = p->lchild;
    struct Node *plr = pl->rchild;
 
    pl->rchild = plr->lchild;
    p->lchild = plr->rchild;
 
    plr->lchild=pl;
    plr->rchild=p;
 
    pl->height=NodeHeight(pl);
    p->height=NodeHeight(p);
    plr->height=NodeHeight(plr);
 
    if(root==p)
        root=plr;
    return plr;
}
 
struct Node * RLRotation(struct Node *p)
{
    struct Node *pr=p->rchild;
    struct Node *prl=pr->lchild;
 
    p->rchild=prl->lchild;
    pr->lchild=prl->rchild;
 
    prl->rchild=pr;
    prl->lchild=p;
 
    pr->height=NodeHeight(pr);
    p->height=NodeHeight(p);
    prl->height=NodeHeight(prl);
 
    if(root==p)
        root=prl;
    return prl;
}
 
struct Node *RInsert(struct Node *root,long long key, int *lrot, int *rrot)
{   struct Node *p=root;
    struct Node *t=NULL;
    if(p==NULL)
    {
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=key;
        t->height=1;
        t->lchild=t->rchild=NULL;
        return t;
    }
    if(key < p->data)
        p->lchild=RInsert(p->lchild,key, lrot, rrot);
    else if(key > p->data)
        p->rchild=RInsert(p->rchild,key, lrot, rrot);
 
    p->height=NodeHeight(p);
 
    if(BalanceFactor(p)==2 && BalanceFactor(p->lchild)==1){
        (*lrot)+=1;
        return LLRotation(p);
    }
 
    else if(BalanceFactor(p)==2 && BalanceFactor(p->lchild)==-1){
        (*lrot)+=1;
        (*rrot)+=1;
        struct Node * a = LRRotation(p);
        return a;
    }
    else if(BalanceFactor(p)==-2 && BalanceFactor(p->rchild)==-1){
        (*rrot)+=1;
        return RRRotation(p);
    }
    else if(BalanceFactor(p)==-2 && BalanceFactor(p->rchild)==1){
        (*rrot)+=1;
        (*lrot)+=1;
        struct Node * q = RLRotation(p);
        return q;
    }
    return p;
}
 
 
long long subtree(struct Node *p){
    if (p == NULL)
        return 0;
    return (p->data + subtree(p->rchild) + subtree(p->lchild));
}
    
 
int main()
{
    int Q; long long x; char y[100]; char A[500][100]; long long B[500];
    scanf("%lld",&Q);
    for(int i=0;i<Q;i++){
    scanf("%s",y);
    strcpy(A[i],y);
    scanf("%lld",&x);
       B[i]=x;   
    }
    for (int i=0;i<Q;i++){
        char N[500];
        strcpy(N,A[i]);
        if (!strcmp(N,"insert")){
            root= RInsert(root,B[i]);
            int rrot = 0, lrot = 0;
            printf("%d %d\n",&rrot,&lrot);
        }
        else{
            struct Node * p = search(root,B[i]);
            if (p == NULL){
                printf("NA\n");
            }
            else{
                printf("%lld\n",subtree(p));
            }
        }
    }

}