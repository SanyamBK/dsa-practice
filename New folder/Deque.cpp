#include <bits/stdc++.h>
class Deque
{
public:
    // Initialize your data structure.

    int *array;
    int head;
    int tail;
    int size;
    int capacity;

    Deque(int n)
    {
        // Write your code here.
        array = new int[n];
        head = -1;
        tail = 0;
        size = 0;
        capacity = n;
    }

    // Pushes 'X' in the front of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushFront(int x)
    {
        // Write your code here.
        if (size == capacity)
        {
            return false;
        }
        if (head == -1)
        {
            head = 0;
            tail = 0;
        }
        else
        {
            head = (head - 1 + capacity) % capacity;
        }
        array[head] = x;
        size++;
        return true;
    }

    // Pushes 'X' in the back of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushRear(int x)
    {
        // Write your code here.
        if (size == capacity)
        {
            return false;
        }
        if (head == -1)
        {
            head = 0;
            tail = 0;
        }
        else
        {
            tail = (tail + 1) % capacity;
        }
        array[tail] = x;
        size++;
        return true;
    }

    // Pops an element from the front of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popFront()
    {
        // Write your code here.
        if (size == 0)
        {
            return -1;
        }
        int ans = array[head];
        head = (head + 1) % capacity;
        size--;
        if (size == 0)
        {
            head = -1;
            tail = 0;
        }
        return ans;
    }

    // Pops an element from the back of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popRear()
    {
        // Write your code here.
        if (size == 0)
        {
            return -1;
        }
        int ans = array[tail];
        tail = (tail - 1 + capacity) % capacity;
        size--;
        if (size == 0)
        {
            head = -1;
            tail = 0;
        }
        return ans;
    }

    // Returns the first element of the deque. If the deque is empty, it returns -1.
    int getFront()
    {
        // Write your code here.
        if (size == 0)
        {
            /* code */
            return -1;
        }

        return array[head];
    }

    // Returns the last element of the deque. If the deque is empty, it returns -1.
    int getRear()
    {
        // Write your code here.
        if (size == 0)
        {
            /* code */
            return -1;
        }
        return array[tail];
    }

    // Returns true if the deque is empty. Otherwise returns false.
    bool isEmpty()
    {
        // Write your code here.
        return size == 0;
    }

    // Returns true if the deque is full. Otherwise returns false.
    bool isFull()
    {
        // Write your code here.
        return size == capacity;
    }
};