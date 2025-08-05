#include <iostream>
using namespace std;
#include "BinaryTree.h"
#include <queue>

Node<int> *takeInput() {
    int rootData;
    cin >> rootData;
    if (rootData == -1)
        return NULL;
    
    Node<int> *root = new Node<int>(rootData);
    Node<int> *leftChild = takeInput();
    Node<int> *rightChild = takeInput();
    root->left = leftChild;
    root->right = rightChild;
    return root;
}

void printTree(Node<int> *root) {
    if (root == NULL)
        return;

    cout << root -> data << ": ";
    if (root->left != NULL)
        cout << root->left->data << " ";
    if (root->right != NULL)
        cout << root->right->data << " ";
    cout << endl;
    printTree(root->left);
    printTree(root->right);
}

Node<int> *inputBT() {
    int rootData;
    cin >> rootData;
    if (rootData == -1)
        return NULL;

    Node<int> *root = new Node<int>(rootData);
    queue<Node<int>*> pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty()) {
        Node<int> *front = pendingNodes.front();
        pendingNodes.pop();
        int leftChild;
        cin >> leftChild;
        if (leftChild != -1) {
            Node<int> *child = new Node<int>(leftChild);
            front->left = child;
            pendingNodes.push(child);
        }
        int rightChild;
        cin >> rightChild;
        if (rightChild != -1) {
            Node<int> *child = new Node<int>(rightChild);
            front->right = child;
            pendingNodes.push(child);
        }
    }
    return root;
}

void printBT(Node<int> *root) {
    if (root == NULL)
        return;
    queue<Node<int>*> pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty()) {
        Node<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << front->data << ":";
        Node<int>* left = front->left;
        if (left != NULL) {
            cout << "L" << left->data << ",";
            pendingNodes.push(left);
        } else 
            cout << "L" << -1 << ",";

        Node<int>* right = front->right;
        if (right != NULL) {
            cout << "R" << right->data << endl;
            pendingNodes.push(right);
        } else 
            cout << "R" << -1 << endl;
    }
} 

void printLevelATNewLine(Node<int> *root) {
    queue<Node<int> *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty()) {
        Node<int> *first = q.front();
        q.pop();
        if (first == NULL) {
            if (q.empty()) {
                break;
            }
            cout << endl;
            q.push(NULL);
            continue;
        }
        cout << first->data << " ";
        if (first->left != NULL) {
            q.push(first->left);
        }
        if (first->right != NULL) {
            q.push(first->right);
        }
    }
}

int numNodes(Node<int> *root) {
    if (root == NULL)
        return 0;
    return 1 + numNodes(root->left) + numNodes(root->right);
}

int height(Node<int> *root) {
    if (root == NULL)
        return 0;
    return max(1 + height(root->left), 1 + height(root->right));
}

pair<int, int> Diameter(Node<int> *root) {
    if (root == NULL) {
        pair<int, int> p;
        p.first = 0;
        p.second = 0;
        return p;
    }
    pair<int, int> leftans = Diameter(root->left);
    pair<int, int> rightans = Diameter(root->right);

    int ld = leftans.second;
    int lh = leftans.first;
    int rd = rightans.second;
    int rh = rightans.first;

    int height = 1 + max(lh, rh);
    int diameter = max(lh + rh, max(ld, rd));
    pair<int, int> p;
    p.first = height;
    p.second = diameter;
    return p;
}

int main() {
    Node<int> *root = inputBT();
    printBT(root);
    delete root;
}