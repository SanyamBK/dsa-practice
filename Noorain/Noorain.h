#include <iostream>
using namespace std;

template <typename T>
class Node {
    public:
    T data;
    Node *left;
    Node *right;

    Node(T data) {
        
        this -> data = data;
        left = NULL;
        right = NULL;
    }

    ~Node() {
        delete left;
        delete right;
    }
};

// creating a class BST
template <typename T>
class BST
{
    Node<T> *root;


// constructor and destructor
public:
    BST()
    {
        root = NULL;
    }

    ~BST()
    {
        delete root;
    }

Node<T> *getRoot()
{
    return root;
}
// member functions

void insert(T data);
void delete(T data);
bool hasData(T data);
void inOrder();
void preOrder();
void postOrder();
int height();
int numNodes();

// insert operation
private:
    Node<T> *insertNode(T data, Node<T> *node)
    {
        if (node == NULL)
        {
            Node<T> *newNode = new Node<T>(data);
            return newNode;
        }
        if (data <= node->data)
        {
            node->left = insertNode(data, node->left);
        }
        else
        {
            node->right = insertNode(data, node->right);
        }
        return node;
    }

// this function is called by the user
public:
    void insert(T data)
    {
        root = insertNode(data, root);
        return;
    }

// delete operation
private:
    Node<T> *deleteNode(T data, Node<T> *node)
    {
        if (node == NULL)
            return NULL;

        if (data < node->data)
        {
            node->left = deleteNode(data, node->left);
            return node;
        }
        else if (data > node->data)
        {
            node->right = deleteNode(data, node->right);
            return node;
        }
        else
        {
            if (node->left == NULL && node->right == NULL)
            {
                delete node;
                return NULL;
            }
            else if (node->right == NULL)
            {
                Node<T> *temp = node->left;
                node->left = NULL;
                delete node;
                return temp;
            }
            else if (node->left == NULL)
            {
                Node<T> *temp = node->right;
                node->right = NULL;
                delete node;
                return temp;
            }
            else
            {
                Node<T> *minNode = node->right;
                while (minNode->left != NULL)
                {
                    minNode = minNode->left;
                }
                T rightMin = minNode->data;
                node->data = rightMin;
                node->right = deleteNode(rightMin, node->right);
                return node;
            }
        }
    }

// this function is called by the user
public:
    void delete(T data)
    {
        root = deleteNode(data, root);
    }

// search operation
// private:
//     bool hasData(T data, Node<T> *node)
//     {
//         if (node == NULL)
//             return false;
//         if (node->data == data)
//             return true;
//         if (data < node->data)
//             return hasData(data, node->left);
//         else
//             return hasData(data, node->right);
//     }

// // this function is called by the user
// public:
//     bool hasData(T data)
//     {
//         return hasData(data, root);
//     }

/* traversal operation */ 

// inorder traversal:
private:
    void inOrder(Node<T> *node)
    {
        if (node == NULL)
            return;
        inOrder(node->left);
        cout << node->data << " ";
        inOrder(node->right);
    }

// this function is called by the user
public:
    void printInOrder()
    {
        inOrder(root);
        cout << endl;
    }

// preorder traversal:
private:
    void preOrder(Node<T> *node)
    {
        if (node == NULL)
            return;
        cout << node->data << " ";
        preOrder(node->left);
        preOrder(node->right);
    }

// this function is called by the user
public:
    void printPreOrder()
    {
        preOrder(root);
        cout << endl;
    }

// postorder traversal:
private:
    void postOrder(Node<T> *node)
    {
        if (node == NULL)
            return;
        postOrder(node->left);
        postOrder(node->right);
        cout << node->data << " ";
    }

// this function is called by the user
public:
    void printPostOrder()
    {
        postOrder(root);
        cout << endl;
    }

// height calculation
public:
    int height(Node<T> *node)
    {
        if (root == NULL) 
            return -1;
        if (node == NULL)
            return 0;
        return 1 + max(height(node->left), height(node->right));
    }


// number of nodes calculation
public:
    int numNodes(Node<T> *node)
    {
        if (node == NULL)
            return 0;
        return 1 + numNodes(node->left) + numNodes(node->right);
    }

};
