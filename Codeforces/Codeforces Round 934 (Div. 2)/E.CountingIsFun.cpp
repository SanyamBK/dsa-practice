#include <bits/stdc++.h>
using namespace std;

int count_good_arrays(int n, int k, int p) {
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

    // Initialize dp[1][j] = 1 for j = 1 to k
    for (int j = 1; j <= k; ++j) {
        dp[1][j] = 1;
    }

    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j <= k; ++j) {
            dp[i][j] = (dp[i][j] + dp[i - 1][j]) % p;
            if (j > 1) {
                dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % p;
            }
        }
    }

    int total_good_arrays = 0;
    for (int j = 1; j <= k; ++j) {
        total_good_arrays = (total_good_arrays + dp[n][j]) % p;
    }

    return total_good_arrays;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k, p;
        cin >> n >> k >> p;
        cout << count_good_arrays(n, k, p) << endl;
    }

    return 0;
}
