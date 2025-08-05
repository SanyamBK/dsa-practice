#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

void testCase() {
    int n;
    ll l, r;
    cin >> n >> l >> r;

    vi a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int win = 0;
    ll curr_sum = 0;
    int start = 0;

    for (int end = 0; end < n; ++end) {
        curr_sum += a[end];
        
        while (curr_sum > r && start <= end) {
            curr_sum -= a[start];
            ++start;
        }
        
        if (curr_sum >= l && curr_sum <= r) {
            ++win;
            curr_sum = 0; // reset current sum for the next segment
            start = end + 1; // move start to the next position after end
        }
    }

    cout << win << endl;
}

int main() {
    fastio;
    int t;
    cin >> t;
    while (t--) {
        testCase();
    }
    return 0;
}
