#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define vi vector<int>
#define mi vector<vector<int>>
#define vll vector<ll>
#define mll vector<vector<ll>>
#define mull vector<vector<ull>>
#define vull vector<ull>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pull pair<ull, ull>
#define pis pair<int, string>
#define ppii pair<pair<int, int>, int>
#define psi pair<string, int>
#define pss pair<string, string>
#define psull pair<string, ull>
#define pulls pair<ull, string>
#define ompi map<int, int>              // ordered map
#define umpi unordered_map<int, int>    // unordered map
#define osi set<int>                    // ordered set
#define usi unordered_set<int>          // unordered set
#define omsi map<string, int>           // ordered map of string int
#define umsi unordered_map<string, int> // unordered map of string int
#define oss set<string>                 // ordered set of string
#define uss unordered_set<string>       // unordered set of string
#define opll map<ll, ll>                // ordered map of ll
#define upll unordered_map<ll, ll>      // unordered map of ll
#define osll set<ll>                    // ordered set of ll
#define usll unordered_set<ll>          // unordered set of ll
#define opii map<pii, int>              // ordered map of pair pair int
#define upii unordered_map<pii, int>    // unordered map of pair pair int
#define osii set<pii>                   // ordered set of pair pair int
#define usii unordered_set<pii>         // unordered set of pair pair int
#define opsi map<pii, string>           // ordered map of pair pair string
#define upsi unordered_map<pii, string> // unordered map of pair pair string
#define osull set<ull>                  // ordered set of unsigned ll
#define usull unordered_set<ull>        // unordered set of unsigned ll
#define opull map<pull, ull>            // ordered map of pair ull
#define sti stack<int>
#define qi queue<int> // queue of int
#define stii stack<pii>
#define qpii queue<ppii> // queue of pair pair int
#define qii queue<pii> // queue of pair int
#define qll queue<ll>  // queue of ll
#define stll stack<ll>
#define qull queue<ull> // queue of ull
#define stull stack<ull>
#define gri greater<int>
#define pb push_back
#define Sort(nums) sort(nums.begin(), nums.end())
#define PQmin priority_queue<int, vi, gri> // min heap
#define PQmax priority_queue<int, vi>      // max heap
#define inf_min INT_MIN
#define inf_max INT_MAX
#define mod 1000000007
#define forloop(i, a, b) for (auto i = a; i < b; i++)
#define rforloop(i, a, b) for (auto i = a; i >= b; i--)
#define forit(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define print(a) cout << a << endl
#define print2(a, b) cout << a << " " << b << endl
#define PI 3.14159265358979323846
#define fi first
#define se second
#define fifi fi.fi
#define fise fi.se
#define sefi se.fi
#define sese se.se
#define all(a) a.begin(), a.end()
#define mem(a, b) memset(a, b, sizeof(a))
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                     \
    cout.tie(NULL)

struct custom_hash {
static uint64_t splitmix64(uint64_t x) {
// http://xorshift.di.unimi.it/splitmix64.c
x += 0x9e3779b97f4a7c15;
x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
return x ^ (x >> 31);
}
size_t operator()(uint64_t x) const {
static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
return splitmix64(x + FIXED_RANDOM);
}
};
#define deb(x) cout << #x << " " << x << endl
#define deb2(x, y) cout << #x << " " << x << " " << #y << " " << y << endl
#define setmem(a, b) for (ull i = 0; i < sizeof(a) / sizeof(a[0]); i++) a[i] = b
const ll MOD = 1e9 + 7;
ull gcd(ll a, ll b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
ull lcm(ll a, ll b)
{
    return b * (a / gcd(a, b));
}

template <typename T>
void printVector(vector<T> &v)
{
    for (auto i : v)
    {
        cout << i << " ";
    }
    cout << endl;
}

// longest common subsequence

// int lcs(string a, string b, string c, string d, vector<vector<vector<vector<int>>>> &dp) {

//     if (a.length() == 0 || b.length() == 0 || c.length() == 0 || d.length() == 0) {
//         return 0;
//     }

//     if (dp[a.length()][b.length()][c.length()][d.length()] != -1) {
//         return dp[a.length()][b.length()][c.length()][d.length()];
//     }

//     if (a[0] == b[0] && c[0] == d[0]) {
//         return dp[a.length()][b.length()][c.length()][d.length()] = 1 + lcs(a.substr(1), b.substr(1), c.substr(1), d.substr(1), dp);
//     }

//     int op1 = lcs(a.substr(1), b, c, d, dp);
//     int op2 = lcs(a, b.substr(1), c, d, dp);
//     int op3 = lcs(a, b, c.substr(1), d, dp);
//     int op4 = lcs(a, b, c, d.substr(1), dp);

//     return dp[a.length()][b.length()][c.length()][d.length()] = max({op1, op2, op3, op4});

// }

string lcs(const string& X, const string& Y) {
    int m = X.length();
    int n = Y.length();

    vector<vector<int>> L(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }

    int index = L[m][n];
    string lcs(index, ' ');

    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcs[index - 1] = X[i - 1];
            i--;
            j--;
            index--;
        } else if (L[i - 1][j] > L[i][j - 1])
            i--;
        else
            j--;
    }

    return lcs;
}

void testCase()
{
    // write your code here
    string s1, s2, s3, s4;
    cin >> s1 >> s2 >> s3 >> s4;

    // int m = s1.length();
    // int n = s2.length();
    // int o = s3.length();
    // int p = s4.length();

    // vector<vector<vector<vector<int>>>> dp(m+1, vector<vector<vector<int>>>(n+1, vector<vector<int>>(o+1, vector<int>(p+1, -1))));

    // int ans = lcs(s1, s2, s3, s4, dp);

    // print(ans);

    string ans = lcs(s1, s2);
    ans = lcs(ans, s3);
    ans = lcs(ans, s4);

    print(ans.size());


}

int main()
{
    fastio;
    int t = 1;
    // int t;
    // cin >> t;
    while (t--)
    {
        testCase();
    }
    return 0;
}