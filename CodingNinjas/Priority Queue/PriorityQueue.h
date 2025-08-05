#include <bits/stdc++.h>
using namespace std;

#define min(a, b) a < b ? a : b

class PriorityQueue {
    vector<int> pq;
    int i;

    public:

    PriorityQueue() {


                
    }

    bool isEmpty() {
        return pq.size() == 0;
    }

    int size() {
        return pq.size();
    }

    int getMin() {
        if (isEmpty()) 
            return INT_MIN;
        return pq.at(0);
    }

    void insert(int element) {
        pq.push_back(element);
        int i = size() - 1;
        while (i > 0 && pq[i] < pq[(i-1)/2]) {
            swap(pq[i], pq[(i-1)/2]);
            i = (i-1)/2;
        }

    }
    

    int extractMin() {
        if (isEmpty()) 
            return INT_MIN;
        int min = pq[0];
        swap(pq[0], pq[pq.size() - 1]);
        pq.pop_back();
        int i = 0;
        while ((pq[i] > pq[2*i+1] || pq[i] > pq[2*i+2]) && 2*i+2 < pq.size()) {
            int j = pq[2*i+1] < pq[2*i+2] ? 2*i+1 : 2*i+2;
            swap(pq[i], pq[j]);
            i = j;
        }
        return min;
    
    }

    void heapify(vector<int> pq, int n, int i) {
        bool flag = true;
        while (i <= (n - 1) / 2 && flag) {
            int min = i;
            if (2 * i + 1 < n && pq[2 * i + 1] < pq[min]) {
                min = 2 * i + 1;
            }
            if (2 * i + 2 < n && pq[2 * i + 2] < pq[min]) {
                min = 2 * i + 2;
            }

            if (min != i) {
                swap(pq[i], pq[min]);
                i = min;
            } else {
                flag = false;
            }
        }
}

    void heapSort() { 
        for (int i = size() / 2 - 1; i >= 0; i--) {
            heapify(pq, size(), i);
        }

        for (int i = size() - 1; i > 0; i--) {
            swap(pq[0], pq[i]);
            heapify(pq, i, 0);
        }
    }
};
