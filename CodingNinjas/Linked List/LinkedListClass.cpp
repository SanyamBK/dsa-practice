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

Node *insertNode(Node *head, int i, int data) {
    Node *newNode = new Node(data);
    int count = 0;
    Node *temp = head;
    if (i == 0) {
        newNode -> next = head;
        head = newNode;
        return head;
    }
    while (temp != NULL && count < i - 1) {
        temp = temp -> next;
        count++;
    }
    if (temp != NULL) {
        Node *a = temp -> next;
        temp -> next = newNode;
        newNode -> next = a;
    }
    return head;
}

Node *deleteNode(Node *head, int i) {
    if (head == NULL)
        return head;

    int count = 0;
    Node *temp = head;
    if (i == 0) {
        Node *a = temp -> next;
        head = a;
        return head;
    }
    while (temp != NULL && count < i - 1) {
        temp = temp -> next;
        count++;
    }
    if (temp == NULL || temp -> next == NULL)
        return head;

    if (temp != NULL && count < i) {
        Node *a = temp -> next;
        Node *b = a -> next;
        temp -> next = b;
        delete a;
    }
    return head;
}


Node *midPoint(Node *head)
{
	if (head == NULL)
		return head;
    Node *slow = head;
	Node *fast = head -> next;
	while (fast != NULL && fast -> next != NULL) {
		slow = slow -> next;
		fast = fast -> next -> next;
	}
	return slow;
}

void printLL(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

int length(Node *head) {
	int count = 0;
    while (head != NULL) {
        count += 1;
        head = head -> next;
    }
	return count;
}

Node *appendLastNToFirst(Node *head, int n) {

	int len = length(head);
	if (n == 0 || n > len) 
		return head;
	Node *newhead = head;
	Node *newtail = NULL;
	for (int i = 0; i < len - n; i++) {
		newtail = newhead;
		newhead = newhead -> next;
	}

	Node *tail = newhead;
	while (tail -> next != NULL) 
		tail = tail -> next;

	tail -> next = head;
	newtail -> next = NULL;
	head = newhead;

    return head;
}

void printIthNode(Node *head, int i) {
	int count = 0;
    while (head != NULL) {
        count += 1;
        head = head -> next;
        if (count == i) {
          cout << head->data;
          break;
        }
    }
}

void swapData(Node *start, Node *end) {
    int temp1 = start->data;
    start->data = end->data;
    end->data = temp1;
}

Node *bubbleSort(Node *head)
{
	if (head == NULL || head -> next == NULL)
		return head;
	Node *temp1 = head->next;
	while (temp1 != NULL) {
		Node *temp2  = head;
		while (temp2 -> next != NULL) {
			if (temp2->data > temp2 -> next -> data)
				swapData(temp2, temp2->next);
				temp2 = temp2->next;
		}
		temp1 = temp1 -> next;
	}

	return head;
}

int findNode(Node *head, int n){
	int count = 0;
    if (head == NULL)
        return -1;
    while (head != NULL) {
        if (head -> data == n)
            return count;
        count += 1;
        head = head -> next;
    }
    return -1;
}

Node *mergeTwoSortedLinkedLists(Node *head1, Node *head2) {
    if (head1 == NULL) {
        return head2;
    } else if (head2 == NULL) {
        return head1;
    }

    Node *head, *tail;

    if (head1->data <= head2->data) {
        head = head1;
        head1 = head1->next;
    } else {
        head = head2;
        head2 = head2->next;
    }
    tail = head;

    while (head1 != NULL && head2 != NULL) {
        if (head1->data <= head2->data) {
            tail->next = head1;
            head1 = head1->next;
        } else {
            tail->next = head2;
            head2 = head2->next;
        }
        tail = tail->next;
    }

    if (head1 == NULL) {
        tail->next = head2;
    } else {
        tail->next = head1;
    }

    return head;
}

void printReverseLL(Node *head) {
    Node *start = head;
    Node *end = NULL;
    while (start != end) {
        Node *temp = head;
        while (temp -> next != end) {
            temp = temp -> next;
        }
        cout << temp -> data << " ";
        end = temp;
    }
    cout << endl;
}

bool isPalindrome(Node *head) {
    Node *start = head;
	Node *end = NULL;
    if (start == end)
        return true;
    while (start != end && end != start->next) {
        Node *temp = start;
        while (temp -> next != end) {
            temp = temp -> next;
        }
        if (start -> data != temp -> data)
            return false;
        end = temp;
        start = start -> next;
    }
    return true;
}

Node *reverseLL(Node *head){
    Node *curr = head;
    Node *prev = NULL;
    Node *temp = NULL;
    while (curr != NULL) {
        temp = curr->next;
        curr -> next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}

int pop(Node *head) {
    Node *tail = head;
    while (tail -> next -> next != NULL) {
    tail = tail -> next;
    }
    int ans = tail -> next -> data;
    tail -> next = NULL;
    tail = NULL;
    return ans;
}

int main () {
    Node *head = takeInput();
    // head = reverseLL(head);
    printLL(head);
    cout << pop(head) << endl;
    printLL(head);

}