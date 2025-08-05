#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

class MinHeap {
private:
    int *heapArray;
    int capacity;
    int heapSize;

    void heapify(int i) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int largest = i;

        if (left < heapSize && heapArray[left] > heapArray[largest])
            largest = left;

        if (right < heapSize && heapArray[right] > heapArray[largest])
            largest = right;

        if (largest != i) {
            swap(heapArray[i], heapArray[largest]);
            heapify(largest);
        }
    }

    int parent(int i) {
        return (i - 1) / 2;
    }

public:
    MinHeap(int capacity) : capacity(capacity), heapSize(0) {
        heapArray = new int[capacity];
    }

    ~MinHeap() {
        delete[] heapArray;
    }

    void push(int value) {
        // If heap is full, we make a new heap with double the capacity
        if (heapSize == capacity) {
            int *temp = new int[2 * capacity];
            for (int i = 0; i < capacity; i++)
                temp[i] = heapArray[i];
            delete[] heapArray;
            heapArray = temp;
            capacity *= 2;
        }

        int i = heapSize++;
        heapArray[i] = value;

        while (i != 0 && heapArray[parent(i)] > heapArray[i]) {
            swap(heapArray[i], heapArray[parent(i)]);
            i = parent(i);
        }
    }

    void pop() {
        if (heapSize == 0) {
            return;
        }

        heapArray[0] = heapArray[--heapSize];
        heapify(0);
    }

    int extractMin() {
        if (heapSize == 0) {
            return INT_MIN; // Return INT_MIN if heap is empty
        }

        int minV = heapArray[0];
        pop();
        return minV;
    }

    void heapSort() {
        int heapSizeCopy = heapSize;
        for (int i = heapSize / 2 - 1; i >= 0; i--)
            heapify(i);

        for (int i = heapSize - 1; i > 0; i--) {
            swap(heapArray[0], heapArray[i]);
            heapSize--;
            heapify(0);
        }
        heapSize = heapSizeCopy; // Restore heapSize to its original value
    }
 
    void printHeap() {
        for (int i = 0; i < heapSize; i++)
            cout << heapArray[i] << " ";
        cout << endl;
    }
};

int main() {
    MinHeap minHeap(10);
    minHeap.push(3);
    minHeap.push(2);
    minHeap.push(15);
    minHeap.push(5);
    minHeap.push(4);
    minHeap.push(45);

    cout << "Heap: ";
    minHeap.printHeap();

    cout << "Extract Min: " << minHeap.extractMin() << endl;
    cout << "Heap after extract min: ";
    minHeap.printHeap();

    minHeap.heapSort();
    cout << "Heap after heap sort: ";
    minHeap.printHeap();

    return 0;
}