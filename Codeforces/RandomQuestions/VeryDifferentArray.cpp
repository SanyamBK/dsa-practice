#include <bits/stdc++.h>
using namespace std;

void testCase() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(m);
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    for(int i=0; i<m; i++) {
        cin >> b[i];
    }

    sort(a.begin(), a.end());
    // reverse sort b
    sort(b.begin(), b.end(), greater<int>());

    long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += (abs(a[i] - b[i]));
    }

    cout << sum << endl;

}

int main() {
    int t;
    cin >> t;
    while(t--) {
        testCase();
    }
    return 0;
}