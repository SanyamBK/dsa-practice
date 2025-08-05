#include <iostream>
#include <vector>
using namespace std;

// Stack structure
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct Stack
{
    Node *head;
    int stackSize;
} Stack;

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Stack *createStack()
{
    Stack *newStack = (Stack *)malloc(sizeof(Stack));
    newStack->head = NULL;
    newStack->stackSize = 0;
    return newStack;
}

void push(Stack *s, int data)
{
    Node *newNode = createNode(data);
    if (s->head == NULL)
    {
        s->head = newNode;
        s->stackSize++;
    }
    else
    {
        Node *temp = s->head;
        s->head = newNode;
        s->head->next = temp;
        s->stackSize++;
    }
}

int pop(Stack *s)
{
    if (s->head == NULL)
    {
        cout << "Stack Empty\n";
        return 0;
    }
    int ans = s->head->data;
    s->head = s->head->next;
    s->stackSize--;
    return ans;
}

int isEmpty(Stack *s)
{
    return s->head == NULL;
}

int top(Stack *s)
{
    if (isEmpty(s))
    {
        cout << "Stack Empty\n";
        return 0;
    }
    return s->head->data;
}

// Queue structure
typedef struct Queue
{
    Node *head;
    Node *tail;
    int size;
} Queue;

Node *newNode(int data)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

Queue *createQueue()
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->head = NULL;
    queue->tail = NULL;
    queue->size = 0;
    return queue;
}

int getSize(Queue *queue)
{
    return queue->size;
}

int isEmpty(Queue *queue)
{
    return queue->size == 0;
}

void enqueue(Queue *queue, int data)
{
    Node *new_node = newNode(data);
    if (queue->head == NULL)
    {
        queue->head = new_node;
        queue->tail = new_node;
    }
    else
    {
        queue->tail->next = new_node;
        queue->tail = new_node;
    }
    queue->size++;
}

int dequeue(Queue *queue)
{
    if (queue->head == NULL)
        return -1;
    int ans = queue->head->data;
    queue->head = queue->head->next;
    queue->size--;
    return ans;
}

// Function to find the next greater element in circular array using Stack
vector<int> nextGreaterCircular(vector<int> &nums)
{
    int n = nums.size();
    vector<int> result(n, -1);
    Stack *stack = createStack();
    for (int i = 0; i < 2 * n; ++i)
    {
        int num = nums[i % n];
        while (!isEmpty(stack) && nums[top(stack)] < num)
        {
            result[top(stack)] = num;
            pop(stack);
        }
        if (i < n)
        {
            push(stack, i);
        }
    }
    free(stack);
    return result;
}

int main()
{
    // Testing next greater element in circular array
    vector<int> nums = {1, 2, 3, 4, 3};
    vector<int> result = nextGreaterCircular(nums);
    cout << "Next greater elements in circular array: ";
    for (int num : result)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
