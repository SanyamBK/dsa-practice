#include <bits/stdc++.h>
using namespace std;

#define ll long long

void testCase() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    // reverse s into t
    string t = s;
    reverse(t.begin(), t.end());
    if (n%2 == 0) {
        bool flag = true;
        int k;
        for (auto i = 0; i < s.length(); i++) {
            if (s[i] != t[i]) {
                flag = false;
                k = i;
                break;
            }
        }
        if (!flag) {
            if (s[k] < t[k]) {
                cout << s << endl;
                return;
            } else {
                t.append(s);
                cout << t << endl;
                return;
            }
        } else {
            cout << s << endl;
            return;
        }
    } 

}

int main() {
    int t;
    cin >> t;
    while(t--) {
        testCase();
    }
    return 0;
}