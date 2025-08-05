#include <bits/stdc++.h>
using namespace std;


void function(int **matrix, bool *placed, int n, unordered_map<int, int> M, set<int> S) {

    int dir1[] = {0, 1, 0, -1};
    int dir2[] = {-1, 0, 1, 0};

    int c = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!placed[c] && matrix[i][j] == 0) {
                matrix[i][j] = c;
                for (int k = 0; )
            }
        }
    }
    

}

int main() {
    int n;
    cin >> n;

    vector<int> A(n);
    unordered_map<int, int> M;
    set<int> S;
    bool *placed = new bool[n]();


    int **matrix = new int*[n];
    for (int i = 0; i < n; i++)
        matrix[i] = new int[n]();

    for (int i = 0; i < n*n; i++) {
        A.push_back(i);
        M[i]++;
    }

    int c = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = A[c];
        }
    }

}