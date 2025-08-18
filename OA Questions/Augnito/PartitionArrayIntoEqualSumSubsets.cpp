#include <bits/stdc++.h>
using namespace std;

string partitionArray(vector<int> arr) {
    int n = arr.size();
    int totalSum = accumulate(arr.begin(), arr.end(), 0);

    if (totalSum % 2) return "-1";
    int target = totalSum / 2;

    // dp[i][s][c] = true if first i elements can form sum s with c elements
    vector<vector<vector<bool>>> dp(n+1, vector<vector<bool>>(target+1, vector<bool>(n/2+1, false)));
    vector<vector<vector<pair<int,int>>>> parent(n+1, vector<vector<pair<int,int>>>(target+1, vector<pair<int,int>>(n/2+1, {-1,-1})));

    dp[0][0][0] = true;

    for (int i = 1; i <= n; i++) {
        for (int s = 0; s <= target; s++) {
            for (int c = 0; c <= n/2; c++) {
                // skip arr[i-1]
                if (dp[i-1][s][c]) {
                    dp[i][s][c] = true;
                    parent[i][s][c] = {s,c};
                }
                // take arr[i-1]
                if (c > 0 && s >= arr[i-1] && dp[i-1][s-arr[i-1]][c-1]) {
                    dp[i][s][c] = true;
                    parent[i][s][c] = {s-arr[i-1],c-1};
                }
            }
        }
    }

    if (!dp[n][target][n/2]) return "-1";

    // backtrack
    vector<int> set1, set2;
    int s = target, c = n/2;
    for (int i = n; i > 0; i--) {
        auto [ps, pc] = parent[i][s][c];
        if (pc != c) { // we took arr[i-1]
            set1.push_back(arr[i-1]);
        } else {
            set2.push_back(arr[i-1]);
        }
        s = ps; c = pc;
    }

    sort(set1.begin(), set1.end());
    sort(set2.begin(), set2.end());

    string res;
    if (set1[0] < set2[0]) {
        for (int x : set1) res += to_string(x) + ",";
        for (int x : set2) res += to_string(x) + ",";
    } else {
        for (int x : set2) res += to_string(x) + ",";
        for (int x : set1) res += to_string(x) + ",";
    }
    res.pop_back();
    return res;
}

string ArrayChallenge(vector<int> arr) {
    string finalResult = partitionArray(arr);
    string token = "inbfzyhc316";
    for (int i = finalResult.length()-1; i >= 0; i--) {
        if (token.find(finalResult[i]) != string::npos) {
            finalResult.replace(i, 1, "");
        }
    }

    return finalResult.empty() ? "EMPTY" : finalResult;
}

int main() {
    // Test cases
    vector<int> test1 = {1, 2, 3, 4};
    cout << "Input: {1,2,3,4}" << endl;
    cout << "Output: " << ArrayChallenge(test1) << endl;
    
    vector<int> test2 = {1, 2, 1, 5};
    cout << "Input: {1,2,1,5}" << endl;
    cout << "Output: " << ArrayChallenge(test2) << endl;

    vector<int> test3 = {16, 22, 35, 8, 20, 1, 21, 11};
    cout << "Input: {16, 22, 35, 8, 20, 1, 21, 11}" << endl;
    cout << "Output: " << ArrayChallenge(test3) << endl;
    
    return 0;
}