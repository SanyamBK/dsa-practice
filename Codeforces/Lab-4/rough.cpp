#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define pii pair<int, int>
#define pb push_back
#define forloop(i, a, b) for (auto i = a; i < b; i++)
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

vector<int> lnk, sz;

void dsu_init(int n) {
    lnk.resize(n + 1);
    sz.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        lnk[i] = i;
        sz[i] = 1;
    }
}

int find(int x) {
    if (lnk[x] == x) return x;
    return lnk[x] = find(lnk[x]);
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) {
        if (sz[a] < sz[b]) swap(a, b);
        lnk[b] = a;
        sz[a] += sz[b];
    }
}

void testCase() {
    int n;
    cin >> n;
    
    vector<pii> edges(n - 1);
    forloop(i, 0, n - 1) {
        int a, b;
        cin >> a >> b;
        edges[i] = {a, b};
    }
    
    dsu_init(n);
    for (auto &[a, b] : edges) {
        unite(a, b);
    }
    
    vector<pii> operations;
    vector<int> degree(n + 1, 0);
    vector<vector<int>> adj(n + 1);
    
    for (auto &[a, b] : edges) {
        degree[a]++;
        degree[b]++;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    
    queue<int> leaves;
    for (int i = 1; i <= n; i++) {
        if (degree[i] == 1) leaves.push(i);
    }
    
    while (leaves.size() > 1) {
        int leaf = leaves.front();
        leaves.pop();
        
        int parent = -1;
        for (int neigh : adj[leaf]) {
            if (degree[neigh] > 0) {
                parent = neigh;
                break;
            }
        }
        
        degree[leaf]--;
        degree[parent]--;
        
        adj[leaf].clear();
        
        int new_leaf = leaves.front();
        leaves.pop();
        
        operations.pb({leaf, parent, leaf, new_leaf});
        
        degree[leaf]++;
        degree[new_leaf]++;
        adj[leaf].pb(new_leaf);
        adj[new_leaf].pb(leaf);
        
        if (degree[parent] == 1) leaves.push(parent);
        if (degree[new_leaf] == 1) leaves.push(new_leaf);
    }
    
    cout << operations.size() << endl;
    for (auto &[i, j, u, v] : operations) {
        cout << i << " " << j << " " << u << " " << v << endl;
    }
}

int main() {
    fastio;
    int t = 1;
    // cin >> t;
    while (t--) {
        testCase();
    }
    return 0;
}
