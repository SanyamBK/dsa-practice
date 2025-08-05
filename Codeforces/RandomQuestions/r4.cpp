#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits>

using namespace std;

struct Cell {
    int x, y, dist;
};

int directions[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int bfs(int w, int h, vector<pair<int, int>>& buildings) {
    vector<vector<int>> dist(h, vector<int>(w, numeric_limits<int>::max()));
    queue<Cell> q;
    
    for (const auto& building : buildings) {
        q.push({building.first, building.second, 0});
        dist[building.second][building.first] = 0;
    }
    
    int maxDist = 0;
    
    while (!q.empty()) {
        Cell current = q.front();
        q.pop();
        
        for (int i = 0; i < 4; ++i) {
            int newX = current.x + directions[i][0];
            int newY = current.y + directions[i][1];
            
            if (newX >= 0 && newX < w && newY >= 0 && newY < h && dist[newY][newX] == numeric_limits<int>::max()) {
                dist[newY][newX] = current.dist + 1;
                maxDist = max(maxDist, dist[newY][newX]);
                q.push({newX, newY, current.dist + 1});
            }
        }
    }
    
    return maxDist;
}

int findMinDistance(int w, int h, int n) {
    vector<pair<int, int>> cells;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cells.push_back({j, i});
        }
    }
    
    int minDist = numeric_limits<int>::max();
    
    vector<bool> combination(cells.size());
    fill(combination.end() - n, combination.end(), true);
    
    do {
        vector<pair<int, int>> buildings;
        for (int i = 0; i < cells.size(); ++i) {
            if (combination[i]) {
                buildings.push_back(cells[i]);
            }
        }
        
        int currentDist = bfs(w, h, buildings);
        minDist = min(minDist, currentDist);
        
    } while (next_permutation(combination.begin(), combination.end()));
    
    return minDist;
}

int main() {
    cout << findMinDistance(4, 4, 3) << endl; // Example output: 2
    cout << findMinDistance(5, 1, 1) << endl; // Example output: 2
    return 0;
}
