#include <bits/stdc++.h>
using namespace std;

#define forloop(i, k, n) for (int (i) = int(k); i < int(n); i++)

void testcase() {
    int n;
    cin >> n;
    vector<int> a(n);
    forloop(i, 0, n) {
        cin >> a[i];
    }
    int count = 0;
    int i = 0;
    while (i < n) {
        int j = -1;
        for (int k = i + 1; k < n; k++) {
            if (a[k] == a[i]) {
                j = k;
                break;
            }
        }
        if (j > i) {
            int k = j - i + 1;
            n -= k;
            count += k;

            for (int x = i; x < n; x++) {
                a[x] = a[x + k];
            }
            i--;
        }
        i++;
    }

    cout << count << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        testcase();
    }
    return 0;
}
