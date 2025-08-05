#include <bits/stdc++.h>
using namespace std;

#define ll long long

#define forloop(i, a, b) for (int i = a; i < b; i++) 

void testCase() {
    int n;
    cin >> n;
    vector<char> a(n);
    forloop(i, 0, n) {
        cin >> a[i];
    }
    int i = 0;  
    int j = 0; 

    int coins = 0;
    while (i < n) {
        if (a[i] == '.') {
            i++;
        }
        if (a[i] == '@') {
            coins++;
            i++;
        }
        if (a[i] == '*') {
            j = i;
            while (a[j] == '*') {
                j++;
            }
            if (j - i > 1) {
                break;
            }
            i = j;
        }
    }
    cout << coins << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        testCase();
    }
    return 0;
}