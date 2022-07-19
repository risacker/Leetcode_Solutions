class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        // logic: search from top right corner as it is given rows & cols are sorted
       // TC will be O(n+m) for binary search and for brute force it will be O(n^2)
      // refrence: aditya verma's question on yt(Search in Row wise And Column wise Sorted Array)
        int n = grid.size();
        int m = grid[0].size();
        int i = 0;
        int j = m - 1;
        int cnt = 0;
        while(j >= 0 && i < n){
            if(grid[i][j] < 0){
                cnt += (n-i);
                j--;
            }
            else
                i++;
        }
        return cnt;
    }
};