#include <iostream>
#include <queue>
using namespace std;
#include <vector>

template <typename T>
class Node {
    public:
    T data;
    vector<Node*> children;

    Node(T data) {
        this -> data = data;
    }

    ~Node() {
        for (int i = 0; i < children.size(); i++) {
            delete children[i];
        }
    }
};

Node<int> *inputTreeLevelWise() {
    int rootData;
    cin >> rootData;
    Node<int> *root = new Node<int>(rootData);
    queue<Node<int>*> pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty()) {
        Node<int> *front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++) {
            int childData;
            cin >> childData;
            Node<int> *child = new Node<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}

void printTreeLevelWise(Node<int> *root) {
    if (root == NULL)
        return;
    queue<Node<int>*> pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty()) {
        Node<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << front->data << ":";
        for (int i = 0; i < front->children.size(); i++) {
            Node<int>* child = front->children[i];
            cout << child->data;
            if (i != front->children.size() - 1) {
                cout << ",";
            }
            pendingNodes.push(child);
        }
        cout << endl;
    }
}



Node<int> *inputTree() {
    int rootData;
    cout << "Enter Data" << endl;
    cin >> rootData;
    Node<int> *root = new Node<int>(rootData);

    int n;
    cout << "Enter no. of children" << endl;
    cin >> n;
    for (int i = 0; i < n; i++) {
        Node<int> *child = inputTree();
        root->children.push_back(child);
        
    }
    return root;    
}


void printTree(Node<int>* root) {
    if (root == NULL)
        return;
    cout << root -> data << ":";
    for (int i = 0; i < root->children.size(); i++) {
        cout << " " << root->children[i]->data;
    }    
    cout << endl;
    for (int i = 0; i < root->children.size(); i++) {
        printTree(root->children[i]);
    }
}

void preOrder(Node<int> *root) {
    cout << root->data << " ";
    for (int i = 0; i < root->children.size(); i++) {
        preOrder(root->children[i]);
    }
}

void postOrder(Node<int> *root) {
    for (int i = 0; i < root->children.size(); i++) {
        postOrder(root->children[i]);
    }
    cout << root->data << " ";
}

int numNodes(Node<int>* root) {
    if (root == NULL)
        return 0;
    int ans = 1;
    for (int i = 0; i < root->children.size(); i++) {
        ans += numNodes(root->children[i]);
    }
    return ans;
}

int getHeight(Node<int>* root) {
   if (root == NULL) {
       return 0;
   }
   
   int height = 1;
   for (int i = 0; i < root->children.size(); i++) {
       height = max(height, 1 + getHeight(root->children[i]));  
   }
   
   return height;
}


Node<int>* maxDataNode(Node<int>* root) {
    if (root == NULL) {
        return NULL;
    }
    
    int max = root->data;
    Node<int> *maxNode = root;

    for (int i = 0; i < root->children.size(); i++) {
        Node<int> *childMaxNode = maxDataNode(root->children[i]);
        if (childMaxNode != NULL && childMaxNode->data > max) {
            max = childMaxNode->data;
            maxNode = childMaxNode;
        }
    }
    
    return maxNode;
}

void printAtLevelK(Node<int>* root, int k) {
    if (root == NULL) {
       return ;
    }
    if (k == 0) {
        cout << root -> data << endl;
        return;
    }

    for (int i = 0; i < root->children.size(); i++) {
        printAtLevelK(root->children[i], k - 1);
    }
}


int main() {
    // Node<int> *root = new Node<int>(1);
    // Node<int> *node1 = new Node<int>(2);
    // Node<int> *node2 = new Node<int>(3);
    // root->children.push_back(node1);
    // root->children.push_back(node2);
    Node<int> *root = inputTreeLevelWise();
    printTreeLevelWise(root);
    cout << "Nodes: " << numNodes(root) << endl;
    postOrder(root);
}