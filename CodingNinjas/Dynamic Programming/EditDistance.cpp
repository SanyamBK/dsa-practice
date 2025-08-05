#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;

int editDistanceHelper(string s1, string s2, int i, int j) {
	if (i == 0) return j;
	if (j == 0) return i;
    if (dp[i][j] != -1) return dp[i][j];
	else if (s1[i-1] == s2[j-1]) return dp[i][j] = editDistanceHelper(s1, s2, i-1, j-1);
	else return dp[i][j] = min(editDistanceHelper(s1, s2, i-1, j-1), min(editDistanceHelper(s1, s2, i-1, j), editDistanceHelper(s1, s2, i, j-1))) + 1;
}

int editDistance(string s1, string s2) {
	// Write your code here
	return editDistanceHelper(s1, s2, s1.size()-1, s2.size()-1);
}

int editDistanceTab(string s1, string s2) {
    vector<vector<int>> dp(s1.size()+1, vector<int>(s2.size()+1, 0));
    for (int i = 0; i <= s1.size(); i++) {
        for (int j = 0; j <= s2.size(); j++) {
            if (i == 0) dp[i][j] = j;
            else if (j == 0) dp[i][j] = i;
            else if (s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
        }
    }
    return dp[s1.size()][s2.size()];
}

// space optimized
int editDistanceTabOptimized(string s1, string s2) {
    vector<int> dp(s2.size()+1, 0);
    for (int i = 0; i <= s1.size(); i++) {
        int prev = dp[0];
        for (int j = 0; j <= s2.size(); j++) {
            if (i == 0) dp[j] = j;
            else if (j == 0) {
                prev = dp[j];
                dp[j] = i;
            }
            else {
                int temp = dp[j];
                if (s1[i-1] == s2[j-1]) dp[j] = prev;
                else dp[j] = min(prev, min(dp[j], dp[j-1])) + 1;
                prev = temp;
            }
        }
    }
    return dp[s2.size()];
}



int main() {
    string s1 = "abc";
    string s2 = "dc";

    dp = vector<vector<int>>(s1.size(), vector<int>(s2.size(), -1));

    cout << editDistance(s1, s2) << endl;
    return 0;
}