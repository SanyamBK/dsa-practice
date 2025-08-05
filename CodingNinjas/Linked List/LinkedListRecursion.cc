#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node *next;

    Node(int data) {
        this -> data = data;
        next = NULL;
    }


};

Node *takeInput() {
    int data;
    cin >> data;
    Node *head = NULL;
    Node *tail = NULL;
    while (data != -1) {
        Node *newNode = new Node(data);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail -> next = newNode;
            tail = newNode;
        }
        cin >> data;
    }
    return head;
}


Node *rangeInput(int n) {
    int data;
    Node *head = NULL;
    Node *tail = NULL;
    for (int i = 0; i < n; i++) {
        Node *newNode = (Node*) malloc(sizeof(Node));
        scanf("%d", &data);
        newNode -> data = data;
        newNode -> next = NULL;
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail -> next = newNode;
            tail = newNode;
        }

    }
    return head;
}

Node* insertNode(Node *head, int i, int data) {
	if (head == NULL)
		return head;
	
	if (i == 0) {
		Node *newNode = new Node(data);
		newNode -> next = head;
		return newNode;
	}
	    if (i == 1) {
        Node* newNode = new Node(data);
        newNode->next = head->next;
        head->next = newNode;
        return head;
    }

		Node *rest = insertNode(head->next, i-1, data);
		head -> next = rest;
		return head;
}

Node *deleteNode(Node *head, int pos) {
	if (head == NULL)
		return head;

	if (pos == 0) {
		head = head -> next;
		return head;
	}
	Node *rest = deleteNode(head->next, pos-1);
	head -> next = rest;
	return head;
}

int length(Node *head) {
	if (head == NULL)
		return 0;
	return 1 + length(head->next);
}

int findNode(Node *head, int n){
    if (head == NULL)
        return -1;
    if (head -> data == n)
        return 0;

    int ans = findNode(head->next, n);
    if (ans == -1)
        return -1;
    return 1 + ans;
}

int kthNode(Node *head, int k) {
    if (head == NULL) 
        return -1;
    if (k == 1) 
        return head->data;
    return kthNode(head->next, k-1);
}


void printLL(Node *head) {
    if (head == NULL) {
        cout << endl;
        return;
    }
    cout << head -> data << " ";
    printLL(head->next);
}

void printReverseLL(Node* head) {
    if (head == NULL) {
        return;
    }
    
    printReverseLL(head->next);
    cout << head->data << " ";
}

Node* reverseLL(Node *head) {
    if(head == NULL || head -> next == NULL)
        return head;
    Node *smallAns = reverseLL(head -> next);
    Node *temp = smallAns; 
    while(temp -> next != NULL) 
        temp = temp -> next; 

    temp -> next = head; 
    head -> next = NULL;
    return smallAns;
}

class Pair {
    public:
    Node *head;
    Node *tail;    
};

Pair reverseLL_2(Node *head) {
    if (head == NULL || head ->next == NULL) {
        Pair ans;
        ans.head = head;
        ans.tail = head;
        return ans;
    }

    Pair smallAns = reverseLL_2(head->next);
    smallAns.tail ->next = head;
    head -> next = NULL;
    Pair ans;
    ans.head = smallAns.head;
    ans.tail = head;
    return ans;
};

Node* reverseLL_3(Node *head) {
    if(head == NULL || head -> next == NULL) 
        return head;

    Node *smallAns = reverseLL_3(head -> next);
    Node *tail = head -> next;
    tail -> next = head; 
    head -> next = NULL;
    return smallAns;
}

bool isPalin(Node* &left, Node* right) { // Arguements pass -> head, head
    if (!right) {
        return true; 
    }

    bool isPal = isPalin(left, right->next); 
    if (!isPal) {
        return false;
        }

    bool isEqual = (left->data == right->data); 
        left = left->next; 

    return isEqual; 
}



Node *midPoint(Node *slow, Node *fast) {
	if (fast == NULL || fast -> next == NULL )
		return slow;
	return midPoint(slow->next, fast->next->next);
}
Node *midPoint(Node *head)
{	if (head == NULL)
		return head;
	return midPoint(head, head->next);
}

Node *mergeTwoSortedLinkedLists(Node *head1, Node *head2) {
    if (head1 == NULL) 
        return head2;
    else if (head2 == NULL) 
        return head1;

	Node *head = NULL;
	if (head1 -> data <= head2 -> data) {
		head = head1;
		head -> next = mergeTwoSortedLinkedLists(head1->next, head2);
	} else {
		head = head2;
		head -> next = mergeTwoSortedLinkedLists(head1, head2->next);;
	}
	return head;
}



int main () {
    int n, k;
    Node *head = takeInput();
    // scanf("%d", &k);
    head = reverseLL_2(head).head;
    printLL(head);
}

                                                                                                                 