#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;
int main() {
    int t = 1;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<int> prefixSum(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            prefixSum[i] = prefixSum[i - 1] + a[i - 1];
        }
        while (m--) {
            int l, s;
            cin >> l >> s;
            int required_sum = prefixSum[l - 1] + s;
            auto it = upper_bound(prefixSum.begin() + l, prefixSum.end(), required_sum - 1);
            if (it != prefixSum.end() && *it >= required_sum) {
                cout << (it - prefixSum.begin()) << endl;
            } else {
                cout << -1 << endl;
            }
        }
    }
    return 0;
}