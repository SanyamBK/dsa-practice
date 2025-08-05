#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

int main() {
    int n, m, l;
    cin >> n >> m >> l;

    vector<vector<int>> adj(n + 1); 
    vector<set<int>> neighbors(n + 1);

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        neighbors[a].insert(b);
        neighbors[b].insert(a);
    }

    vector<int> cnt(n + 1, 0);
    for (int a = 1; a <= n; ++a) {
        for (int b : adj[a]) {
            if (b > a) { 
                for (int c : adj[b]) {
                    if (c > b && neighbors[a].count(c)) {
                        cnt[a]++,cnt[b]++,cnt[c]++;
                    }
                }
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (cnt[i] < l) {
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}