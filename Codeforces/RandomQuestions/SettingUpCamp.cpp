#include <bits/stdc++.h>
using namespace std;

#define ll long long

void testCase() {
    int a, b, c;
    cin >> a >> b >> c;
    int x = b % 3;
    if (x + c < 3 && x != 0) {
        cout << -1 << endl;
    } else {
        cout << a + (b+2)/3 + c+1/3 << endl;
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