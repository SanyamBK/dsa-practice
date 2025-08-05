#include <bits/stdc++.h>
using namespace std;

#define N 9

bool findEmptyLocation(int grid[N][N], int &row, int &col) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j] == 0) {
                row = i;
                col = j;
                return true;
            }
        }
    }
    return false;
}

bool isSafe(int grid[N][N], int row, int col, int num)  {
    for (int i = 0; i < N; i++) {  // is safe in row
        if (grid[row][i] == num) {
            return false;
        }
    }

    for (int i = 0; i < N; i++) {  // is safe in col
        if (grid[i][col] == num) {
            return false;
        }
    }

    int rowFactor = row - (row%3);  // is safe in grid
    int colFactor = col - (col%3);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i+rowFactor][j+colFactor] == num) {
                return false;
            }
        }
    }

    return true;
}

bool solveSudoku(int grid[N][N]) {
    int row, col;
    if (!findEmptyLocation(grid, row, col)) {
        return true;
    }

    for (int i = 1; i <= 9; i++) {
        if (isSafe(grid, row, col, i)) {
            if (solveSudoku(grid)) {
                return true;
            }
            grid[row][col] = 0;
        }
    }

    return false;
}

int main() {
    int grid[N][N];
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < s.length(); j++) {
            grid[i][j] = s[j] - '0';
        }
    }

    solveSudoku(grid);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << grid[i][j];
        }
        cout << endl;
    }
    return 0;
}