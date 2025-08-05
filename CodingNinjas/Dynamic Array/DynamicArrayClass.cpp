#include <iostream>
using namespace std;

class DynamicArray {
    int *array;
    int nextIndex;
    int capacity;

    public:
    DynamicArray() {
        array = new int[5];
        nextIndex = 0;
        capacity = 5;
    }

    DynamicArray(DynamicArray const &d) {
        this -> array = new int[d.capacity];
        for (int i = 0; i < d.nextIndex; i++) {
            this -> array[i] = d.array[i];
        }
        this -> nextIndex = d.nextIndex;
        this -> capacity = d.capacity;
    }

    void operator = (DynamicArray const &d) {
        this -> array = new int[d.capacity];
        for (int i = 0; i < d.nextIndex; i++) {
            this -> array[i] = d.array[i];
        }
        this -> nextIndex = d.nextIndex;
        this -> capacity = d.capacity;
    }

    void append(int element) {
        if (nextIndex == capacity) {
            int *newArray = new int[2*capacity];
            for (int i = 0; i < capacity; i++) {
                newArray[i] = array[i];
            }
            capacity *= 2;
            delete [] array;
            array = newArray;
        }
        array[nextIndex] = element;
        nextIndex++;
    }

    void get(int i) const {

        if (i > capacity) {
            cout << "Out of Limit!!!" << endl;
            return ;
        }

        else if (i > nextIndex) {
            cout << "Out of Index!!" << endl;
            return ;
        }

        cout << array[i] << endl;
        return;
    }

    void insert(int index, int element) {
        if (index == nextIndex) 
            append(element);
        
        else if (index < nextIndex) {
            if (nextIndex < capacity) {
                for (int i = nextIndex + 1; i > index; i--) {
                    array[i] = array[i-1];
                }
                nextIndex ++;
            }
            else {
                append(array[nextIndex]);
                for (int i = nextIndex - 2; i > index; i--) {
                    array[i] = array[i-1];
                }
            }
            array[index] = element;
        }

        else 
            array[index] = element;
    }

    int Search(int element) {
        for (int i = 0; i < nextIndex; i++) {
            if (array[i] == element)
                return i;
        }
        return -1;
    }

    void deleteElement(int element) {
        int index = Search(element);
        for(int i = index; i < nextIndex - 1; i++) {
            array[i] = array[i+1];
        }
        nextIndex--;
    }

    int pop(int index) {
        int element = array[index];
        for(int i = index; i < nextIndex - 1; i++) {
            array[i] = array[i+1];
        }
        nextIndex--;
        return element;
    } 

    void printArray() {
        for (int i = 0; i < nextIndex; i++) {
            cout << array[i] <<" ";
        }
        cout << endl;
    }

    void Capacity() {
        cout << "Current Capacity: "<< capacity << endl;
    }

    void printIndex() const {
        cout << nextIndex << endl;
    }
};