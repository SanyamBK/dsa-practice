#include <bits/stdc++.h>
using namespace std;

void testCase() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> copyA(a);
    

    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--; r--;
        int i = l, j = -1;
        int m = a[l];

        for (int k = l+1; k <= r; k++) {
            if (a[k] != m) {
                j = k;
                break;
            }
        }
        if (j == -1) {
            cout << "-1 -1" << endl;
            continue;
        } else {
            if (a[j] > m) {
                cout << i+1 << " " << j+1 << endl;
                
            } else {
                cout << j+1 << " " << i+1 << endl;
            }
            continue;
        }

    }
    
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        testCase();
        cout << endl;
    }
    return 0;
}