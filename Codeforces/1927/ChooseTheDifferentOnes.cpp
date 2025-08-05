#include <bits/stdc++.h>
using namespace std;

void testCase() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n), b(m);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < m; i++) {
        cin >> b[i];
    }
    sort(a.begin(), a.end());  
    sort(b.begin(), b.end());

    // check if numbers from 1 to k are in both array
    vector<bool> kArray(k + 1, false);
    int inA = k/2;
    int inB = k/2;
    for (int i = 0; i < n; i++) {
        if (a[i] <= k && !kArray[a[i]]) {
            kArray[a[i]] = true;
            inA--;
        }
    }
    for (int i = 0; i < m; i++) {
        if (b[i] <= k && !kArray[b[i]]) {
            kArray[b[i]] = true;
            inB--;
        }
    }
    for (int i = 1; i <= k; i++) {
        if (!kArray[i] || inA < 0 || inB < 0) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
    return;
    
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        testCase();
    }
    return 0;
}