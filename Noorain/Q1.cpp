#include <iostream>
#include <vector>

using namespace std;

void escapeMazeHelper(int maze[][20], int n, int x, int y, vector<vector<bool>>& visited, bool& escape) {

    if (x == n - 1 && y == n - 1) {
        escape = true;
        return;
    }


    visited[x][y] = true;

    if (x > 0 && maze[x - 1][y] == 0 && !visited[x - 1][y]) { 
        escapeMazeHelper(maze, n, x - 1, y, visited, escape);
    }
    if (x < n - 1 && maze[x + 1][y] == 0 && !visited[x + 1][y]) { 
        escapeMazeHelper(maze, n, x + 1, y, visited, escape);
    }
    if (y > 0 && maze[x][y - 1] == 0 && !visited[x][y - 1]) { 
        escapeMazeHelper(maze, n, x, y - 1, visited, escape);
    }
    if (y < n - 1 && maze[x][y + 1] == 0 && !visited[x][y + 1]) { 
        escapeMazeHelper(maze, n, x, y + 1, visited, escape);
    }

    visited[x][y] = false;
}

bool canEscapeMaze(int maze[][20], int n) {
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    bool escape = false; 
    escapeMazeHelper(maze, n, 0, 0, visited, escape);
    return escape;
}

int main() {
    int n;
    cin >> n;

    int maze[20][20];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> maze[i][j];
        }
    }

    cout << (canEscapeMaze(maze, n) ? "true" : "false") << endl;

    return 0;
}
