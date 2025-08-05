#include <bits/stdc++.h>
using namespace std;

void testCase() {
    int n;
    cin >> n;

    vector<int> P(n);
    // Resize the vector to store 'n' elements

    for (int i = 0; i < n; ++i) {
        cin >> P[i];
    }

    if (n <= 2) {
        cout << -1 << endl;
        return;
    }

    int x = n / 2; // Calculate x once

    if (n % 2 != 0) {
        int sum = n + 1;
        for (int i = 0; i < n; ++i) {
            int ans = sum - P[i];
            cout << ans << " ";
        }
        cout << endl;
        return;
    } else {
        int sum = n;
        for (int i = 0; i < n; ++i) {
            if (P[i] == x) {
                cout << n << " ";
            } else if (P[i] == n) {
                cout << x << " ";
            } else {
                cout << sum - P[i] << " ";
            }
        }
        cout << endl;
        return;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        testCase();
    }
    return 0;
}
