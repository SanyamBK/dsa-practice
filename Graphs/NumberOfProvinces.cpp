//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class SolutionDfs {
public:
    void dfs(vector<vector<int>>& adj, vector<bool>& visited, int v) {
        visited[v] = true;
        for (int i = 0; i < adj.size(); ++i) {
            if (adj[v][i] == 1 && !visited[i]) {
                dfs(adj, visited, i);
            }
        }
    }

    int numProvinces(vector<vector<int>>& adj, int V) {
        int provinces = 0;
        vector<bool> visited(V, false);

        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                dfs(adj, visited, i);
                provinces++;
            }
        }

        return provinces;
    }
};

class SolutionBfs {
public:
    int numProvinces(vector<vector<int>>& adj, int V) {
        int provinces = 0;
        vector<bool> visited(V, false);

        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                bfs(adj, visited, i);
                provinces++;
            }
        }

        return provinces;
    }

    void bfs(vector<vector<int>>& adj, vector<bool>& visited, int start) {
        queue<int> q;
        q.push(start);
        visited[start] = true;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v = 0; v < adj.size(); ++v) {
                if (adj[u][v] == 1 && !visited[v]) {
                    q.push(v);
                    visited[v] = true;
                }
            }
        }
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        SolutionBfs ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends