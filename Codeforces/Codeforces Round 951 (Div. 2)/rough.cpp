#include <bits/stdc++.h>
using namespace std;

void testCase() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Initialize the min of maximums as infinity
    int minE = INT_MAX;

    // Iterate over the array to find maximum of all subarrays with different lengths
    for (int len = 2; len <= n; ++len) {
        deque<int> dq;

        for (int i = 0; i < n; ++i) {
            // Remove elements not in the current window
            while (!dq.empty() && dq.front() <= i - len) {
                dq.pop_front();
            }
            // Remove elements smaller than the current element
            while (!dq.empty() && a[dq.back()] <= a[i]) {
                dq.pop_back();
            }
            // Add current element at the back of the deque
            dq.push_back(i);
            // If we have a valid window, update the minimum of maximums
            if (i >= len - 1) {
                minE = min(minE, a[dq.front()]);
            }
        }
    }

    // Output the result
    int ans = minE - 1;
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        testCase();
    }
    return 0;
}
