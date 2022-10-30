class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        if(n == 0)
            return 0;
        int cols = grid[0].size();
        int min_distance = n+cols-2;
        if(n+cols-3 <= k)
            return min_distance;
        int min_distance_next_level = min_distance; 
        queue<vector<int>>q;
        q.push({0,0,k});     
        vector<vector<int>> visited(n,vector<int>(cols,-1));
        int dist = 0;
        visited[0][0] = k;
        vector<vector<int>> dirs = {{1,0},{0,1},{-1,0},{0,-1}};
        while(!q.empty()){
            int qsize = q.size();
            min_distance = min_distance_next_level;
            while(qsize--){
                vector<int> v = q.front();
                q.pop();
                for(auto d : dirs){
                    int x = v[0]+d[0];
                    int y = v[1]+d[1];
                    int curr_k = v[2];
                    if(x < 0 || y < 0 || x >= n || y >= cols || curr_k < 0 || visited[x][y] >= curr_k)
                        continue;
                    curr_k -= grid[x][y];
                    int distance_from_curr = n+cols-2-x-y;
                    if(n+cols-3-x-y <= curr_k && distance_from_curr == min_distance-1)
                        return distance_from_curr+dist+1;
                    visited[x][y] = curr_k;   
                    q.push({x,y,curr_k});
                    min_distance_next_level = min(min_distance_next_level,distance_from_curr);
                }
            }
            dist++;
        }  
        return -1;
    }
};