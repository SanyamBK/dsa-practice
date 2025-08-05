#include <iostream>
using namespace std;

template <typename T>

class Stack {
    T *data;
    int nextIndex;
    T capacity;
    
    public:
    
    Stack () {
        data = new T[5];
        nextIndex = 0;
        capacity = 5;
    }

    bool isEmpty() {
        return nextIndex == 0;
    }

    int size() {
        return nextIndex;
    }

    void push(T element) {
        if (nextIndex == capacity) {
            T *newData = new T[2*capacity];
            for (int i = 0; i < capacity; i++) {
                newData[i] = data[i];
            }
            capacity *= 2;
            delete [] data;
            data = newData;
        }
        data[nextIndex] = element;
        nextIndex++;
    }

    T pop() {
        if (isEmpty()) {
            cout << "Stack is Empty" << endl;
            return 0;
        }
        nextIndex--;
        return data[nextIndex];
    }

    T top() {
        if (isEmpty()) {
            cout << "Stack is Empty" << endl;
            return 0;
        }
        return data[nextIndex-1];
    }
};
