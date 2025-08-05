#include <bits/stdc++.h>
using namespace std;



void dfsTraversal(int node, vector<int> &dfs, vector<int> &vis, vector<int> adj[])
{
    dfs.push_back(node);
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            dfsTraversal(it, dfs, vis, adj);
        }
    }
}

vector<int> dfsofGraph(int V, vector<int> adj[])
{
    vector<int> dfs;
    vector<int> vis(V, 0);
    int start = 0;
    dfsTraversal(start, dfs, vis, adj);
    
}