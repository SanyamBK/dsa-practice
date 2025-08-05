#include <bits/stdc++.h>
using namespace std;

bool hasPathDFS(int **edges, int n, int sv, int ev, bool *visited, vector<int> &path) {
    if (sv == ev) {
        path.push_back(sv);
        return true;
    }
    visited[sv] = true;
    for (int i = 0; i < n; i++) {
        if (i == sv) {
            continue;
        }
        if (edges[sv][i] == 1 && !visited[i]) {
            if (hasPathDFS(edges, n, i, ev, visited, path)) {
                path.push_back(sv);
                return true;
            }
        }
    }
    return false;
}


void GetPathDFS(int ** edges, int n, int sv, int ev) {
    bool *visited = new bool[n]();
    vector<int> path;
    if (hasPathDFS(edges, n, sv, ev, visited, path)) {
        for (int i = path.size() - 1; i >= 0 ; i--) {
            cout << path[i] << " ";
        }
    }
     
    delete [] visited;
}



int main() {
    int n;
    int e;
    cin >> n >> e;
    int **edges = new int*[n];
    for (int i = 0; i < n; i++) {
        edges[i] = new int[n]();
    }
    
    for (int i = 0; i < e; i++) {
        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    int sv, ev;
    cin >> sv >> ev;
    GetPathDFS(edges, n, sv, ev);


    for (int i = 0; i < n; i++) {
        delete [] edges[i];
    }
    delete [] edges;
}
