// #include <bits/stdc++.h>
// using namespace std;

// 

// vector<string> threePalindromicSubstrings(string word) {
//     int n = word.length();
//     if (n < 3) return {"Impossible"};
    
//     vector<vector<bool>> dp(n, vector<bool>(n, false));
//     for (int i = 0; i < n; i++) {
//         dp[i][i] = true; 
//     }

//     forloop(length, 2, n) {
//         forloop(i, 0, n - length + 1) {
//             int j = i + length - 1;
//             if (word[i] == word[j]) {
//                 if (length == 2) {
//                     dp[i][j] = true;
//                 } else {
//                     dp[i][j] = dp[i + 1][j - 1];
//                 }
//             }
//         }
//     }

//     forloop(i, 1, n - 1) {
//         forloop(j, i + 1, n) {
//             if (dp[0][i - 1] && dp[i][j - 1] && dp[j][n - 1]) {
//                 return {word.substr(0, i), word.substr(i, j - i), word.substr(j)};
//             }
//         }
//     }

//     return {"Impossible"};
// }

// int main() {
//     string word;
//     cin >> word;
//     vector<string> result = threePalindromicSubstrings(word);
//     for (const string& s : result) {
//         cout << s << " ";
//     }
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

#define forloop(i, a, b) for (auto i = a; i < b; i++)
#define pb push_back

bool isPalin(const string &x) {
    int l = 0;
    int r = x.length() - 1;
    while (l < r) {
        if (x[l] != x[r])
            return false;
        l++;
        r--;
    }
    return true;
}

vector<string> Palindromes(string &s, int n) {
    vector<int> P1, P2;
    vector<pair<int, int>> P3;

    string start;
    int a = s.length();
    forloop(i, 0, a-2) {
        start += s[i];
        if (isPalin(start))
            P1.pb(i);
    }

    string last;
    for (int j = s.length() - 1; j > 1; j--) {
        last = s[j] + last;
        if (isPalin(last))
            P2.pb(j);
    }

    reverse(P2.begin(), P2.end());
    
    int x = P1.size();
    int y = P2.size();
    forloop(i, 0, x) {
        forloop(j, 0, y) {
            if (P1[i] < P2[j]) {
                P3.emplace_back(P1[i], P2[j]);
            }
        }
    }

    vector<string> ans;
    string ans1, ans2, ans3;
    bool flag = false;

    for (auto &p : P3) {
        int a = p.first;
        int b = p.second;
        string mid = s.substr(a + 1, b - a - 1);
        if (isPalin(mid)) {
            flag = true;
            ans1 = s.substr(0, a + 1);
            ans.pb(ans1);
            ans2 = mid;
            ans.pb(ans2);
            ans3 = s.substr(b, n - b);
            ans.pb(ans3);
            break;
        }
    }
    

    if (!flag) return ans = {"Impossible"};
    else return ans;
}

int main() {
    string strr;
    cin >> strr;
    int n = strr.length();
    vector<string> ans = Palindromes(strr, n);
    for (auto &s : ans) {
        cout << s << " ";
    } cout << endl;
    return 0;
}
