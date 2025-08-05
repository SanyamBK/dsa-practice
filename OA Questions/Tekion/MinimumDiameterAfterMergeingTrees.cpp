#include <bits/stdc++.h>
using namespace std;

pair<int, int> dfs(vector<vector<int>> &adj, int node, int parent) {
    pair<int, int> res = {0, node}; // {depth, node}
    for (int adjNode : adj[node]) {
        if (adjNode != parent) {
            pair<int, int> temp = dfs(adj, adjNode, node);
            temp.first++;
            if (temp.first > res.first) {
                res = temp;
            }
        }
    }
    return res;

} 

int getDiameter(vector<vector<int>>& adj, int n) {
    pair<int, int> farthest = dfs(adj, 1, 0);
    pair<int, int> res = dfs(adj, farthest.second, 0);
    return res.first;
}

int findShortestDiameter(int networkA_nodes, vector<int> networkA_from, vector<int> networkA_to, 
            int networkB_nodes, vector<int> networkB_from, vector<int> networkB_to) {
        
        vector<vector<int>> networkA(networkA_nodes+1);
        for (int i = 0; i < networkA_nodes - 1; i++) {
            networkA[networkA_from[i]].push_back(networkA_to[i]);
            networkA[networkA_to[i]].push_back(networkA_from[i]);

        }
        vector<vector<int>> networkB(networkB_nodes+1);
        for (int i = 0; i < networkB_nodes - 1; i++) {
            networkB[networkB_from[i]].push_back(networkB_to[i]);
            networkB[networkB_to[i]].push_back(networkB_from[i]);
        }
        
        int diamA = getDiameter(networkA, networkA_nodes);
        int diamB = getDiameter(networkB, networkB_nodes);

        int newDiam = 1 + ceil(diamA/2) + ceil(diamB/2);

        return max(newDiam, max(diamA, diamB));

    }

int main() {
    
    int networkA_nodes = 3, networkB_nodes = 3;
    vector<int> networkA_from = {1, 1}, networkA_to = {2, 3};
    vector<int> networkB_from = {1, 2}, networkB_to = {2, 3};

    cout << findShortestDiameter(networkA_nodes, networkA_from, networkA_to, networkB_nodes, networkB_from, networkB_to) << endl;
    return 0;
}