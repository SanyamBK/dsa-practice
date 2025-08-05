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
#define Input(a) forloop (i, 0, a.size()) cin >> a[i]
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

bool isValid(const vector<vector<int>>& matrix, int n, int m, int guess) {
    vector<int> masks(n);

    for (int i = 0; i < n; ++i) {
        int mask = 0;
        for (int j = 0; j < m; ++j) {
            if (matrix[i][j] >= guess)
                mask |= (1 << j);
        }
        masks[i] = mask;
    }

    int total = (1 << m) - 1; // all columns covered

    // Generate all combinations of m - 1 rows
    int rows_to_pick = m - 1;
    vector<int> indices(n);
    for (int i = 0; i < n; ++i) indices[i] = i;

    // Try all combinations of m - 1 rows
    vector<bool> select(n, false);
    fill(select.begin(), select.begin() + rows_to_pick, true);
    do {
        int combined = 0;
        for (int i = 0; i < n; ++i) {
            if (select[i]) combined |= masks[i];
        }
        if (combined == total) return true;
    } while (prev_permutation(select.begin(), select.end()));

    return false;
}

int solve(const vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    int low = 0, high = 0;

    for (auto& row : matrix)
        for (int val : row)
            high = max(high, val);

    int ans = 0;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (isValid(matrix, n, m, mid)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}

int main() {
    vector<vector<int>> matrix = {
        {1, 3, 1},
        {3, 1, 1},
        {1, 2, 2},
        {1, 1, 3}
    };

    cout << solve(matrix) << endl; // Should output 2
    return 0;
}


// void testCase()
// {
//     // write your code here
    
// }

// int main()
// {
//     fastio;
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         testCase();
//     }
//     return 0;
// }