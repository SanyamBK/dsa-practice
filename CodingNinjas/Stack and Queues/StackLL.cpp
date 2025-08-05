#include <iostream>
using namespace std;

template <typename T> 
class Node {
    public:
    T data;
    Node *next;

    Node(T data) {
        this -> data = data;
        next = NULL;
    }

};

template <typename T>
class Stack {
    Node<T> *head;
    int stackSize;

    public:
    Stack () {
        head = NULL;
        stackSize = 0;
    }

    void push(T data) {
        Node<T> *newNode = new Node<T>(data);
        if (head == NULL) {
            head = newNode;
            stackSize++;

        } else {
            Node<T> *temp = head;
            head = newNode;
            head -> next = temp;
            stackSize++;
        }

    }

    T pop() {
        if (isEmpty()) {
            cout << "Stack Empty" << endl;
            return 0;
        }
        
        T ans = head -> data;
        head = head -> next;
        stackSize--;
        return ans;
    }

    bool isEmpty() {
        return head == NULL;
    }

    T top() {
        if (isEmpty()) {
            cout << "Stack Empty" << endl;
            return 0;
        }
        return head->data;
    }

    int size() {
        return stackSize;
    }

};
    
