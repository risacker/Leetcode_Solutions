class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();  
        int row[] = {1, -1, 0, 0, 1, -1, 1, -1};
        int col[] = {0, 0, 1, -1, 1, 1, -1, -1};  
        if(grid[0][0] == 1) 
            return -1;
        if(grid[n-1][n-1] == 1) 
            return -1;
        queue<pair<pair<int, int>, int>> q;
        q.push({{0, 0}, 1}); 
        grid[0][0] = 1; 
        while(!q.empty()){
            int x = q.front().first.first;
            int y = q.front().first.second;
            int d = q.front().second;     
            if(x == n - 1 && y == n - 1)
                return d; 
            for(int i = 0; i < 8; i++){
                int r = x + row[i];
                int c = y + col[i];
                if(r >= 0 && r < n && c >= 0 && c < n && grid[r][c] == 0){
                    grid[r][c] = 1;
                    q.push({{r, c}, d + 1});
                }
            } 
            q.pop();
        } 
        return -1;
    }
};