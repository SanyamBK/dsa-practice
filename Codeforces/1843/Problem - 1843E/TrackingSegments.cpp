#include <bits/stdc++.h>
using namespace std;

bool fn(vector<pair<int, int>> segs, unordered_map<int, int> mp, int m) {  
    for (int j = 0; j < m; j++) {
        int l = segs[j].first;
        int r = segs[j].second;
        int cnt1 = mp[r] - mp[l-1];
        int cnt0 = r - l + 1 - cnt1;
        if (cnt1 > cnt0) {
            return true;
        }
    }
    return false;
}

void testcase() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> segs(m);
    unordered_map<int, int> mp;
    for (int i = 1; i <= n; i++) {
        mp[i] = 0;
    }

    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        segs[i] = make_pair(l, r);
    }

    int q;
    cin >> q;
    for (int i = 1; i <= q; i++) {
        int x;
        cin >> x;
        for (int j = x; j <= n; j++) {
            mp[j]++;
        }
        bool ans = fn(segs, mp, m);
        if (ans) {
            int a = i;
            while (i < q) {
                cin >> x;
                i++;
            }
            cout << a << endl;

            return;
        }
    }
    cout << -1 << endl;

}

int main() {
    int t;
    cin >> t;
    while (t--) {
        testcase();
    }
    return 0;
}