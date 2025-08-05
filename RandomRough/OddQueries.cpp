#include <bits/stdc++.h>
using namespace std;


void testcase() {
    int n, q;
    cin >> n >> q;

    long *a = new long[n+1];
    unordered_map<int, int> map;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
        map[i] = sum;
    }
    while (q--) {
    int l, r; long k;
    cin >> l >> r >> k;
    int ans = map[l-1] + (r-l+1)*k + (map[n] - map[r]);

    if (ans % 2 != 0)
        cout << "YES" << endl;
    else 
        cout << "NO" << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        testcase();
    }
    return 0;
}