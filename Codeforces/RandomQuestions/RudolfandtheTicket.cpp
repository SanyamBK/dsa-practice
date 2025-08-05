#include <bits/stdc++.h>
using namespace std;

#define ll long long

void testCase() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> b(n), c(m);
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }
    for(int i = 0; i < m; i++) {
        cin >> c[i];
    }
    sort(b.begin(), b.end(), greater<int>());
    sort(c.begin(), c.end(), greater<int>());
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (b[i] >= k) {
            continue;
        }
        for (int j = 0; j < m; j++) {
            if (c[j] >= k) {
                continue;
            }
            if (b[i] + c[j] <= k) {
                ans += (m - j);
                break;
            }
        }
    }
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        testCase();
    }
    return 0;
}