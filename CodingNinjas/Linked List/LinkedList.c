#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef struct node {
    int data;
    struct node *next;
} node;

void swapData(node *start, node *end) {
    int temp1 = start->data;
    start->data = end->data;
    end->data = temp1;
}


node *bubbleSort(node *head)
{
	if (head == NULL || head -> next == NULL)
		return head;
	node *temp1 = head->next;
	while (temp1 != NULL) {
		node *temp2  = head;
		while (temp2 -> next != NULL) {
			if (temp2->data > temp2 -> next -> data)
				swapData(temp2, temp2->next);
				temp2 = temp2->next;
		}
		temp1 = temp1 -> next;
	}

	return head;
}

node *takeInput() {
    int data;
    scanf("%d", &data);
    node *head = NULL;
    node *tail = NULL;
    while(data != -1) {
        node *newNode = (node*) malloc(sizeof(node));
        newNode -> data = data;
        newNode -> next = NULL;
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail -> next = newNode;
            tail = newNode;
        }
        scanf("%d", &data);
    }
    return head;
}

node *rangeInput(int n) {
    int data;
    node *head = NULL;
    node *tail = NULL;
    for (int i = 0; i < n; i++) {
        node *newNode = (node*) malloc(sizeof(node));
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

void append(node **head, int new_data) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = new_data;
    new_node->next = NULL;
    
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    
    node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
}

node *insertNode(node *head, int i, int data) {
    node *newNode = (node*) malloc(sizeof(node));
    newNode -> data = data;
    int count = 0;
    node *temp = head;
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
        node *a = temp -> next;
        temp -> next = newNode;
        newNode -> next = a;
    }
    return head;
}


node *deleteNode(node *head, int i) {
    if (head == NULL)
        return head;

    int count = 0;
    node *temp = head;
    if (i == 0) {
        return temp -> next;
    }
    while (temp != NULL && count < i - 1) {
        temp = temp -> next;
        count++;
    }
    if (temp == NULL || temp -> next == NULL)
        return head;

    if (temp != NULL && count < i) {
        node *a = temp -> next;
        node *b = a -> next;
        temp -> next = b;
        free(a);
    }
    return head;
}

int length(node *head) {
	int count = 0;
    while (head != NULL) {
        count += 1;
        head = head -> next;
    }
	return count;
}

void printIthNode(node *head, int i) {
	int count = 0;
    while (head != NULL) {
        count += 1;
        head = head -> next;
        if (count == i) {
          printf("%d", head->data);
          break;
        }
    }
}

int findNode(node *head, int n){
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


int kthNode(node *head, int k) { 
    int count = 0;
    if (k == 0 || length(head) < k)
        return -1;
    if (k == 0)
        return head -> data;
    node *temp = head;
    while (count < k - 1) {
        temp = temp -> next;
        count++;
    }
    return temp -> data;
}

void printLL(node *head) {
    while (head != NULL) {
        printf("%d ", head -> data);
        head = head -> next;
    }
    printf("\n");
}

node *reverseData(node *head) {
    node *start = head;
	node *end = NULL;
    if (start == end)
        return head;
    while (start != end && end != start->next) {
        node *temp = start;
        while (temp -> next != end) {
            temp = temp -> next;
        }
        end = temp;
        swapData(start, end);
        start = start -> next;
    }
    return head;
}

void printReverseLL(node *head) {
    node *start = head;
    node *end = NULL;
    while (start != end) {
        node *temp = head;
        while (temp -> next != end) {
            temp = temp -> next;
        }
        printf("%d ", temp -> data);
        end = temp;
    }
    printf("\n");
}

node *midPoint(node *head)
{
	if (head == NULL)
		return head;
    node *slow = head;
	node *fast = head -> next;
	while (fast != NULL && fast -> next != NULL) {
		slow = slow -> next;
		fast = fast -> next -> next;
	}
	return slow;
}

bool isPalindrome(node *head) {
    node *start = head;
	node *end = NULL;
    if (start == end)
        return true;
    while (start != end && end != start->next) {
        node *temp = start;
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


node *mergeTwoSortedLinkedLists(node *head1, node *head2) {
    if (head1 == NULL) {
        return head2;
    } else if (head2 == NULL) {
        return head1;
    }

    node *head, *tail;

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

node *reverseLL(node *head) {
    node *curr = head;
    node *prev = NULL;
    node *temp = NULL;
    while (curr != NULL) {
        temp = curr->next;
        curr -> next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}


int main () {
    int n;
    scanf("%d", &n);
    node *head = rangeInput(n);
    scanf("%d", &n);
    int ans = kthNode(head, n);
    printf("%d", ans);
}