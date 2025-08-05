#include <bits/stdc++.h>
using namespace std;

#define forloop(i, k, n) for(int(i) = int(k); i < int(n); i++) 


void testcase() {
    int n; long x;
    cin >> n >> x;
    queue<long> a;
    queue<long> b;
    queue<long> c;

    forloop(i, 0, n) {
        long data;
        cin >> data;
        a.push(data);
    }
    forloop(i, 0, n) {
        long data;
        cin >> data;
        b.push(data);
    }
    forloop(i, 0, n) {
        long data;
        cin >> data;
        c.push(data);
    }

    long k = 0;
    long p = a.front();
    long q = b.front();
    long r = c.front();
    while (k <= x) {
        if (k == x) {
            cout << "Yes" << endl;
            return;
        }

        if (!a.empty() && p|k < x) {
            k = p|k;
            a.pop();
            if (!a.empty())
                p = a.front();
        }
        if (!b.empty() && q|k < x) {
            k = q|k;
            b.pop();
            if (!b.empty())
                q = b.front();
        }
        if (!c.empty() && r|k < x) {
            k = r|k;
            c.pop();
            if (!c.empty())
                r = c.front();
        }
    }
    cout << "No" << endl;
}

int main () {
    int t;
    cin >> t;
    while (t--) {
        testcase();
    }
    return 0;
}