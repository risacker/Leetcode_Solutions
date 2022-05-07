class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<int> q;
        int fresh = 0;
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(grid[i][j] == 2) 
                    q.push(i*100 + j);
                else if(grid[i][j] == 1)
                    fresh++;
            }   
        } 
        int time = 0;
        vector<int> dir = {-1,0,1,0,-1};
        while(q.size() && fresh){
            int size = q.size();
            time++;
            while(size--){
                int index = q.front();
                q.pop();
                int x = index/100, y = index%100;
                for(int k = 0;k < 4;k++){
                    int i = x + dir[k], j = y + dir[k+1];
                    if(i < 0 || j < 0 || i == m || j == n || grid[i][j] != 1) 
                        continue;
                    grid[i][j] = 2;
                    q.push(i*100 + j);
                    fresh--;
                }
            }
        }
        if(fresh) return -1;
        return time;
    }
};