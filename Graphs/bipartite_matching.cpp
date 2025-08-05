// bipartite matching
#include <bits/stdc++.h>
using namespace std;

class BipartiteMatching
{
public:
    int n, m = 0;
    vector<vector<int>> adj;
    vector<int> match;
    vector<bool> visited;

    BipartiteMatching(int n, int m)
    {
        this->n = n;
        this->m = m;
        this->adj = vector<vector<int>>(n);
        this->match = vector<int>(m, -1);
        this->visited = vector<bool>(n);
    }

    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
    }

    bool dfs(int u)
    {
        if (visited[u])
            return false;
        visited[u] = true;
        for (int v : adj[u])
        {
            if (match[v] == -1 || dfs(match[v]))
            {
                match[v] = u;
                return true;
            }
        }
        return false;
    }

    int maximumMatching()
    {
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            fill(visited.begin(), visited.end(), false);
            if (dfs(i))
                ans++;
        }
        return ans;
    }
};

int main()
{
    BipartiteMatching bm(3, 3);
    bm.addEdge(0, 0);
    bm.addEdge(0, 1);
    bm.addEdge(1, 1);
    bm.addEdge(1, 2);
    bm.addEdge(2, 2);
    cout << bm.maximumMatching() << endl; // 3
    return 0;
}