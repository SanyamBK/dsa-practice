#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<vector<int>> dp;

void grove(int n, double r, int x, int y, int dr) {
    
    if (n == 0 || x >= n || y >= n) return ;
    
    if (x == 0 && y == 0) {
        x = y = dr;
    }
    if (dp[x][y] == 1) return;

    if (x + r <= n && y + r <= n) {
        dp[x][y] = 1;
        cout << x << " " << y << endl;
    }

    if (x < n && y < n) {
        grove(n, r, x + 2*dr, y, dr);
        grove(n, r, x, y + 2*dr, dr);
        grove(n, r, x + 2*dr, y + 2*dr, dr);
    }





}

void testCase() {
    int n; double r;
    cin >> n >> r;



    int x = 0, y = 0;

    dp = vector<vector<int>>(n, vector<int>(n, 0));

    int dr = ceil(r);

    grove(n, r, x, y, dr);
}

int main() {
    int t = 1;
    // cin >> t;
    while(t--) {
        testCase();
    }
    return 0;
}