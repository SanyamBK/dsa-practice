#include <bits/stdc++.h>
using namespace std;

template<typename T> class DisjointSet {
public:
    vector<T> parent, size;
    
    DisjointSet(int n) {
        parent.resize(n+1);
        size.resize(n+1, 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }
    
    int findParent(int x) {
        if (x != parent[x]) 
            parent[x] = findParent(parent[x]);
        return parent[x];
    }
    
    void unionBySize(int a, int b) {
        int rootA = findParent(a);
        int rootB = findParent(b);
        if (rootA == rootB) return;
        
        if (size[rootA] < size[rootB]) {
            swap(rootA, rootB);
        }
        parent[rootB] = rootA;
        size[rootA] += size[rootB];
    }
};

class Solution {
  public:
    int countMinEdgesRemoved(int n, vector<vector<int>> &edges, int k) {
        DisjointSet<int> dsu(n);
        vector<pair<int,int>> cyclicEdges;
        
        for (auto &it: edges) {
            int u = it[0], v = it[1];
            if (dsu.findParent(u) == dsu.findParent(v)) {
                cyclicEdges.push_back({u, v});  
            } 
            dsu.unionBySize(u, v);
        }
        
        int components = 0;
        for (int i = 1; i <= n; i++) {
            if (dsu.findParent(i) == i) {
                components++;
            }
        }
        
        int moreReq = k - components;
        if (moreReq < 0) return -1;
        
        vector<bool> hasCycle(n+1, false);
        for (size_t i = 0; i < cyclicEdges.size(); i++) {
            int u = cyclicEdges[i].first;
            hasCycle[dsu.findParent(u)] = true;
        }
        
        int a = 0;
        for (auto &edge: edges) {
            int u = edge[0];
            if (!hasCycle[dsu.findParent(u)]) a++;
        }
        
        if (a >= moreReq) return moreReq;
        
        int cyclicMoreRemoval = moreReq - a; // unused, but left here to keep your structure
        
        vector<int> countEdgesResponsibleForCycles(n+1, 0);
        vector<int> edgesPerComponent(n+1, 0);
        for (auto &it : edges) {
            int u = it[0];
            edgesPerComponent[dsu.findParent(u)]++;
            countEdgesResponsibleForCycles[dsu.findParent(u)]++;
        }
        
        vector<pair<int, int>> cycleRemovedParentWise;
        for (int i = 1; i <= n; i++) {
            if (hasCycle[i]) {
                cycleRemovedParentWise.push_back(
                    {countEdgesResponsibleForCycles[dsu.findParent(i)], dsu.findParent(i)}
                );
            }
        }
        
        sort(cycleRemovedParentWise.begin(), cycleRemovedParentWise.end());
        
        int ans = a;
        int left = moreReq - a;
        
        for (size_t i = 0; i < cycleRemovedParentWise.size(); i++) {
            int removals = cycleRemovedParentWise[i].first;
            int parent = cycleRemovedParentWise[i].second;
            
            int edgesInthatComponent = edgesPerComponent[parent];
            ans += removals;
            edgesInthatComponent -= removals;
            ans += min(edgesInthatComponent, left);
            left -= edgesInthatComponent;
            if (left <= 0) break;
        }
        return ans;
    }
};

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> edges(m, vector<int>(2));
    for (int i = 0; i < m; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }
    
    Solution sol;
    int ans = sol.countMinEdgesRemoved(n, edges, k);
    cout << ans << "\n";
    return 0;
}
