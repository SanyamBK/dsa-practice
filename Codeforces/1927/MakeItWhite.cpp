#include <bits/stdc++.h>
using namespace std;

void testCase() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int first = -1, last = -1;
    for(int i = 0; i < n; i++) {
        if(s[i] == 'B') {
            first = i;
            break;
        }
    }
    for(int i = n - 1; i >= 0; i--) {
        if(s[i] == 'B') {
            last = i;
            break;
        }
    }
    int ans = last - first + 1;
    if(first == -1) {
        cout << 0 << endl;
    } else {
        cout << ans << endl;
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