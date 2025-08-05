#include "BinaryTree.h"
#include <iostream>
using namespace std;
template <typename T>
class BST {
    Node<T> *root;

    public:
    BST() {
        root = NULL;
    }
     
    ~BST() {
        delete root;
    }

    private:
    Node<T> *deleteData(T data, Node<T> *node) {
        if (node == NULL) 
            return NULL;
        
        if (data < node->data) {
            node -> left = deleteData(data, node->left);
            return node;
        }
        else if (data > node->data) {
            node -> right = deleteData(data, node->right);
            return node;
        }
        else {
            if (node->left == NULL && node->right == NULL) {
                delete node;
                return NULL;
            } else if (node->right == NULL) {
                Node<T> *temp = node -> left;
                node-> left = NULL;
                delete node;
                return temp;
            } else if (node->left == NULL) {
                Node<T> *temp = node -> right;
                node-> right = NULL;
                delete node;
                return temp;
            } else {
                Node<T> *minNode = node -> right;
                while (minNode -> left != NULL) {
                    minNode = minNode -> left;
                }
                T rightMin = minNode -> data;
                node -> data = rightMin;
                node -> right = deleteData(rightMin, node->right);
                return node;
            }
        }
    }


    public:
    void deleteData(T data) {
        root = deleteData(data, root);

    }


    private:
    Node<T> *insert(T data, Node<T> *node) {
        if (node == NULL) {
            Node<T> *newNode = new Node<T>(data);
            return newNode;
        }
        if (data <= node->data) {
            node -> left = insert(data, node->left);
        }
        else {
            node -> right = insert(data, node->right);
        }
        return node;
    } 

    public: 
    void insert(T data) {
        root = insert(data, root);
        return;
    }

    private:
    bool hasData(T data, Node<T>*root) {
        if (root == NULL) {
            return false;
        }

        if (root->data == data) {
            return true;
        }
        if (root->data > data) {
            return hasData(data, root->left);
        } else 
            return hasData(data, root->right);
    }

    public:
    bool hasData(T data) {
        return hasData(data, root);
    }

    private:
    void printTree(Node<T>* root) {
        if (root == NULL)
            return;
        cout << root -> data << ":";
        if (root->left != NULL)
            cout << "L:" << root->left->data << ",";
        if (root->right != NULL)
            cout << "R:" << root->right->data << endl;
        else 
            cout << endl;
        cout << endl;
        printTree(root->left);
        printTree(root->right);
    }

    public:
    void print() {
        printTree(root);
    }
};
