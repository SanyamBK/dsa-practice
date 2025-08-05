#include <bits/stdc++.h>
using namespace std;

void testcase() {
    int n;
    cin >> n;
    vector<int> a(n);
    priority_queue<int> pqmax;
    priority_queue<int, vector<int>, greater<int>> pqmin;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        pqmax.push(a[i]);
        pqmin.push(a[i]);
    }
    int cost = 0;
    while (n >= 1) {
        cost += pqmax.top() - pqmin.top();
        pqmin.pop();
        pqmax.pop();
        n -= 2;
    }
    cout << cost << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        testcase();
    }
    return 0;
}