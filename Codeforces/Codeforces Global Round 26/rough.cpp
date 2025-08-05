#include <bits/stdc++.h>
using namespace std;

#define MOD 998244353
#define ll long long
#define vll vector<ll>
#define mll vector<vector<ll>>

void testCase() {
    int n;
    cin >> n;
    vll a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // DP tables for maximum values and counts
    mll dp(n, vll(2, LLONG_MIN));
    mll count(n, vll(2, 0));
    
    dp[0][0] = a[0];
    dp[0][1] = abs(a[0]);
    count[0][0] = 1;
    count[0][1] = 1;

    for (int i = 1; i < n; i++) {
        // Transition for dp[i][0]
        ll val0 = dp[i-1][0] + a[i];
        dp[i][0] = val0;
        count[i][0] = count[i-1][0];

        // Transitions for dp[i][1]
        ll val1_0 = dp[i-1][0] + a[i];
        ll val1_1 = dp[i-1][1] + a[i];
        ll abs_val1_0 = abs(val1_0);
        ll abs_val1_1 = abs(val1_1);

        dp[i][1] = max({val1_0, val1_1, abs_val1_0, abs_val1_1});

        if (dp[i][1] == val1_0) count[i][1] += count[i-1][0];
        if (dp[i][1] == val1_1) count[i][1] += count[i-1][1];
        if (dp[i][1] == abs_val1_0) count[i][1] += count[i-1][0];
        if (dp[i][1] == abs_val1_1) count[i][1] += count[i-1][1];

        count[i][1] %= MOD;
    }

    ll max_value = max(dp[n-1][0], dp[n-1][1]);
    ll total_ways = 0;

    if (max_value == dp[n-1][0]) total_ways += count[n-1][0];
    if (max_value == dp[n-1][1]) total_ways += count[n-1][1];

    total_ways %= MOD;
    cout << total_ways << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        testCase();
    }
    return 0;
}
