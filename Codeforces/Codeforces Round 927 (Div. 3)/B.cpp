#include <bits/stdc++.h>
using namespace std;

#define ll long long

void testCase() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    priority_queue<int> pq;
    // unordered_set<int> s;

    int i = 0;
    
    while (i < n) {
        if (pq.empty() || pq.top() < a[i]){
            // s.insert(a[i]);
            pq.push(a[i]);
            i++;
        } else {
            int k = 1; int temp = a[i];
            while (a[i] <= pq.top()) {
                a[i] = temp * k;
                k++;
            }
            pq.push(a[i]);
            // s.insert(a[i]);
            i++;
        }
       
    }
    
    cout << pq.top() << endl;
}


int main() {
    int t;
    cin >> t;
    while(t--) {
        testCase();
    }
    return 0;
}