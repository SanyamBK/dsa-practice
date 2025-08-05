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
#define forloop(i, a, b) for (int i = a; i < b; i++)
#define rforloop(i, a, b) for (int i = a; i >= b; i--)
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

int dfs(vi adj[], int node, vi &color, int steps)
{
    color[node] = 2;
    steps++;
    for (auto it : adj[node])
    {
        steps = dfs(adj, it, color, steps);
    }
    if (count(all(color), 2) == color.size())
    {
        return steps;
    }
}

pair<vi, int> BFSShortestPath(vi adj[], int a, int b, int n)
{
    vi path;
    vi visited(n + 1, 0);
    queue<int> q;
    q.push(a);
    visited[a] = 1;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        path.pb(node);
        if (node == b)
        {
            return {path, path.size()-1};
        }
        for (auto it : adj[node])
        {
            if (!visited[it])
            {
                visited[it] = 1;
                q.push(it);
            }
        }
    }
    return {path, -1};

}

int solution(vi adj[], int a, int b, int n, vi &color)
{
    // if a == b, then the we apply dfs and return the number of steps to cover whole graph

    if (a == b) {
        int ans = dfs(adj, a, color, 0);
        return ans;
    }

    // if a != b, then we find the shortest path from a to b, if the path is even, then it implies they meet at the same point and we return the number of steps to cover the whole graph from that point
    else {
        auto shortestPath = BFSShortestPath(adj, a, b, n);
        if (shortestPath.second != -1) {
            vi path = shortestPath.first;
            if (shortestPath.second % 2 == 0) {
                // if the path is even, then it means they meet at the same point, so we return the number of steps to cover the whole graph from that point
                // we find the meeting point by taking the middle element of the path (since the path is even, the meeting point will be the middle element of the path
                int meetingPoint = path[path.size() / 2];
                int ans = dfs(adj, meetingPoint, color, 0);
                return ans;
            } else {
                // if the path is odd, then it means they don't meet, so we just need to find the first node they overlap at
                int i = 0, j = path.size() - 1;
                int ans = 0;
                int meetingPoint = -1;
                while (i != j) {
                    if (color[path[i]] == 0) {
                        color[path[i]] = 1;
                        i++;
                    } if (color[path[j]] == 0) {
                        j--;
                    } if (color[path[j]] == 1) {
                        color[path[j]] = 2;
                        meetingPoint = path[j];
                        break;
                    } ans++;
                }
                ans += dfs(adj, meetingPoint, color, 0);
                return ans;
            }
        } else {
            return -1;
        }
    }

}

void testCase()
{
    // write your code here
    int n;
    cin >> n;
    int a, b;
    cin >> a >> b;
    vi adj[n + 1];
    forloop(i, 1, n)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    vi color(n + 1, 0);
    color[0] = 1;
    color[a] = 1;
    color[b] = 2;
    
    int ans = solution(adj, a, b, n, color);
    print(ans);

}

int main()
{
    fastio;
    int t;
    cin >> t;
    while (t--)
    {
        testCase();
    }
    return 0;
}