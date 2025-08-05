#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_CHILD_DIRS 20

typedef struct DirectoryNode {
    char* name;
    struct DirectoryNode* parent;
    struct DirectoryNode* child_dir[MAX_CHILD_DIRS];
    int num_child_dirs;
} DirectoryNode;

DirectoryNode* createDirectoryNode(char* name, DirectoryNode* parent) {
    DirectoryNode* new_dir = (DirectoryNode*) malloc(sizeof(DirectoryNode));
    new_dir->name = name;
    new_dir->parent = parent;
    new_dir->num_child_dirs = 0;
    return new_dir;
}

int compare(const void* a, const void* b) {
    DirectoryNode* dirA = (DirectoryNode*)a;
    DirectoryNode* dirB = (DirectoryNode*)b;
    return strcmp((dirA)->name, (dirB)->name);
}

DirectoryNode* findDirectory(DirectoryNode* currentDir, char* directoryName) {
    // Traverse the linked list until the end or the target directory is found
    for (int i = 0; i < currentDir -> num_child_dirs; i++) {
        if (strcmp(currentDir->child_dir[i]->name, directoryName) == 0) {
            return currentDir->child_dir[i];  // Found the directory, return its node
        }
    }
    return NULL;  // Directory not found
}


void *makeDirectory(char *name, DirectoryNode *current_dir) {
    if (current_dir->num_child_dirs == MAX_CHILD_DIRS || findDirectory(current_dir, name) != NULL) {
        printf("-1\n");
        return;
    } else {
        DirectoryNode* new_dir = createDirectoryNode(name, current_dir);
        current_dir->child_dir[current_dir->num_child_dirs++] = new_dir;
        return;
    }
}


void printWorkingDirectory(DirectoryNode *currdir) {
    if (currdir->parent == NULL) {
        printf("%s", currdir->name);
        return;
    }
    printWorkingDirectory(currdir->parent);
    printf("/%s", currdir->name);
}

DirectoryNode *changeDirectory(DirectoryNode *currdir, char *newdir) {
    if (strcmp(newdir, "..") == 0) {
        if (currdir->parent == NULL) {
            printf("-1\n");
            return currdir;
        }
        currdir = currdir->parent;
        return currdir;
    }

    DirectoryNode *newDir =  findDirectory(currdir, newdir);
    if (newDir != NULL) {
        return newDir;
    }
    printf("-1\n");
    return currdir;
}

void removeDirectory(DirectoryNode *current_dir, char *dir) {
    for (int i = 0; i < current_dir->num_child_dirs; i++) {
        if (strcmp(current_dir->child_dir[i]->name, dir) == 0) {
            for (int j = i+1; j < current_dir->num_child_dirs; j++) {
                current_dir->child_dir[j-1] = current_dir->child_dir[j];
            }
            current_dir->num_child_dirs--;
            return;
        }
    }
    printf("-1\n");
}


void listDirectories(DirectoryNode *currdir) {
    if (currdir == NULL) {
        return;
    }
    DirectoryNode *child = currdir->next;
    if (child == NULL) {
        printf("\n");
        return;
    }

    char dirs[1000][1000];
    int i = 0;
    while (child != NULL) {
        strcpy(dirs[i], child->data);
        child = child->next;
        i++;
    }
    
    for (int j = 0; j < i - 1; j++) {
        for (int k = 0; k < i - j - 1; k++) {
            if (strcmp(dirs[k], dirs[k+1]) > 0) {
                char temp[1000];
                strcpy(temp, dirs[k]);
                strcpy(dirs[k], dirs[k+1]);
                strcpy(dirs[k+1], temp);
            }
        }
    }
    for (int j = 0; j < i; j++) {
        printf("%s ", dirs[j]);
    }
    printf("\n");
}


int main () {

    Node *root = createNode("root");
    FileSystem *fs = createFileSystem(NULL);
    fs -> child = root;
    fs->subDirs++;
    int q;
    FileSystem *cfs = createFileSystem(root);
    scanf("%d", &q);
    while (q--) {
        int n;
        scanf("%d", &n);
        char command[3][1000];
        for (int i = 0; i < n; i++) {
            scanf("%s", command[i]);
        }
        if (strcmp(command[0], "pwd") == 0) {
            printWorkingDirectory(root);
            printf("\n");
        }
        if (strcmp(command[0], "ls") == 0) {
            listDirectories(root);
        }
        if (strcmp(command[0], "mkdir") == 0) {
            makeDirectory(command[1], root);

        }
        if (strcmp(command[0], "cd") == 0) {
            fs = changeDirectory(root, command[1]);
        }
        if (strcmp(command[0], "rm") == 0) {
            removeDirectory(root, command[2]);
        }
    }

    free(root);
    return 0;
}