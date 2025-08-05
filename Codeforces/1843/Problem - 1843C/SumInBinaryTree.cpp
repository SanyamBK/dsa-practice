#include <bits/stdc++.h>
using namespace std;

void testcase() {
    long long n;
    cin >> n;
    long long sum = 0;
    long long i = n - 1;
    while (i > 0) {
        sum += i+1;
        i = (i-1)/2;
    }
    cout << sum + 1 << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        testcase();
    }
    return 0;
}