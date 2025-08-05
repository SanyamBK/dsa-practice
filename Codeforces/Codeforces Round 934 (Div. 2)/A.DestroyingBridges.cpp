#include <bits/stdc++.h>
using namespace std;

#define ll long long

void testCase() {
    int n, k;
    cin >> n >> k;

    if (k >= n - 1) {
        cout << 1 << endl;
    } else {
        cout << n << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        testCase();
    }
    return 0;
}