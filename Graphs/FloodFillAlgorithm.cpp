//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<vector<bool>> visited;
        int n;
        int m;

        void bfs(vector<vector<int>>& image, int row, int col, int oldColor, int newColor) {
            queue<pair<int, int>> q;
            q.push({row, col});
            visited[row][col] = true;
            image[row][col] = newColor;
            
            while (!q.empty()) {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                for (int i = 0; i < 4; ++i) {
                    int newRow = row + directions[i][0];
                    int newCol = col + directions[i][1];
                    if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && image[newRow][newCol] == oldColor && !visited[newRow][newCol]) {
                        q.push({newRow, newCol});
                        visited[newRow][newCol] = true;
                        image[newRow][newCol] = newColor;
                    }
                }
            }
        }

    public:
        vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
            // Code here 
            n = image.size();
            m = image[0].size();
            visited = vector<vector<bool>>(n, vector<bool>(m, false));
            int oldColor = image[sr][sc];
            bfs(image, sr, sc, oldColor, newColor);
        }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends