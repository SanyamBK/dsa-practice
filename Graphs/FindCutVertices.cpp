#include <bits/stdc++.h>
using namespace std;


vector<int> findCutVertices(vector<vector<int>> adj, int V, int s, int t, int outdegree[]) {
    //toposort 
    int indegree[V + 1] = {0}; 
    for (int i = 1; i <= V; i++) { 
        for (auto it : adj[i]) {
            indegree[it]++;
        }
    }

    queue<int> q;
    q.push(s);
    vector<int> topoInd(V+1,-1);
    vector<int> topo;
    int ind=1;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        topo.push_back(node);
        topoInd[node]=ind;
        ind++;
        for (auto it : adj[node]) {
            indegree[it]--;
            if (indegree[it] == 0) q.push(it);
        }
    }   

    //misc
    // for(int i=0;i<topo.size();i++){
    //     cout<<topo[i]<<" ";
    // }
    // cout<<"\n";

    // for(int i=0;i<topoInd.size();i++){
    //     if(topoInd[i]!=-1){
    //         cout<<i<<" "<<topoInd[i]<<"\n";
    //     }
    // }
    // cout<<"\n";

    // finding Cut Vertice
    vector<int> cutVertices;
    int maxInd=-1;
    int targetFound=0;
    for(int i=0;i<topo.size();i++){
        // cout<<"newVertex "<<topo[i]<<"\n";
        // cout<<maxInd<<"\n";
        if(maxInd!=-1 && topoInd[topo[i]]>=maxInd){
            cutVertices.push_back(topo[i]);
        }
        for(auto v : adj[topo[i]]){
            if(topoInd[v]>maxInd) {
                // cout<<v<<"\n";
                maxInd=topoInd[v];
                // cout<<maxInd<<"\n";
                if(v==t){
                    targetFound=1;
                }
            }
        }   
        if(targetFound){
            break;
        }
    }
    return cutVertices;
}

void removeOtherSources(vector<vector<int>> &adj,int v,int indegree[],int s){
    queue<int> q;
    for(int i=1;i<=v;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int curr=q.front();
        q.pop();
        if(curr==s) continue;
        for(auto v : adj[curr]){
            indegree[v]--;
            if(indegree[v]==0){
                q.push(v);
            }
        }
        adj[curr].clear();
    }
    // for(int i=0;i<v+1;i++){
    //     cout<<indegree[i]<<" ";
    // }
    // cout<<"\n";
}

void removeOtherSinks(vector<vector<int>> &adj,vector<vector<int>> invAdj, int v, int outdegree[], int t) {
    queue<int> q;
    // vector<vector<int>> inverse_adj(v + 1, vector<int>());

    // Construct inverse adjacency list
    // for (int i = 1; i <= v; ++i) {
    //     for (int j : adj[i]) {
    //         inverse_adj[j].push_back(i);
    //     }
    // }

    for (int i = 1; i <= v; ++i) {
        if (outdegree[i] == 0 && i != t) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        if(curr==t) continue;
        for (int incoming : invAdj[curr]) {
            auto it = find(adj[incoming].begin(), adj[incoming].end(), curr);
            if (it != adj[incoming].end()) {
                adj[incoming].erase(it);
                outdegree[incoming]--;
                if (outdegree[incoming] == 0 && incoming != t) {
                    q.push(incoming);
                }
            }
        }
    }
    // for(int i=1;i<v+1;i++){
    //     cout<<outdegree[i]<<" ";
    // }
}



int main() {
    int v, e;
    cin >> v >> e;
    int s, t;
    cin >> s >> t;
    vector<vector<int>> adj(v+1);
    vector<vector<int>> invAdj(v+1);
    int indegree[v+1]={0};
    int outdegree[v+1]={0};
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        invAdj[v].push_back(u);
        outdegree[u]++;
        indegree[v]++;
    }

    removeOtherSources(adj,v,indegree,s);
    removeOtherSinks(adj,invAdj,v,outdegree,t);
    vector<int> cutVertices = findCutVertices(adj, v, s, t,outdegree);


    cout << "The (s, t)-cut vertices are:";
    for (int v : cutVertices) {
        cout << " " << v;
    }
    cout << endl;

    return 0;
}