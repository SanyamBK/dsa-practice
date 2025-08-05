#include <iostream>
using namespace std;

template <typename T>
class Queue {
    T *array;
    int head;
    int tail;
    int size;
    int capacity;

    public:
    Queue() {
        array = new T[10];
        tail = 0;
        head = -1;
        size = 0;
        capacity = 10;
    }

    void Enqueue(T element) {
        if (size == capacity) {
            int *newArray = new int[2*capacity];
            int j = 0;
            for (int i = head; i < capacity; i++) {
                newArray[j] = array[i];
                j++;
            }
            for (int i = 0; i < head; i++) {
                newArray[j] = array[i];
            }
            capacity *= 2;
            delete [] array;
            array = newArray;
        }
    array[tail] = element;
    tail = (tail+1)%capacity;
    size++;
    if (head == -1)
        head++;
    }


    T Dequeue() {
        if (isEmpty()) {
            cout << "Queue Empty" << endl;
            return 0;
        }

        T ans = array[head];
        head = (head+1)%capacity;
        size--;
        return ans;
    }

    T front() {
        if (isEmpty()) {
            cout << "Queue Empty" << endl;
            return 0;
        }
        return array[head];
    }

    bool isEmpty() {
        return size == 0;
    }

    int length() {
        return size;
    }
};



int main () {
    Queue<int> q;
    q.Enqueue(10);
    q.Enqueue(20);
    q.Enqueue(30);
    q.Enqueue(10);
    q.Enqueue(20);
    q.Enqueue(30);
    q.Enqueue(10);
    q.Enqueue(20);
    q.Enqueue(30);
    q.Enqueue(10);
    q.Enqueue(20);
    q.Enqueue(30);
    cout << q.front() << endl;
    cout << q.Dequeue() << endl;
    cout << q.Dequeue() << endl;
    cout << q.length() << endl;
    

}
