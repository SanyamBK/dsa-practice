#include <bits/stdc++.h>
using namespace std;

class PriorityQueue {
    int *pq;
    int size;
    int capacity;

   public:
    PriorityQueue() {
        capacity = 1000;
        pq = new int(capacity);
        size = 0;
    }

    void insert(int element) {
        pq[size] = element;
        int i = size;
        while (i > 0 && pq[i] > pq[(i-1)/2]) {
            swap(pq[i], pq[(i-1)/2]);
            i = (i-1)/2;
        }
        size++;
    }

    int getMax() {
        return pq[0];
    }

    int removeMax() {
        if (isEmpty()) 
            return 0;
        int ans = pq[0];
        swap(pq[0], pq[size - 1]);
        size--;
        int i = 0;
        while ((pq[i] < pq[2*i+1] || pq[i] < pq[2*i+2]) && 2*i+2 < size) {
            int j = pq[2*i+1] > pq[2*i+2] ? 2*i+1 : 2*i+2;
            swap(pq[i], pq[j]);
            i = j;
        }
        return ans;
    }

    int size() { 
        return size;
    }

    bool isEmpty() {
        return size == 0;
    }

    
    void heapify(int *pq, int n, int i) {
        int max = i;
        if (2 * i + 1 < n && pq[2 * i + 1] > pq[max]) {
            max = 2 * i + 1;
        }
        if (2 * i + 2 < n && pq[2 * i + 2] > pq[max]) {
            max = 2 * i + 2;
        }

        if (max != i) {
            swap(pq[i], pq[max]);
            heapify(pq, n, max);
        }
    }

    void heapSort() {
        for (int i = size/2 - 1; i >= 0; i--) {
            heapify(pq, size, i);
        }

        for (int i = size - 1; i >= 0; i--) {
            swap(pq[0], pq[i]);
            heapify(pq, i, 0);
        }
    }

};

