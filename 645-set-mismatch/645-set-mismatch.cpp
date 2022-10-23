class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        bool seen[n + 1];
        vector<int> ans(2);
        for(int i = 1; i <= n; i++) 
            seen[i] = false;
        for(int i: nums) 
            seen[i] = (!seen[i] || bool(1 + (ans[0] = i)));
        for(int i = 1; i <= n; i++) 
            if (!seen[i]) 
                return ans[1] = i, ans;
        return ans;
    }
};