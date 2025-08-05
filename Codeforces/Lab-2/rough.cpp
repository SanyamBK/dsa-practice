#include <bits/stdc++.h>
using namespace std;

#define ll long long

bool isPossible(ll n, ll m, ll k, ll x) {
    ll left = k - 1;
    ll right = n - k;

    ll left_sum = x * (x - 1) / 2; // Sum of first x-1 numbers
    if (left < x - 1) {
        left_sum -= (x - 1 - left) * (x - left) / 2; // Removing excess
    }

    ll right_sum = x * (x - 1) / 2; // Sum of first x-1 numbers
    if (right < x - 1) {
        right_sum -= (x - 1 - right) * (x - right) / 2; // Removing excess
    }

    ll total = x + left_sum + right_sum;
    return total <= m;
}

void solve() {
    ll n, m, k;
    cin >> n >> m >> k;
    
    ll low = 1, high = m, ans = 1;
    
    while (low <= high) {
        ll mid = (low + high) / 2;
        
        if (isPossible(n, m, k, mid)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();
    
    return 0;
}
