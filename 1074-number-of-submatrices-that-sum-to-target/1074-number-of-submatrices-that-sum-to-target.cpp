class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        int ans = 0;
        for(int r = 0; r < row; r++){
            vector<int> arr(col, 0);
            for(int i = r; i < row; i++){
                for(int j = 0; j < col; j++)
                    arr[j] += matrix[i][j];
                unordered_map<int,int> mp;
                int sum = 0;
                for(int k = 0; k < col; k++){
                    sum += arr[k];
                    if(sum == target)
                        ans += 1;
                    if(mp.find(sum-target) != mp.end())
                        ans += mp[sum-target];
                    mp[sum] += 1;
                }
            }
        }
        return ans;
    }
};