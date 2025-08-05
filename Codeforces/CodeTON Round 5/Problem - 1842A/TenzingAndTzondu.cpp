#include <bits/stdc++.h>
using namespace std;

#define forloop(i, k, n) for (int(i) = int(k); i < int(n); i++)

int testCase() {
    int m, n;
    cin >> n >> m;

    vector<long> a(n);
    vector<long> b(m);

    forloop(i, 0, n) {
        cin >> a[i];
    }

    forloop(i, 0, m) {
        cin >> b[i];
    }

    bool flag = true;
    int i = 0, j = 0;
    while (n != 0 && m != 0) {
        if (flag) {
            long x = a[i];
            long y = b[j];
            a[i] = x - y;
            b[j] = y - x;
            if (a[i] <= 0) {
                i++; n--;
            }
            if (b[j] <= 0) {
                j++; m--;
            }
            flag = !flag;
        } else if (!flag) {
            long y = a[i];
            long x = b[j];
            a[i] = y - x;
            b[j] = x - y;
            if (a[i] <= 0) {
                i++; n--;
            }
            if (b[j] <= 0) {
                j++; m--;
            }
            flag = true;
        }
    }
    if (n > m) {
        cout << "Tsondu" << endl;
    } else if (m > n) {
        cout << "Tenzing" << endl;
    } else 
        cout << "Draw" << endl;

}

int main() {
    int t;
    cin >> t;
    while (t--) {
        testCase();
    }
    return 0;
}