#include <iostream>
#include <vector>
using namespace std;


bool dfs(vector<vector<pair<int, int>>>& graph, int sv, int ev, bool* visited, string direction) {
    if (sv == 1 && ev != 1) {
        return false;
    }
    else if (sv == ev) {
        return true;
    }

    visited[sv] = true;
    for (auto neighbor : graph[sv]) {
        int vertex = neighbor.first;
        int dir = neighbor.second;
        if (dir == 1 && direction == "towards" || dir == 0 && direction == "away") {
            if (!visited[vertex] && dfs(graph, vertex, ev, visited, direction)) {
                return true;
            }
        }
    }
    return false;
}

void canFind(vector<vector<pair<int, int>>>& graph, int sv, int ev, string direction) {
    bool* visited = new bool[graph.size()]();
    if (dfs(graph, sv, ev, visited, direction)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    delete[] visited;
}

int main() {
    int n;
    cin >> n;
    vector<vector<pair<int, int>>> graph(n + 1);

    for (int i = 0; i < n - 1; i++) {
        int f, s;
        cin >> f >> s;
        graph[f].push_back(make_pair(s, 1)); // towards
        graph[s].push_back(make_pair(f, 0)); // away
    }

    int q;
    cin >> q;
    while (q--) {
        string direction;
        int sv, ev;
        cin >> direction >> sv >> ev;
        canFind(graph, sv, ev, direction);
    }

    return 0;
}
