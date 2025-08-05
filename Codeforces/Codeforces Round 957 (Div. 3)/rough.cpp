#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

void testCase() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<char> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    if (m > n) {
        cout << "Yes" << endl;
        return;
    }

    int i = 1; // Start from the first position

    while (i < n) {
        if (a[i] == 'L') {
            ++i; // Move to the next position
        } else if (a[i] == 'C') {
            int j = i + m;
            // Find the nearest log behind the crocodile
            while (j > i) {
                if (j <= n && a[j] == 'L') {
                    i = j; // Move to the log
                    break;
                }
                --j;
            }
            // If no log found behind crocodile
            if (j == i) {
                cout << "No" << endl;
                return;
            }
        } else if (a[i] == 'W') {
            // Swim k steps or until finding log or crocodile
            int j = i + 1;
            int steps = 0;
            while (j <= n && steps <= k) {
                if (a[j] == 'L') {
                    i = j; // Move to the log
                    break;
                } else if (a[j] == 'C') {
                    cout << "No" << endl;
                    return;
                }
                ++j;
                ++steps;
            }
            // If k steps completed without finding log
            if (steps > k) {
                cout << "No" << endl;
                return;
            }
        }
    }

    cout << "Yes" << endl;
}

int main() {
    fastio;
    int t;
    cin >> t;
    while (t--) {
        testCase();
    }
    return 0;
}
