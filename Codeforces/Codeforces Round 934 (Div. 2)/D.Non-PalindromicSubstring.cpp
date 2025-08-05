#include <bits/stdc++.h>
using namespace std;

#define ll long long

bool checkPalindrome(string s) {
    int n = s.length();
    for (int i = 0; i < n / 2; i++) {
        if (s[i] != s[n - i - 1]) {
            return false;
        }
    }
    return true;
}

void testCase() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;

    vector<bitset<200001>> dp(n + 1); // Using bitset instead of 2D boolean array

    // Fill the bitset based on whether substrings are palindromes
    for (int i = n; i >= 1; i--) {
        for (int j = n; j >= i; j--) {
            string s1 = s.substr(i - 1, j - i + 1);
            if (!checkPalindrome(s1)) {
                dp[i].set(j);
            }
        }
    }

    unordered_set<int> st;
    for (int k = 0; k < q; k++) { // Renamed the loop variable to k
        int l, r;
        cin >> l >> r;

        int ans = 0;
        for (int i = l; i < r; i++) {
            for (int j = i + 1; j <= r; j++) {
                if (dp[i][j] != 0) {
                    int x = j - i + 1;
                    if (st.count(x) == 0) {
                        ans += x;
                    }
                    st.insert(x);
                }
            }
        }
        cout << ans << endl;
        st.clear();
    }

    // print dp array

}

int main() {
    int t;
    cin >> t;
    while(t--) {
        testCase();
    }
    return 0;
}
