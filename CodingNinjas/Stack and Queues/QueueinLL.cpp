#include <iostream>

class Node {
    public :
    int data;
    Node *next;

    Node(int data) {
        this->data = data;
        next = NULL;
    }
};

class Queue {
	Node *head;
	Node *tail;
	int size;
   public:
    Queue() {
		head = NULL;
		tail = NULL;
		size = 0;
	}

	int getSize() {
		return size;
	}

    bool isEmpty() {
		return size == 0;
	}

    void enqueue(int data) {
		Node *newNode = new Node(data);
		if (head == NULL) {
			head = newNode;
			tail = newNode;
			tail -> next = NULL;
		} else {
			tail -> next = newNode;
			tail = newNode;
			tail -> next = NULL;
		}
		size++;
	}

    int dequeue() {
		if (head == NULL)
			return -1;
        int ans = head -> data;
		head = head -> next;
		size--;
		return ans;
    }

    int front() {
		if (head == NULL)
			return -1;
        return head -> data;
    }
};

void reverseQueue(Queue &input) {
  if (input.getSize()<=1)
    return;

    int front = input.front();
    input.dequeue();
    reverseQueue(input);

    input.enqueue(front);
}