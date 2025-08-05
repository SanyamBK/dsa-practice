#include <bits/stdc++.h>
using namespace std;

#define forloop(i, k, n) for (int(i) = int(k); i < int(n); i++)

void testcase() {
    int n;
    cin >> n;
    long long *L = new long long[n];
    unordered_map<long long, int> M;
    forloop(i, 0, n) {
        int data;
        cin >> data;
        L[i] = data;
        M[data]++;
    }

    int count = 0;
    for (auto x : M) {
        count++;
    }

    cout << count << endl;
    delete [] L;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        testcase();
    }

    return 0;
}