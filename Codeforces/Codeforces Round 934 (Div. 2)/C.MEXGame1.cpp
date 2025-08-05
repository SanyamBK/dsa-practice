#include <bits/stdc++.h>
using namespace std;

#define ll long long

void testCase() {
    int n;
    cin >> n;
    int a;
    priority_queue<int, vector<int>, greater<int> > pq;
    for (int i = 0; i < n; i++) {
        cin >> a;
        pq.push(a);
    }

    
    int mex = 0;
    
    while (!pq.empty()) {   
        int x = pq.top();
        pq.pop();
        if (x == mex) {
            mex++;
        }
        if (pq.empty()) {
            break;
        }
        pq.pop();

    }
    
    cout << mex << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        testCase();
    }
    return 0;
}