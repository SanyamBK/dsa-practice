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