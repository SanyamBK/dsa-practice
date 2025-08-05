#include <iostream>
#include <queue>
using namespace std;



int main() {
    int n = 5, k = 3;
    int array[] = {12, 10, 6, 7, 9};
    
    
    priority_queue<int> pq;
    for (int i = 0; i < k; i++) {
        pq.push(array[i]);
    }
    
    int j = 0;
    for (int i = k; i < n; i++) {
        array[j++] = pq.top();
        pq.pop();
        pq.push(array[i]);
    }
    
    while (!pq.empty()) {
        array[j++] = pq.top();
        pq.pop();
    }
    
    for (int i = 0; i < n; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

}