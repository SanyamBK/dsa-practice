#include <bits/stdc++.h>
using namespace std;

#define forloop(i, k, n) for(int(i) = int(k); i < int(n); i++) 


void testcase() {
    int n;
    cin >> n;
    vector<long long> a(n);
    forloop(i, 0, n) {
        cin >> a[i];
    }

    int l = 0, r = 0;
    int ops = 0;
    long long sum = 0;
    while (l < n && r < n) {
        if (a[l] < 0) {
            r = l;
            while (a[r] <= 0 && r < n) {
                a[r] = -a[r];
                r++;
            }
            ops++;
            l = r;
        }
        l++;
    }
    forloop(i, 0, n) {
        sum += a[i];
    }
    cout << sum << " " << ops << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        testcase();
    }
    return 0;
}