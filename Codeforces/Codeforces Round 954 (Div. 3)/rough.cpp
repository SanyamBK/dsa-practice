#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll evaluate_expression(const string &s, int n, int mask) {
    vector<ll> nums;
    ll current = s[0] - '0';

    for (int i = 1; i < n; ++i) {
        if (mask & (1 << (i - 1))) {
            // If bit is set, treat it as a `+`
            nums.push_back(current);
            current = s[i] - '0';
        } else {
            // If bit is not set, treat it as a `×`
            current *= (s[i] - '0');
        }
    }
    nums.push_back(current);

    // Now we just need to sum all parts in `nums`
    ll result = 0;
    for (ll num : nums) {
        result += num;
    }

    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n;
        string s;
        cin >> n >> s;

        if (n == 2) {
            cout << stoll(s) << '\n';
            continue;
        }

        ll min_result = LLONG_MAX;
        int total_masks = 1 << (n - 1);

        for (int mask = 0; mask < total_masks; ++mask) {
            int bits_count = __builtin_popcount(mask);
            if (bits_count == n - 2) {
                ll result = evaluate_expression(s, n, mask);
                min_result = min(min_result, result);
            }
        }

        cout << min_result << '\n';
    }

    return 0;
}
