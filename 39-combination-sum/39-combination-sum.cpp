class Solution {
public:
    vector<vector<int>>ans;
    void solve(int idx,vector<int>& candidates, int target, vector<int>&res){
        if(target == 0){
            ans.push_back(res);
            return;
        }
        if(idx < 0) 
            return;
        if(target >= candidates[idx]){
            res.push_back(candidates[idx]);
            solve(idx, candidates, target-candidates[idx], res);
            res.pop_back();
        }
        solve(idx-1, candidates, target, res);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        ans.clear();
        vector<int> res;
        solve(n-1, candidates, target, res);
        return ans;
    }
};