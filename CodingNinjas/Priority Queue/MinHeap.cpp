#include <bits/stdc++.h>
using namespace std;

class MinHeap {
    vector<int> pq;

    public:
    MinHeap() {
        pq = vector<int>();
    }

    ~MinHeap() {
        pq.clear();
        delete &pq;
    }

    bool isEmpty() {
        return pq.size() == 0;
    }

    int size() {
        return pq.size();
    }

    // insert operation
    void push(int element) {
        pq.push_back(element);
        int i = size() - 1;
        while (i > 0 && pq[i] < pq[(i-1)/2]) {
            swap(pq[i], pq[(i-1)/2]);
            i = (i-1)/2;
        }

    }
    
    // delete operation
    void pop() {
        if (isEmpty()) 
            return;
        swap(pq[0], pq[pq.size() - 1]);
        pq.pop_back();
        int i = 0;
        while ((pq[i] > pq[2*i+1] || pq[i] > pq[2*i+2]) && (unsigned int)(2*i+2) < pq.size()) {
            int j = pq[2*i+1] < pq[2*i+2] ? 2*i+1 : 2*i+2;
            swap(pq[i], pq[j]);
            i = j;
        }
    }


    int extractMin() {
        if (isEmpty()) 
            return INT_MIN;
        int min = pq[0];
        pop();
        return min;
    
    }

};

void heapify(vector<int> &arr, int n, int i) {
    bool flag = true;
    while (i <= (n - 1) / 2 && flag) {
        int maxi = i;
        if (2 * i + 1 < n && arr[2 * i + 1] > arr[maxi]) {
            maxi = 2 * i + 1;
        }
        if (2 * i + 2 < n && arr[2 * i + 2] > arr[maxi]) {
            maxi = 2 * i + 2;
        }

        if (maxi != i) {
            swap(arr[i], arr[maxi]);
            i = maxi;
        } else {
            flag = false;
        }
    }
}

void heapSort(vector<int> &arr) { 
    for (int i = arr.size() / 2 - 1; i >= 0; i--) {
        heapify(arr, arr.size(), i);
    }

    for (int i = arr.size() - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void printVector(vector<int> &arr) {
    for (unsigned int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    MinHeap pq;
    pq.push(10);
    pq.push(5);
    pq.push(15);
    pq.push(2);
    pq.push(20);
    pq.push(3);
    
    cout << pq.extractMin() << endl;

    pq.pop();

    cout << pq.extractMin() << endl;

    vector<int> arr = {10, 5, 15, 2, 20, 3};

    // heap sort using min heap
    MinHeap pq1;
    for (unsigned int i = 0; i < arr.size(); i++) {
        pq1.push(arr[i]);
    }
    vector<int> sortedArr;
    while (!pq1.isEmpty()) {
        sortedArr.push_back(pq1.extractMin());
    }

    printVector(sortedArr);

    // heap sort using heapify function
    heapSort(arr);

    printVector(arr);
}