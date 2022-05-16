// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find unit area of the largest region of 1s.
     int checkForNeighbors(vector<vector<int>> &grid, vector<vector<bool>> &visited, int i, int j, int rows, int cols){
        if(i < 0 || i >= rows || j < 0 || j>= cols){
            return 0;
        }
        if(visited[i][j] == true || grid[i][j] == 0){
            return 0;
        }
        visited[i][j] = true;
        return 1 + checkForNeighbors(grid, visited, i - 1, j , rows, cols) + checkForNeighbors(grid, visited, i, j - 1, rows, cols) + checkForNeighbors(grid, visited, i + 1, j, rows, cols) + checkForNeighbors(grid, visited, i , j + 1 , rows, cols) + checkForNeighbors(grid, visited, i - 1, j - 1, rows, cols) + checkForNeighbors(grid, visited, i + 1, j + 1, rows, cols) + checkForNeighbors(grid, visited, i - 1, j + 1, rows, cols) + checkForNeighbors(grid, visited, i + 1, j - 1, rows, cols);
    }
    
    
    
    //Function to find unit area of the largest region of 1s.
    int findMaxArea(vector<vector<int>>& grid) {
       int rows = grid.size();
       int cols = grid[0].size();
       vector<vector<bool>> visited;
       for(int i = 0; i < rows; i++){
           vector<bool> v (cols, false);
           visited.push_back(v);
       }
       int ans = INT_MIN;
       for(int i = 0; i < rows; i++){
           for(int j = 0; j < cols; j++){
               if(visited[i][j] == false && grid[i][j] == 1){
                   ans = std::max(ans, checkForNeighbors(grid, visited, i, j, rows, cols));
               }
           }
       }
       return ans;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends