#include <bits/stdc++.h>
using namespace std;

int LCS(string &s1, string &s2, int i, int j, vector<vector<int>> &dp) {
    if (i == 0 || j == 0) return 0;
    if (s1[i] == s2[j]) return 1 + LCS(s1, s2, i-1, j-1, dp);
    return max(LCS(s1, s2, i-1, j, dp), LCS(s1, s2, i, j-1, dp));
}

int LCS_Memo(string &s1, string &s2, int i, int j, vector<vector<int>> &dp) {
    if (i == 0 || j == 0) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    if (s1[i-1] == s2[j-1]) return dp[i][j] = 1 + LCS_Memo(s1, s2, i-1, j-1, dp);
    return dp[i][j] = max(LCS_Memo(s1, s2, i-1, j, dp), LCS_Memo(s1, s2, i, j-1, dp));
}

int LCS_Tab(string &s1, string &s2, vector<vector<int>> &dp) {
    for (int i = 0; i <= s1.size(); i++) {
        for (int j = 0; j <= s2.size(); j++) {
            if (i == 0 || j == 0) dp[i][j] = 0;
            else if (s1[i-1] == s2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[s1.size()][s2.size()];
}

int main() {
    string s1 = "AGGTAB";
    string s2 = "GXTXAYB";
    vector<vector<int>> dp(s1.size()+1, vector<int>(s2.size()+1, -1));
    cout << LCS_Memo(s1, s2, s1.size(), s2.size(), dp) << endl;
    return 0;
}
